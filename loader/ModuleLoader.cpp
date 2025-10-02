#include "ModuleLoader.h"
#include "Game/Scene/SceneFunction.h"
#include "Game/Scene/SceneObjHolder.h"
#include "Game/Scene/StageDataHolder.h"
#include "Game/Util/FileUtil.h"
#include "Game/Util/ObjUtil.h"
#include "JSystem/JKernel/JKRArchive.h"

typedef void (*VoidFuncPtr)();

static RSMLoadEntry* sModulesStart;
static RSMLoadEntry* sModulesEnd;

// ********** Loading and Unloading ********** // 

RSMError ModuleLoader::load(const char *pName, bool isStatic) {
    RSMLoadEntry *pEntry = findModule(pName);
    if (pEntry) {
        pEntry->isStatic = isStatic;
        return RSM_ERR_OK;
    }

    DVDFileInfo dvdFile;
    s32 dvdEntryNo = DVDConvertPathToEntrynum(pName);

    if (dvdEntryNo < 0) {
        OSReport("ModuleLoader: %s isn't exist\n", pName);
        return RSM_ERR_NOT_FOUND;
    }

    if (!DVDFastOpen(dvdEntryNo, &dvdFile)) {
        OSReport("ModuleLoader: Opening %s failed\n", pName);
        return RSM_ERR_NOT_FOUND;
    }

    if (dvdFile.mLength < sizeof(RSMFile)) {
        OSReport("ModuleLoader: %s is too small\n", pName);
        return RSM_ERR_TOO_SMALL;
    }

    OSReport("ModuleLoader: Loading %s\n", pName);

    u8 *pBuffer = new (0x20) u8[dvdFile.mLength];
    DVDReadPrio(&dvdFile, pBuffer, dvdFile.mLength, 0, 2);
    DVDClose(&dvdFile);

    RSMFile *pModule = (RSMFile *)pBuffer;
    loadAllDeps(pModule);
    patch(pModule);
    initStatic(pModule);
    registerModule(pName, pModule, isStatic);
    callOnLoad(pModule);

    OSReport("ModuleLoader: Loaded %s successfully\n", pName);
    return RSM_ERR_OK;
}

RSMError ModuleLoader::unload(const char *pName, bool unloadDeps) {
    return unload(findModule(pName), unloadDeps);
}

RSMError ModuleLoader::unload(RSMLoadEntry *pEntry, bool unloadDeps) {
    if (!pEntry) {
        OSReport("ModuleLoader: Module %s not found\n", pEntry->name);
        return RSM_ERR_NOT_FOUND;
    }

    if (pEntry->isStatic) {
        OSReport("ModuleLoader: Cannot unload static module %s\n", pEntry->name);
        return RSM_ERR_INVALID;
    }

    RSMFile *pModule = pEntry->code;
    callOnUnload(pModule);

    if (unloadDeps) {
        unloadAllDeps(pModule);
    }

    patch(pModule);
    unregisterModule(pEntry);

    OSReport("ModuleLoader: Unloaded %s successfully\n", pEntry->name);
    return RSM_ERR_OK;
}

void ModuleLoader::loadAllDeps(RSMFile *pModule) {
    InlineDataStream stream(getDepsSection(pModule), pModule->deps.size);
    u16 depCount = stream.read<u16>();

    for (s32 i = 0; i < depCount; i++) {
        const char *pDepName = stream.read<const char *>();

        s32 ret = load(pDepName, false);
        if (ret < RSM_ERR_OK) {
            OSReport("ModuleLoader: Loading dependency '%s' failed with error code %d\n", pDepName, ret);
        }
    }
}

void ModuleLoader::unloadAllDeps(RSMFile *pModule) {
    InlineDataStream stream(getDepsSection(pModule), pModule->deps.size);
    u16 depCount = stream.read<u16>();

    for (s32 i = 0; i < depCount; i++) {
        const char *pDepName = stream.read<const char *>();

        s32 ret = unload(pDepName, true);
        if (ret < RSM_ERR_OK) {
            OSReport("ModuleLoader: Unloading dependency '%s' failed with error code %d\n", pDepName, ret);
        }
    }
}

// ********** Patching ********** // 

void ModuleLoader::patch(RSMFile *pModule) {
    InlineDataStream stream(getPatchSection(pModule), pModule->patch.size);

    while (!stream.isEnd()) {
        u32 type = *stream.dataAs<u32>();

        switch (type) {
            case rsmPatchIdNull:
                break;
            case rsmPatchIdWrite:
                patchWrite(pModule, &stream);
                break;
            case rsmPatchIdBranch:
                patchBranch(pModule, &stream);
                break;
            default:
                OSReport("ModuleLoader: Unknown command 0x%X\n", type);
                break;
        }
    }
}

void ModuleLoader::patchWrite(RSMFile *pModule, InlineDataStream *pStream) {
    rsmPatchWrite *pWritePatch = pStream->dataAs<rsmPatchWrite>();

    u32 addr = pWritePatch->addr;
    u32 oldValue = 0;
    u32 newValue = pWritePatch->val;

    #define RSM_WRITE_DATATYPE_CASE(addr, oldValue, newValue, type) \
    case rsmPatchWriteType_##type: \
        oldValue = *(type *)addr; \
        writeAsm<type>((type *)addr, newValue); \
        break;

    switch (pWritePatch->dataType) {
        RSM_WRITE_DATATYPE_CASE(addr, oldValue, newValue, u8);
        RSM_WRITE_DATATYPE_CASE(addr, oldValue, newValue, u16);
        RSM_WRITE_DATATYPE_CASE(addr, oldValue, newValue, u32);
    }

    pWritePatch->val = oldValue;
    pStream->skip(sizeof(rsmPatchWrite));
}

void ModuleLoader::patchBranch(RSMFile *pModule, InlineDataStream *pStream) {
    rsmPatchBranch *pBranchPatch = pStream->dataAs<rsmPatchBranch>();
    u32 addr = pBranchPatch->addr;
    u32 ptr = pBranchPatch->ptr;

    if (addr < 0x80000000) {
        addr += (u32)getTextSection(pModule);
    }

    if (ptr < 0x80000000) {
        s16 depEntry = pBranchPatch->depEntry;
        if (depEntry == -1) {
            ptr += (u32)getTextSection(pModule);
        }
        else {
            RSMFile *pDependency = findModule(pModule, depEntry)->code;   

            if (!pDependency) {
                OSReport("ModuleLoader: Patching dependency branch failed.\n");
                return;
            }

            ptr += (u32)getTextSection(pDependency);
        }
    }

    u32 oldValue = *(u32 *)addr;
    u32 oldPtr = addr + (oldValue & 0x3FFFFFC);
    bool oldIsCall = oldValue & 1;
    u32 newValue = 0x48000000 | ((ptr - addr) & 0x3FFFFFC) | (pBranchPatch->isCall);

    writeAsm<u32>((u32 *)ptr, newValue);
    pBranchPatch->ptr = oldPtr;
    pBranchPatch->isCall = oldIsCall;

    pStream->skip(sizeof(rsmPatchBranch));
}

template<typename T>
void ModuleLoader::writeAsm(T *addr, T value) {
    *addr = value;

    register u32 cacheAddr = (u32)addr;
    asm {
        dcbst r0, cacheAddr
		sync
		icbi r0, cacheAddr
    }
}

// ********** Static initializing and module callback calls ********** // 

void ModuleLoader::initStatic(RSMFile *pModule) {
    u8 *pFunc = getTextSection(pModule) + pModule->ctorLoc;
    u8 *pEndFunc = getTextSection(pModule) + pModule->ctorEnd;

    for (; pFunc < pEndFunc; pFunc += sizeof(VoidFuncPtr)) {
        ((VoidFuncPtr)pFunc)();
    }
}

void ModuleLoader::callOnLoad(RSMFile *pModule) {
    s32 offset = pModule->onLoadFunc;
    if (offset < 0) {
        return;
    }
    
    ((VoidFuncPtr)(getTextSection(pModule) + offset))();
}

void ModuleLoader::callOnUnload(RSMFile *pModule) {
    s32 offset = pModule->onUnloadFunc;
    if (offset < 0) {
        return;
    }
    
    ((VoidFuncPtr)(getTextSection(pModule) + offset))();
}

// ********** Module Registry ********** // 

void ModuleLoader::registerModule(const char *pName, RSMFile *pModule, bool isStatic) {
    RSMLoadEntry *pEntry = new RSMLoadEntry();
    pEntry->name = pName;
    pEntry->code = pModule;
    pEntry->isStatic = isStatic;

    if (!sModulesStart) {
        sModulesStart = pEntry;
    }
    else {
        sModulesEnd->next = pEntry;
    }
    
    pEntry->prev = sModulesEnd;
    sModulesEnd = pEntry;
}

void ModuleLoader::unregisterModule(RSMLoadEntry *pEntry) {
    RSMLoadEntry *pPrev = pEntry->prev;
    RSMLoadEntry *pNext = pEntry->next;

    if (pPrev) { pPrev->next = pNext; }
    if (pNext) { pNext->prev = pPrev; }

    delete pEntry;
}

RSMLoadEntry* ModuleLoader::findModule(const char *pName) {
    RSMLoadEntry *pCurrent = sModulesEnd; // reverse lookup because it's usually more efficient
    if (!pCurrent) {
        return NULL;
    }

    do {
        if (strcmp(pCurrent->name, pName) == 0) {
            return pCurrent;
        }
    }
    while (pCurrent = pCurrent->prev);
    return NULL;
}

RSMLoadEntry* ModuleLoader::findModule(RSMFile *pModule, s16 depEntry) {
    InlineDataStream stream(getDepsSection(pModule), pModule->deps.size);
    u16 depCount = stream.read<u16>();
    if (depEntry >= depCount) {
        return NULL;
    }

    const char **pDeps = stream.dataAs<const char *>();
    return findModule(pDeps[depEntry]);
}

// ********** Stage UseResource Loading ********** // 

void ModuleLoader::loadStageResource() {
    StageDataHolder *pHolder = (StageDataHolder *)MR::getSceneObjHolder()->getObj(SCENE_OBJ_STAGE_DATA_HOLDER);
    JKRArchive *pArc = (JKRArchive *)((u32)pHolder->_C4 + 0x10);
    if (!pArc) {
        return;
    }

    void *pRes = pArc->getResource("modules.bcsv");
    if (!pRes) {
        return;
    }

    JMapInfo info;
    info.attach(pRes);

    int resNameItemIdx = info.searchItemInfo("ResourceName");

    for (s32 i = 0; i < info.mData->mNumEntries; i++) {
        const char *pName = NULL;
        info.getValueFast(i, resNameItemIdx, &pName);

        if (!pName) {
            continue;
        }

        RSMLoadEntry *pEntry = findModule(pName);

        if (!pEntry) {
            if (load(pName, false) < RSM_ERR_OK) {
                continue;
            }

            pEntry = findModule(pName);
        }
        
        pEntry->isPreserveForNextLoad = true;
    }
}

void ModuleLoader::flushStageResource() {
    RSMLoadEntry *pCurrent = sModulesStart;
    if (!pCurrent) {
        return;
    }

    RSMLoadEntry *pNext = pCurrent->next;
    
    do {
        pNext = pCurrent->next; // Do this since pCurrent gets deleted in unload

        if (!pCurrent->isPreserveForNextLoad && !pCurrent->isStatic) {
            unload(pCurrent, false);
            continue;
        }

        pCurrent->isPreserveForNextLoad = false;
    }
    while (pCurrent = pNext);
}

// ********** Hooks ********** // 

void loadModuleStageResource() {
    SceneFunction::startActorFileLoadCommon(); // restore call
    ModuleLoader::loadStageResource();
    ModuleLoader::flushStageResource();
}

extern rsmSymbol init__9GameSceneFv;
rsmSymCall(init__9GameSceneFv, 0x158, loadModuleStageResource);

extern rsmSymbol handleException__19GameSystemExceptionFUsP9OSContextUlUl;
extern rsmSymbol __OSStopAudioSystem;

#ifdef TARGET_SMG1
rsmSymBranch(handleException__19GameSystemExceptionFUsP9OSContextUlUl, 0x114, __OSStopAudioSystem);
#else
rsmSymBranch(handleException__19GameSystemExceptionFUsP9OSContextUlUl, 0x11C, __OSStopAudioSystem);
#endif