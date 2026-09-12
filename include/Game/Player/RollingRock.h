#pragma once

#include "Game/LiveActor/LiveActor.h"
#include "Game/LiveActor/HitSensor.h"
#include "Game/Util/JMapInfo.h"
#include "JSystem/JGeometry/TVec.h"
#include "revolution/types.h"

class RollingRock : public LiveActor {
public:
    RollingRock(const char *);
    ~RollingRock();
    virtual void init(const JMapInfoIter &);
    virtual void makeActorAppeared();
    virtual void kill();
    virtual void calcAnim();
    virtual void calcAndSetBaseMtx();
    virtual void attackSensor(HitSensor *, HitSensor *);
    virtual bool receiveMsgEnemyAttack(u32, HitSensor *, HitSensor *);
    virtual bool receiveMsgPush(HitSensor *, HitSensor *);
    virtual bool receiveOtherMsg(u32, HitSensor *, HitSensor *);

    u32 _90;
    u32 _94;
    u32 _98;
    u32 _9C;
    TVec4f _A0;
    Mtx _B0;
    Mtx _E0;
    TVec3f _110;
    f32 _11C;
    f32 _120;
    f32 _124;
};

namespace NrvRollingRock {
    NERVE(RollingRockNrvRolling);
}