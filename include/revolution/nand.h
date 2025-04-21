#ifndef __REVOLUTION_NAND_H
#define __REVOLUTION_NAND_H

#include "revolution\types.h"

#ifdef __cplusplus
extern "C" {
#endif

#define NAND_PERM_READ 0x10
#define NAND_PERM_WRITE 0x20
#define NAND_PERM_READ_WRITE (NAND_PERM_READ | NAND_PERM_WRITE)

#define NAND_MODE_READ 1
#define NAND_MODE_WRITE 2
#define NAND_MODE_RW (NAND_MODE_READ | NAND_MODE_WRITE)

struct NANDFileInfo {
    s32 fileDescriptor;
    s32 origFd;
    char origPath[64];
    char tmpPath[64];
    u8 accType;
    u8 stage;
    u8 mark;
};

typedef struct NANDCommandBlock {
    void *userData;
    void *callback;
    void *fileInfo;
    void *bytes;
    void *inodes;
    void *status;
    u32 ownerId;
    u16 groupId;
    u8  nextStage;
    u32 attr;
    u32 ownerAcc;
    u32 groupAcc;
    u32 othersAcc;
    u32 num;
    char absPath[64];
    u32 *length;
    u32 *pos;
    int state;
    void *copyBuf;
    u32 bufLength;
    u8 *type;
    u32 uniqNo;
    u32 reqBlocks;
    u32 reqInodes;
    u32 *answer;
    u32 homeBlocks;
    u32 homeInodes;
    u32 userBlocks;
    u32 userInodes;
    u32 workBlocks;
    u32 workInodes;
    const char **dir;
    BOOL simpleFlag;
} NANDCommandBlock;

typedef struct NANDStatus {
    u32 ownerId;
    u16 groupId;
    u8 attribute;
    u8 permission;
} NANDStatus;

s32 NANDOpen(const char*, NANDFileInfo*, u8);
s32 NANDGetLength(NANDFileInfo*, u32*);
s32 NANDCreate(const char*, u8, u8);
s32 NANDPrivateCreate(const char *, u8, u8);
s32 NANDDelete(const char *);
// void* must be aligned to 32 byte boundary
s32 NANDRead(NANDFileInfo*, void*, u32);
// const void* must be aligned to 32 byte boundary
s32 NANDWrite(NANDFileInfo*, const void*, u32);
s32 NANDClose(NANDFileInfo*);
s32 NANDSeek(NANDFileInfo*, s32, s32);

#ifdef __cplusplus
}
#endif

#endif