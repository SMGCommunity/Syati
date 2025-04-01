#pragma once

#include "Game/LiveActor.h"
#include "Game/Player/YoshiTongue.h"
#include "Game/Player/YoshiSilhouette.h"

class Yoshi : public LiveActor {
public:
    Yoshi(const char *);
    virtual ~Yoshi();
    virtual void init(const JMapInfoIter &);
    virtual void makeActorAppeared();
    virtual void makeActorDead();
    virtual void movement();
    virtual void calcAnim();
    virtual void kill();
    virtual void control();
    virtual void calcAndSetBaseMtx();
    virtual void attackSensor(HitSensor *, HitSensor *);
    virtual bool receiveMsgPlayerAttack(u32, HitSensor *, HitSensor *);
    virtual bool receiveMsgPush(HitSensor *, HitSensor *);

    u32 _90;
    XanimeResourceTable *_94;
    u32 _98;
    u32 _9C;
    u32 _A0;
    u8 _A4;
    u8 _A5;
    Mtx _A8;
    u32 _D8;
    u32 _DC;
    u32 _E0;
    u32 _E4;
    TVec3f _E8;
    YoshiTongue *mYoshiTongue; // _F4
    u32 *_F8; // 80417D40
    u32 *_FC; // 8041A9A0
    u32 *_100; // 8040B440
    u32 *_104; // 804155D0
    u32 *_108; // 80412610
    u32 *_10C; // 80412700
    u32 *_110; // 80412990
    u32 *_114; // 80412A20
    u8 *_118;
    u32 *_11C; // 80412B40
    u32 *_120; // 80412E00
    u32 *_124; // JASMemChunkPool<1024,Q217JASThreadingModel19ObjectLevelLockable>::MemoryChunk::MemoryChunk
    u32 *_128; // 804132A0
    u32 *_12C; // 80413390
    u8 _130;
    u32 _134;
    u8 _138;
    u8 _139;
    u32 _13C;
    u32 _140;
    u8 _144;
    u8 _145;
    WaterInfo *mWaterInfo; // _148
    f32 _14C;
    f32 _150;
    f32 _154;
    u32 _158;
    f32 _15C;
    u32 _160;
    TVec3f _164;
    TVec3f _170;
    u32 _17C;
    u32 _180;
    u32 _184;
    u32 _188;
    f32 _18C;
    f32 _190;
    f32 _194;
    u8 _198;
    YoshiSilhouette *mYoshiSilhouette; // _19C
    u8 _1A0;
    u8 _1A1;
    u8 _1A2;
    BreakModel *mWaterColumn; // _1A4
    u32 _1A8;
};