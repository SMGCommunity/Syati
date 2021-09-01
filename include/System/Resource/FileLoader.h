#pragma once

#include "syati.h"
#include "System/Resource/ArchiveHolder.h"

class JKRArchive;
class JKRHeap;

class FileHolder
{
public:
    bool isExist(const char *) const;
};

class FileLoader
{
public:
    JKRArchive* receiveArchive(const char *);

    void getMountedArchiveAndHeap(const char *, JKRArchive **, JKRHeap **);

    void requestMountArchive(const char *, JKRHeap *, bool);

    JKRArchive* createAndAddArchive(void *, JKRHeap *, const char *);

    u8 _0[0x24];
    FileHolder* mHolder; // _24
    ArchiveHolder* mArchiveHolder; // _28
};