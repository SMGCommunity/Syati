#pragma once

#include "Game/LiveActor.h"

class WaterPressureBullet : public LiveActor {
public:
    WaterPressureBullet(const char *pName);
    ~WaterPressureBullet();
    virtual void init(const JMapInfoIter &rIter);
    virtual void kill();
    virtual void movement();
    virtual void control();
    virtual void calcAndSetBaseMtx();
    virtual void attackSensor(HitSensor *, HitSensor *);
    virtual bool receiveMsgPlayerAttack(u32, HitSensor *, HitSensor *);
    virtual bool receiveOtherMsg(u32, HitSensor *, HitSensor *);
    void shotWaterBullet(LiveActor *, const TPos3f &, f32, bool, bool, bool, ActorCameraInfo **);
    void exeFly();
    void exeSpinKill();
    bool startHostCamera() const;
    bool endHostCamera() const;
    bool inviteMario(HitSensor *);

    f32 _90;
    f32 _94;
    f32 _98;
    f32 _9C;
    f32 _A0;
    f32 _A4;
    u32 _A8;
    f32 _AC;
    u32 _B0;
    bool _B4;
    bool _B5;
    bool _B6;
    u32 _BC;
};

namespace NrvWaterPressureBullet {
    NERVE(WaterPressureBulletNrvFly);
    NERVE(WaterPressureBulletNrvSpinKill);
}