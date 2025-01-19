#pragma once

#include "Game/LiveActor.h"

class TeresaAtomic : public LiveActor {
public:
    TeresaAtomic(const char *);
    ~TeresaAtomic();
    virtual void init(const JMapInfoIter &);
    virtual void makeActorAppeared();
    virtual void makeActorDead();
    virtual void appear();
    virtual void kill();
    virtual void attackSensor(HitSensor *, HitSensor *);
    virtual bool receiveMsgPlayerAttack(u32, HitSensor *, HitSensor *);
    virtual void control();
    virtual void calcAndSetBaseMtx();
    
    bool isEnableAttack() const;
    bool isEnablePush() const;
    bool isEnableStarPieceAttack() const;
    bool tryDisappear();
    bool tryDead();
    void exeAppear();
    void exeWait();
    void exeChase();
    void exeShay();
    void exeAggressive();
    void exeLaugh();
    void exeDead();
    void exeDisappear();

    u32 _90;
    TVec3f mFrontVec;                   // _94
    f32 mSpeed;                         // _A0
    s32 mPowerStarType;                 // _A4
    PartsModel **mChildTeresas;         // _A8 (array size 4)
    PartsModel *mTeresaAtomicPosition;  // _AC
    s32 mChildTeresaNum;                // _B0
};

namespace NrvTeresaAtomic {
    NERVE(TeresaAtomicNrvAppear);
    NERVE(TeresaAtomicNrvWait);
    NERVE(TeresaAtomicNrvChase);
    NERVE(TeresaAtomicNrvShay);
    NERVE(TeresaAtomicNrvAggressive);
    NERVE(TeresaAtomicNrvLaugh);
    NERVE(TeresaAtomicNrvDead);
    NERVE(TeresaAtomicNrvDisappear);
    NERVE(TeresaAtomicNrvDeadPowerStarGet);
}