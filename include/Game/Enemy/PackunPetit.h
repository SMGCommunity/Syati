#pragma once

#include "Game/LiveActor.h"
#include "Game/Enemy/AnimScaleController.h"
#include "Game/Enemy/WalkerStateBindStarPointer.h"
#include "Game/Player/YoshiLockOnTarget.h"

class PackunPetit : public LiveActor {
public:
    PackunPetit(const char *pName);
    virtual ~PackunPetit();
    virtual void init(const JMapInfoIter &rIter);
    virtual void initAfterPlacement();
    virtual void makeActorDead();
    virtual void kill();
    virtual void calcAndSetBaseMtx();
    virtual void control();
    virtual void attackSensor(HitSensor *pReceiver, HitSensor *pSender);
    virtual bool receiveMsgPlayerAttack(u32, HitSensor *pSender, HitSensor *pReceiver);
    virtual bool receiveMsgEnemyAttack(u32, HitSensor *pSender, HitSensor *pReceiver);
    virtual bool receiveOtherMsg(u32, HitSensor *pSender, HitSensor *pReceiver);

    void initBlowModel();
    void punchDown(HitSensor *, HitSensor *);
    void selectNrvWait();

    void exeNonActive();
    void exeWait();
    void exeFind();
    void exeThreat();
    void exeTurn();
    void exeAttackStart();
    void exeHitWaitForAttack();
    void exeHit();
    void exeTrampleDown();
    void exePunchDown();
    void exeSwoonStart();
    void exeSwoon();
    void exeSwoonToThreat();

    bool tryNonActive();
    bool tryTurn();
    bool tryDPDSwoon();
    
    AnimScaleController *_90;
    WalkerStateBindStarPointer *_94;
    TVec3f _98;
    LiveActor *_A4;
    bool mNoTurn;                       // _A8
    bool mUseBinder;                    // _A9
    Mtx _AC;
    Mtx _DC;
    YoshiLockOnTarget *_10C;
    TVec3f _110;
};

namespace NrvPackunPetit {
    NERVE(PackunPetitNrvNonActive);
    NERVE(PackunPetitNrvWait);
    NERVE(PackunPetitNrvFind);
    NERVE(PackunPetitNrvThreat);
    NERVE(PackunPetitNrvLeftTurn);
    NERVE(PackunPetitNrvRightTurn);
    NERVE(PackunPetitNrvAttackStart);
    NERVE(PackunPetitNrvAttack);
    NERVE(PackunPetitNrvAttackBack);
    NERVE(PackunPetitNrvHitWaitForAttack);
    NERVE(PackunPetitNrvHit);
    NERVE(PackunPetitNrvTrampleDown);
    NERVE(PackunPetitNrvPunchDown);
    NERVE(PackunPetitNrvSwoonStart);
    NERVE(PackunPetitNrvSwoon);
    NERVE(PackunPetitNrvSwoonToThreat);
    NERVE(PackunPetitNrvDPDSwoon);
    // 4 more nerves
};