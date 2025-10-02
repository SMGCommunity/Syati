#include "revolution.h"

typedef int RSMError;
#define RSM_ERR_OK 0
#define RSM_ERR_INVALID   -1
#define RSM_ERR_NOT_FOUND -2
#define RSM_ERR_TOO_SMALL -3

#define RSM_MAGIC 'RSM\0'

struct SectionInfo {
    u32 offset;
    u32 size;
};

struct RSMFile {
    u32 magic;
    u32 ctorLoc;
    u32 ctorEnd;
    s32 onLoadFunc;
    s32 onUnloadFunc;
    SectionInfo deps;
    SectionInfo text;
    SectionInfo patch;
};

struct RSMLoadEntry {
    const char* name;
    RSMFile* code;
    bool isStatic;
    bool isPreserveForNextLoad;
    RSMLoadEntry* prev;
    RSMLoadEntry* next;
};