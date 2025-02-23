#pragma once

#include "Game/LiveActor.h"

class ElectricPressureBullet : public LiveActor {
public:
    ElectricPressureBullet(const char *pName);
    virtual void init(const JMapInfoIter &rIter);
    virtual void kill();
    virtual void control();
    virtual void attackSensor(HitSensor *, HitSensor *);
    virtual bool receiveOtherMsg(u32, HitSensor *, HitSensor *);
    void shotElectricBullet(LiveActor *, const TPos3f &, const f32 &, bool);
    void exeFly();

    f32 _90;
    f32 _94;
    f32 _98;
    u32 _9C;
    f32 _A0;
    bool _A4;
};

namespace NrvElectricPressureBullet {
    NERVE(ElectricPressureBulletNrvFly);
}