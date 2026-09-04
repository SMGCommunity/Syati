#pragma once

#include "Game/LiveActor.h"
#include "Game/MapObj/MapObjConnector.h"
#include "Game/Enemy/AnimScaleController.h"
#include "Game/Enemy/SpinHitController.h"
#include "Game/Enemy/WalkerStateBindStarPointer.h"
#include "Game/Player/YoshiLockOnTarget.h"

class TakoboInkHolder;

class Takobo : public LiveActor {
public:
    Takobo(const char *pName);
    virtual ~Takobo();
    virtual void init(const JMapInfoIter &rIter);
    virtual void initAfterPlacement();
    virtual void makeActorAppeared();
    virtual void kill();
    virtual void control();
    virtual void attackSensor(HitSensor *pReceiver, HitSensor *pSender);
    virtual bool receiveOtherMsg(u32 msg, HitSensor *pSender, HitSensor *pReceiver);
    virtual bool receiveMsgPlayerAttack(u32 msg, HitSensor *pSender, HitSensor *pReceiver);
    virtual bool receiveMsgEnemyAttack(u32 msg, HitSensor *pSender, HitSensor *pReceiver);
    virtual void calcAndSetBaseMtx();
    
    void exeHitPunch();
    void exePress();
    void exeHitReaction();
    void exeStunEnd();

    TVec3f _90;
    TVec3f _9C;
    TVec3f _A8;
    u8 _B4;
    u8 _B5;
    f32 _B8;
    f32 _BC;
    TVec3f _C0;
    u32 _CC;
    AnimScaleController *_D0;
    WalkerStateBindStarPointer *_D4;
    SpinHitController *_D8;
    TakoboInkHolder *_DC;
    YoshiLockOnTarget *_E0;
    MapObjConnector *_E4;
};