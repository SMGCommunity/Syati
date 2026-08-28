#pragma once

#include "Game/LiveActor.h"
#include "Game/Player/YoshiLockOnTarget.h"
#include "Game/Map/HitInfo.h"

class YoshiCapture : public LiveActor {
public:
    YoshiCapture(const char *pName);
    virtual ~YoshiCapture();
    virtual void init(const JMapInfoIter &rIter);
    virtual void initAfterPlacement();
    virtual void appear();
    virtual void kill();
    virtual void control();
    virtual bool receiveOtherMsg(u32 msg, HitSensor *pSender, HitSensor *pReceiver);

    void exeWait();
    void exeCatch();
    void exeRelease();

    u32 _90;
    YoshiLockOnTarget *mLockOnTarget;   // _94
    Mtx _98;
    f32 _C8;
    f32 _CC;
    f32 _D0;
    bool mIsFixedRotation;              // _D4
};

namespace NrvYoshiCapture {
    NERVE(YoshiCaptureNrvWait);
    NERVE(YoshiCaptureNrvCatch);
    NERVE(YoshiCaptureNrvRelease);
};

namespace MR {
    bool requestYoshiCapture();
};