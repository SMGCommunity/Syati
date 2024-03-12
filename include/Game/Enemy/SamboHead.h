#pragma once

#include "syati.h"

class SamboHead : public LiveActor {
public:
    SamboHead(const char*);
    virtual ~SamboHead();
    virtual void init(const JMapInfoIter&);
    virtual void appear();
    virtual void kill();
    virtual void control();
    virtual void attackSensor(HitSensor*, HitSensor*);
    virtual bool receiveMsgPlayerAttack(u32, HitSensor*, HitSensor*);
    virtual bool receiveMsgPush(HitSensor*, HitSensor*);
    virtual bool receiveOtherMsg(u32, HitSensor*, HitSensor*);
    void exeWaitUnderGround();
    void exeHide();
    void exeAppear();
    void exeWait();
    void exePrePursue();
    void exePursue();
    void exePursueEnd();
    void exeHitToPlayer();
    void exeStarPieceHit();
    void exeStampFall();
    void exeStampDeath();
    void exeHitBlow();
    void exeBuryDeath();
    void exeBindStarPointer();
    void exeBindStarPointerEnd();
    void calcAndSetBaseMtx();
    void isNerveTypeDead() const;
    void isStarPointerBindable() const;

    SpinHitController* mSpinHitController; // 0x90
    AnimScaleController* mAnimScaleController; // 0x94
    WalkerStateBindStarPointer* mWalkerStateBindStarPointer; // 0x98
    TVec3f _9C;
    s32 _A0;
    s32 _A4;
    TVec3f _A8;
    s32 _B4;
    s32 _B8;
};

namespace NrvSamboHead {
    NERVE(HostTypeNrvHide);
    NERVE(HostTypeNrvAppear);
    NERVE(HostTypeNrvAppearImmediately);
    NERVE(HostTypeNrvWait);
    NERVE(HostTypeNrvPrePursue);
    NERVE(HostTypeNrvPursue);
    NERVE(HostTypeNrvPursueEnd);
    NERVE(HostTypeNrvHitToPlayer);
    NERVE(HostTypeNrvStarPieceHit);
    NERVE(HostTypeNrvStampFall);
    NERVE(HostTypeNrvStampDeath);
    NERVE(HostTypeNrvHitBlow);
    NERVE(HostTypeNrvBuryDeath);
    NERVE(HostTypeNrvBindStarPointer);
    NERVE(HostTypeNrvBindStarPointerEnd);
};