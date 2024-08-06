#pragma once

#include "Game/LiveActor.h"
#include "Game/Util/JointController.h"

class BombHei : public LiveActor {
public:
    BombHei(const char *);
    ~BombHei();
    virtual void init(const JMapInfoIter &);
    virtual void initAfterPlacement();
    virtual void appear();
    virtual void kill();
    virtual void calcAndSetBaseMtx();
    virtual void control();
    virtual void attackSensor(HitSensor *, HitSensor *);
    virtual bool receiveMsgPlayerAttack(u32, HitSensor *, HitSensor *);
    virtual bool receiveMsgEnemyAttack(u32, HitSensor *, HitSensor *);
    virtual bool receiveMsgPush(HitSensor *, HitSensor *);
    virtual bool receiveOtherMsg(u32, HitSensor *, HitSensor *);
    bool receiveMsgThrow(HitSensor *, HitSensor *);

    void setGroupClipping(const JMapInfoIter &);
    void startCountdown();
    void endCountdown();
    void exeLaunch();
    void exeStarting();
    void exeWait();
    void exeWalk();
    void exePursue();
    void exePursueHit();
    void exeSpinHit();
    void exeTrample();
    void exePhysics();
    void exeStop();
    void exeThrown();
    void exeTaken();
    void exeExplode();
    void calcJoint(TPos3f *, JointControllerInfo &);
    void startBoundSound();
    u8 _90[0x58];
};

namespace NrvBombHei {
    NERVE(HostTypeNrvLaunch);
    NERVE(HostTypeNrvStarting);
    NERVE(HostTypeNrvWait);
    NERVE(HostTypeNrvWalk);
    NERVE(HostTypeNrvPursue);
    NERVE(HostTypeNrvPursueFast);
    NERVE(HostTypeNrvPursueHit);
    NERVE(HostTypeNrvSpinHit);
    NERVE(HostTypeNrvTrample);
    NERVE(HostTypeNrvPhysics);
    NERVE(HostTypeNrvStop);
    NERVE(HostTypeNrvTaken);
    NERVE(HostTypeNrvThrown);
    NERVE(HostTypeNrvExplode);
    NERVE(HostTypeNrvBindStarPointer);
};