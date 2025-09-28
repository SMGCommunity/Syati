#include "ModuleLoader.h"
#include "Game/Util/FileUtil.h"

typedef void (*VoidFuncPtr)();

static RSMLoadEntry* sModulesStart;
static RSMLoadEntry* sModulesEnd;

RSMError ModuleLoader::load(const char *pName) {
    RSMLoadEntry *pEntry = findModule(pName);
    if (pEntry) {
        if (pEntry->mode == RSM_LOAD_MODE_DEPENDENCY) {
            pEntry->mode = RSM_LOAD_MODE_NORMAL;
        }

        OSReport("ModuleLoader: %s already loaded\n", pName);
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
    registerModule(pName, pModule);
    callOnLoad(pModule);

    OSReport("ModuleLoader: Loaded %s successfully\n", pName);
    return RSM_ERR_OK;
}

RSMError ModuleLoader::unload(const char *pName, bool depOnly) {
    RSMLoadEntry *pEntry = findModule(pName);

    if (!pEntry) {
        OSReport("ModuleLoader: Module %s not found\n", pName);
        return RSM_ERR_NOT_FOUND;
    }

    if (pEntry->mode == RSM_LOAD_MODE_STATIC) {
        OSReport("ModuleLoader: Cannot unload static module %s\n", pName);
        return RSM_ERR_INVALID;
    }

    if (depOnly && pEntry->mode == RSM_LOAD_MODE_NORMAL) {
        OSReport("ModuleLoader: Cannot unload non-dependency module %s\n", pName);
        return RSM_ERR_INVALID;
    }

    RSMFile *pModule = pEntry->code;
    callOnUnload(pModule);
    unloadAllDeps(pModule);
    patch(pModule);
    unregisterModule(pEntry);

    OSReport("ModuleLoader: Unloaded %s successfully\n", pName);
    return RSM_ERR_OK;
}

void ModuleLoader::loadAllDeps(RSMFile *pModule) {
    InlineDataStream stream(getDepsSection(pModule), pModule->deps.size);
    u16 depCount = stream.read<u16>();

    for (s32 i = 0; i < depCount; i++) {
        const char *pDepName = stream.read<const char *>();

        s32 ret = load(pDepName);
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
    u32 oldPtr = addr + (oldValue & 0x3FFFFFD);

    u32 newValue = 0x48000000 | ((ptr - addr) & 0x3FFFFFD);

    writeAsm<u32>((u32 *)ptr, newValue);
    pBranchPatch->ptr = oldPtr;

    pStream->skip(sizeof(rsmPatchBranch));
}

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

void ModuleLoader::registerModule(const char *pName, RSMFile *pModule) {
    RSMLoadEntry *pEntry = new RSMLoadEntry();
    pEntry->name = pName;
    pEntry->code = pModule;

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
    RSMLoadEntry *pCurrent = sModulesStart;
    if (!pCurrent) {
        return NULL;
    }

    do {
        if (strcmp(pCurrent->name, pName) == 0) {
            return pCurrent;
        }
    }
    while (pCurrent = pCurrent->next);
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