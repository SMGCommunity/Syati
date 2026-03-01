#ifndef __REVOLUTION_DVD_H
#define __REVOLUTION_DVD_H

#include "revolution/types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct DVDDiskID DVDDiskID;

struct DVDDiskID {
    char gameName[4];
    char company[2];
    u8 diskNumber;
    u8 gameVersion;
    u8 streaming;
    u8 streamingBufSize;
    u8 padding[14];
    u32 rvlMagic;
    u32 gcMagic;
};

struct DVDCommandBlock {
    DVDCommandBlock* mNext;
    DVDCommandBlock* mPrev;
    u32 mCommand;
    s32 mState;
    u32 mOffset;
    u32 mLength;
    void* mAddr;
    u32 mCurTransferSize;
    u32 mTransferredSize;
    void* mId;
    void* mCallback;
    void* mUserData;
};

struct DVDFileInfo {
    DVDCommandBlock mCommandBlock;
    u32 mStartAddr;
    u32 mLength;
    void* mCallback;
};

struct DVDDir {
    u32 entryNum;
    u32 location;
    u32 next;
};

struct DVDDirEntry {
    u32 entryNum;
    BOOL isDir;
    char* name;
};

typedef void (*DVDCallback)(s32 result, DVDFileInfo* fileInfo);

bool DVDOpen(const char* fileName, DVDFileInfo* fileInfo);
bool DVDFastOpen(s32 entrynum, DVDFileInfo* fileInfo);
bool DVDClose(DVDFileInfo* fileInfo);

bool DVDOpenDir(const char *, DVDDir *);
bool DVDReadDir(DVDDir *, DVDDirEntry *);
bool DVDCloseDir(DVDDir *);

s32 DVDCancel(DVDCommandBlock *);
BOOL DVDReadAsyncPrio(DVDFileInfo *, void *, s32, s32, DVDCallback, s32);

s32 DVDReadPrio(DVDFileInfo* fileInfo, void* addr, s32 length, s32 offset, s32 prio);
s32 DVDConvertPathToEntrynum(const char* pathPtr);

#ifdef __cplusplus
}
#endif

#endif // __REVOLUTION_DVD_H
