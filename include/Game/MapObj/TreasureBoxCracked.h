#pragma once

#include "syati.h"

class TreasureBoxCracked : public LiveActor {
public:
    TreasureBoxCracked(const char*);
    virtual ~TreasureBoxCracked();
    virtual void init(const JMapInfoIter&);
    virtual void makeActorAppeared();
    virtual void makeActorDead();
    virtual void control();
    virtual void attackSensor(HitSensor*, HitSensor*);
    virtual bool receiveMsgPlayerAttack(u32, HitSensor*, HitSensor*);
    virtual bool receiveMsgEnemyAttack(u32, HitSensor *, HitSensor *);
    void exeWait();
    void exeOpenWait();
    void exeAlwaysOpen();
    void initItem(const JMapInfoIter &);
    void makeOpen();
    void isHalfOpen() const;

    CollisionParts* mBoxCollisionParts;
    TMtx34f _94;
    u32 mType;
    u32 mUnlockRequirement;
    u32 _CC;
    u32 _D0;
    u32 _D4;
};

namespace NrvTreasureBoxCracked {
    NERVE(TreasureBoxCrackedNrvWait);
    NERVE(TreasureBoxCrackedNrvOpenWait);
    NERVE(TreasureBoxCrackedNrvAlwaysOpen);
};