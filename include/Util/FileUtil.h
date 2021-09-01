#pragma once

#include "JSystem/JKernel/JKRDvdRipper.h"

class JKRHeap;
class JKRArchive;

namespace MR
{
    bool isFileExist(const char *, bool);

    // int should be JKRDvdRipper::EAllocDirection but whatever
    JKRArchive* loadToMainRAM(const char *, u8 *, JKRHeap *, int);
    JKRArchive* mountArchive(const char *, JKRHeap *, bool);

    void* recieveFile(const char *);
    JKRArchive* mountAsyncArchive(const char *);
};