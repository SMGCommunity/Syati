#pragma once

#include "revolution.h"
#include "JSystem.h"

class HeapMemoryWatcherFunction {
public:
    static JKRHeap* createExpHeap(u32, JKRHeap *, bool);
    static JKRHeap* createSolidHeap(u32, JKRHeap *);
    static JKRHeap* destroyHeapAndSetNULL(u32, JKRHeap **);
};

class HeapMemoryWatcher {
public:
    HeapMemoryWatcher();

    JKRHeap* getHeapNapa(const JKRHeap *);
    JKRHeap* getHeapGDDR3(const JKRHeap *);
    void createWorldMapHeap();
    void createFileCacheHeapOnGameHeap(u32 size);
    void createSceneHeapOnGameHeap();
    void adjustStationedHeapNapa();
    void adjustStationedHeapGDDR3();
    void setCurrentHeapToStationedHeap();
    void setCurrentHeapToGameHeap();
    void setCurrentHeapToSceneHeap();
    void resetHeapNapaAndGDDR3();
    void resetHeapNapa();
    void resetHeapGDDR3();
    void destroyWorldMapHeap();
    void destroyFileCache();
    void destroySceneHeap();
    void createRootHeap();
    void createHeaps();
    void createGameHeap();

    void memoryErrorCallback(void *, u32, int);
    void checkRestMemory();

    static JKRExpHeap* sRootHeapGDDR3;

    JKRExpHeap *mStationedHeapNapa; // 0
    JKRExpHeap *mStationedHeapGDDR3; // 4
    JKRExpHeap *mHeapNapa; // 8
    JKRExpHeap *mHeapGDDR3; // 0xC
    JKRSolidHeap *mWorldMapHeap; // 0x10
    JKRSolidHeap *mFileCacheHeap; // 0x14
    JKRHeap *_18; // 0x18 appears to be some sort of SMG2 exclusive JKRHeap child class?
    JKRSolidHeap *mSceneHeapNapa; // 0x1C
    JKRSolidHeap *mSceneHeapGDDR3; // 0x20
    JKRExpHeap *mWPadHeap; // 0x24
    JKRExpHeap *mHomeButtonLayoutHeap; // 0x28
    JKRSolidHeap *_2C;
};
