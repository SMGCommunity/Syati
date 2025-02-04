#pragma once

#include "Game/LiveActor/LiveActor.h"
#include "revolution.h"

class ActorAnimDataInfo {
public:
    ActorAnimDataInfo();
    
    f32 _4;
    u8 _8;
};

class ActorAnimKeeperInfo {
public:
    ActorAnimKeeperInfo();

    ActorAnimDataInfo _4;
    ActorAnimDataInfo _10;
    ActorAnimDataInfo _1C;
    ActorAnimDataInfo _28;
    ActorAnimDataInfo _34;
    ActorAnimDataInfo _40;
};

class ActorAnimKeeper {
public:
    ActorAnimKeeper(LiveActor *);

    void start(const char *);
    void update();
    bool trySetAllFrame();
    bool isExistAnim(const char *);
    bool isAnyAnimPlaying(const char *);
    bool initAnimData();
    void findAnimInfo(const char *) const;

    static ActorAnimKeeper* tryCreate(LiveActor *);

    LiveActor* mActor;  // 0x0
    u32 _4;
    u32 _8;
    u32 _C;
};