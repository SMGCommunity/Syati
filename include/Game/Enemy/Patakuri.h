#pragma once

#include "Game/LiveActor.h"
#include "Game/Enemy/Kuribo.h"
#include "Game/Player/YoshiLockOnTarget.h"
#include "Game/Enemy/AnimScaleController.h"
#include "Game/Enemy/WalkerStateBindStarPointer.h"

class PatakuriWing : public PartsModel {
public:
    PatakuriWing(const char *pName);
    virtual ~PatakuriWing();
};

class Patakuri : public LiveActor {
public:
    Patakuri(const char *pName);
    virtual ~Patakuri();
    virtual void init(const JMapInfoIter &rIter);
    virtual void control();
    virtual void calcAndSetBaseMtx();
    virtual void attackSensor(HitSensor *pReceiver, HitSensor *pSender);
    virtual bool receiveMsgPlayerAttack(u32 msg, HitSensor *pSender, HitSensor *pReceiver);
    virtual bool receiveOtherMsg(u32 msg, HitSensor *pSender, HitSensor *pReceiver);
    
    Kuribo *_90;
    TQuat4f _94;
    TVec3f _A4;
    PatakuriWing *_B0;
    AnimScaleController *_B4;
    WalkerStateBindStarPointer *_B8;
    YoshiLockOnTarget *_BC;
};

// PatakuriWing nerves