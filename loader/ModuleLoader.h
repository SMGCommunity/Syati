#pragma once

#include "revolution.h"
#include "rsm/file.h"
#include "rsm/hooks.h"
#include "rsm/inline.h"

class ModuleLoader {
public:
    static RSMError load(const char *pName, bool isStatic);
    static RSMError unload(const char *pName, bool unloadDeps);
    static RSMError unload(RSMLoadEntry *pEntry, bool unloadDeps);

    static void loadAllDeps(RSMFile *pModule);
    static void unloadAllDeps(RSMFile *pModule);
    
    static void patch(RSMFile *pModule);
    static void patchWrite(RSMFile *pModule, InlineDataStream *pStream);
    static void patchBranch(RSMFile *pModule, InlineDataStream *pStream);

    template<typename T>
    static void writeAsm(T *addr, T value);

    static void initStatic(RSMFile *pModule);
    static void callOnLoad(RSMFile *pModule);
    static void callOnUnload(RSMFile *pModule);

    static inline u8* getDepsSection(RSMFile *pModule) {
        return (u8 *)pModule + pModule->deps.offset;
    }

    static inline u8* getTextSection(RSMFile *pModule) {
        return (u8 *)pModule + pModule->text.offset;
    }

    static inline u8* getPatchSection(RSMFile *pModule) {
        return (u8 *)pModule + pModule->patch.offset;
    }    

    static void registerModule(const char *pName, RSMFile *pModule, bool isStatic);
    static void unregisterModule(RSMLoadEntry *pEntry);
    static RSMLoadEntry* findModule(const char *pName);
    static RSMLoadEntry* findModule(RSMFile *pModule, s16 depEntry);

    static void loadStageResource();
    static void flushStageResource();
};