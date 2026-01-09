#pragma once

#include "revolution.h"
#include "JSystem.h"

namespace MR {
    bool isFileExist(const char *, bool);
    u32 getFileSize(const char*, bool);
    // Unknown function here
    bool makeObjectArchiveFileName(char* outFullPathBuffer, u32 bufferLength, const char* objectName); // returns true/false based on if the object archive exists or not

    // int should be JKRDvdRipper::EAllocDirection but whatever
    JKRArchive* loadToMainRAM(const char *, u8 *, JKRHeap *, int);
    JKRArchive* mountArchive(const char *, JKRHeap *, bool);

    void* receiveFile(const char *);
    JKRArchive* mountAsyncArchive(const char *);
};
