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
    HeapMemoryWatcher* createHeaps();
    void createGameHeap();

    void memoryErrorCallback(void *, u32, int);
    void checkRestMemory();

    static JKRHeap* sRootHeapGDDR3;

    JKRHeap *mStationedHeapNapa; // 0
    JKRHeap *mStationedHeapGDDR3; // 4
    JKRHeap *mHeapNapa; // 8
    JKRHeap *mHeapGDDR3; // 0xC
    JKRHeap *mWorldMapHeap; // 0x10
    JKRHeap *mFileCacheHeap; // 0x14
    JKRHeap *_18; // 0x18
    JKRHeap *mSceneHeapNapa; // 0x1C
    JKRHeap *mSceneHeapGDDR3; // 0x20
    JKRHeap *mWPadHeap; // 0x24
    JKRHeap *mHomeButtonLayoutHeap; // 0x28
    JKRHeap *_2C;
};
