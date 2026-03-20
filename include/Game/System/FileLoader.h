#pragma once

#include "revolution.h"
#include "JSystem.h"

class FileLoaderThread;
class ArchiveHolder;
class FileHolder;
struct RequestFileInfo;

class FileLoader {
public:
    JKRArchive* receiveArchive(const char *);
    void getMountedArchiveAndHeap(const char *, JKRArchive **, JKRHeap **);
    void requestMountArchive(const char *, JKRHeap *, bool);
    JKRArchive* createAndAddArchive(void *, JKRHeap *, const char *);
    bool isNeedToLoad(const char*) const;
    const RequestFileInfo* getRequestFileInfoConst(const char*) const;
    RequestFileInfo* addRequest(const char*);

    FileLoaderThread* mLoaderThread;     // 0x00
    OSMutex mMutex;                      // 0x04
    RequestFileInfo* mRequestFileInfos;  // 0x1C
    s32 mRequestedFileCount;             // 0x20
    FileHolder* mHolder;                 // 0x24
    ArchiveHolder* mArchiveHolder;       // 0x28
};
