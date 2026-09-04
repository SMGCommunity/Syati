#pragma once

#include "Game/LiveActor.h"
#include "Game/Enemy/AnimScaleController.h"
#include "Game/Enemy/WalkerStateBindStarPointer.h"
#include "Game/Enemy/Kuribo.h"
#include "Game/Player/YoshiLockOnTarget.h"

class Kabokuri : public LiveActor {
public:
    Kabokuri(const char *pName);
    virtual ~Kabokuri();
    virtual void init(const JMapInfoIter &rIter);
    virtual void initAfterPlacement();
    virtual void control();
    virtual void calcAndSetBaseMtx();
    virtual void attackSensor(HitSensor *pReceiver, HitSensor *pSender);
    virtual bool receiveMsgPlayerAttack(u32 msg, HitSensor *pSender, HitSensor *pReceiver);
    virtual bool receiveOtherMsg(u32 msg, HitSensor *pSender, HitSensor *pReceiver);

    void updatePose();
    void addVelocityBase();
    void addVelocityToRailPoint(f32);

    void exeWait();
    void exeWalk();
    void exeDropFire();
    void exeAttacksuccess();
    void exeTrampled();
    void exeStarPieceHitted();
    void exeHipDropped();
    void exeHitAttacked();
    void exeBreak();
    void exeEaten();
    
    bool requestTrampled();
    bool requestStarPieceHitted();
    bool requestHipDropped();
    bool requestHitAttacked(HitSensor *, HitSensor *);
    bool requestEaten();
    
    bool tryPointBind();
    bool tryYoshiEat();
    
    bool isEnableAttack() const;
    bool isEnablePointBind() const;
    bool isEnableTrampled() const;
    bool isEnablePush() const;
    bool isEatable() const;

    Kuribo *_90;
    ModelObj *mBreakModel;              // _94
    ModelObj *mHeadModel;               // _98
    Mtx _9C;
    Mtx _CC;
    AnimScaleController *_FC;
    WalkerStateBindStarPointer *_100;
    YoshiLockOnTarget *_104;
    TQuat4f _108;
    TVec3f _118;
    s32 _124;
    u32 _128;
    bool mNoCalcGravity;                // _12C
    u8 _12D;
};

namespace NrvKabokuri {
    NERVE(KabokuriNrvWait);
    NERVE(KabokuriNrvWalk);
    NERVE(KabokuriNrvDropFire);
    NERVE(KabokuriNrvAttacksuccess);
    NERVE(KabokuriNrvTrampled);
    NERVE(KabokuriNrvStarPieceHitted);
    NERVE(KabokuriNrvBindStarPointer);
    NERVE(KabokuriNrvHitAttacked);
    NERVE(KabokuriNrvHipDropped);
    NERVE(KabokuriNrvBreak);
    NERVE(KabokuriNrvEaten);
};