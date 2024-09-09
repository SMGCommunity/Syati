#ifndef RSO_H
#define RSO_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct RSOObjectHeader RSOObjectHeader;
typedef u32 RSOHash;
typedef struct RSOObjectList RSOObjectList;
typedef struct RSOObjectLink RSOObjectLink;
typedef struct RSOObjectInfo RSOObjectInfo;
typedef struct RSOSymbolHeader RSOSymbolHeader;
typedef struct RSOSectionInfo RSOSectionInfo;
typedef struct RSOExportTable RSOExportTable;
typedef struct RSOImportTable RSOImportTable;
typedef struct RSORel RSORel;
typedef struct RSOExportFuncTable RSOExportFuncTable;

struct RSOExportFuncTable {
    const char* mSymbolName;
    u32* mSymbolPtr;
};
    
struct RSOObjectList {
    RSOObjectInfo* mHead;
    RSOObjectInfo* mTail;
};

struct RSOObjectLink {
    RSOObjectInfo* mNext;
    RSOObjectInfo* mPrev;
};

struct RSOObjectInfo {
    RSOObjectLink mLink;
    u32 mNumSections;
    u32 mSectionInfoOffset;
    u32 mNameOffset;
    u32 mNameSize;
    u32 mVersion;
};

struct RSOSymbolHeader {
    u32 mTableOffset;
    u32 mTableSize;
    u32 mStringOffset;
};

struct RSOObjectHeader {
    RSOObjectInfo mInfo;
    u32 mBssSize;
    u8 mPrologSection;
    u8 mEpilogSection;
    u8 mUnresolvedSection;
    u8 mBssSection;
    u32 mProlog;
    u32 mEpilog;
    u32 mUnresolved;
    u32 mInternalRelOffset;
    u32 mInternalRelSize;
    u32 mExternalRelOffset;
    u32 mExternalRelSize;
    RSOSymbolHeader mExpHeader;
    RSOSymbolHeader mImpHeader;
};

struct RSOSectionInfo {
    u32 mOffset;
    u32 mSize;
};

BOOL RSOListInit(void *);
BOOL RSOLinkList(void *, void *);

BOOL RSOIsImportSymbolResolvedAll(const RSOObjectHeader *);

int RSOGetJumpCodeSize(const RSOObjectHeader *);
int RSOGetJumpCodeSize(const RSOObjectHeader *);
void RSOMakeJumpCode(const RSOObjectHeader *, void *);

const void* RSOFindExportSymbolAddr(const RSOObjectHeader *, const char *);

#ifdef __cplusplus
}
#endif

#endif // RSO_H