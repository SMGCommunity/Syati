#pragma once

#include "Game/LiveActor/LiveActor.h"
#include "JSystem/JGeometry.h"

class InfernoMario : public LiveActor {
public:
    InfernoMario(const char *pName);
    ~InfernoMario();
    virtual void init(const JMapInfoIter &rIter);
    virtual void draw() const;
    virtual void makeActorAppeared();
    virtual void kill();
    virtual void control();
    virtual void calcAndSetBaseMtx();
    virtual void attackSensor(HitSensor *, HitSensor *);
    virtual bool receiveMsgPlayerAttack(u32, HitSensor *, HitSensor *);
    virtual bool receiveMsgEnemyAttack(u32, HitSensor *, HitSensor *);
    virtual bool receiveOtherMsg(u32, HitSensor *, HitSensor *);

    u32 _90;
    u32 _94;
    u32 _98;
    u32 _9C;
    TVec4f _A0;
    TVec4f _B0;
    TVec4f _C0;
    f32 _D0;
    f32 _D4;
    f32 _D8;
    u32 _DC;
    u32 _E0;
    u8 _E4;
    // Start of Padding
    u32 _E8;
    u32 _EC;
    u32 _F0;
    u32 _F4;
    u32 _F8;
    u32 _FC;
    u32 _100;
    u32 _104;
    u32 _108;
    u32 _10C;
    u32 _110;
    u32 _114;
    u32 _118;
    u32 _11C;
    u32 _120;
    // End of Padding
    u32 _124;
    u8 _128;
};