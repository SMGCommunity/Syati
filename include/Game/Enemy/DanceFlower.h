#pragma once

#include "Game/LiveActor.h"
#include "Game/Enemy/AnimScaleController.h"
#include "Game/Enemy/WalkerStateBindStarPointer.h"
#include "Game/Player/YoshiLockOnTarget.h"

class DanceFlower : public LiveActor {
public:
    DanceFlower(const char *pName);
    virtual ~DanceFlower();
    virtual void init(const JMapInfoIter &rIter);
    virtual void initAfterPlacement();
    virtual void kill();
    virtual void control();
    virtual void calcAndSetBaseMtx();
    virtual void attackSensor(HitSensor *pReceiver, HitSensor *pSender);
    virtual bool receiveMsgEnemyAttack(u32 msg, HitSensor *pSender, HitSensor *pReceiver);
    virtual bool receiveMsgPlayerAttack(u32 msg, HitSensor *pSender, HitSensor *pReceiver);
    virtual bool receiveOtherMsg(u32 msg, HitSensor *pSender, HitSensor *pReceiver);

    // many unknown funcs

    ActorPoseTQ *_90;
    TVec3f _94;
    AnimScaleController *_A0;
    WalkerStateBindStarPointer *_A4;
    YoshiLockOnTarget *_A8;
    bool _AC;
};

// Nerves init'ed at 0x8017B150