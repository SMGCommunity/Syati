#pragma once

#include "syati.h"

class Kuribo : public LiveActor {
    public:

    Kuribo(const char*);
    virtual void init(const JMapInfoIter&);
    virtual void initAfterPlacement();
    void initState();
    void initAppearState(const JMapInfoIter&);
    virtual void makeActorAppeared();
    virtual void makeActorDead();
    virtual void kill();
    virtual void control();
    virtual void calcAndSetBaseMtx();
    virtual void attackSensor(HitSensor*, HitSensor*);
    virtual bool receiveMsgPlayerAttack(u32, HitSensor*, HitSensor*);
    virtual bool receiveMsgEnemyAttack(u32, HitSensor*, HitSensor*);
    virtual bool receiveMsgPush(HitSensor*, HitSensor*);
    virtual bool receiveOtherMsg(u32, HitSensor*, HitSensor*);
    void requestDead();
    void requestFlatDown(HitSensor*, HitSensor*);
    void requestHipDropDown(HitSensor*, HitSensor*);
    void requestPressDown();
    void requestStagger(HitSensor*, HitSensor*);
    void requestBlowDown(HitSensor*, HitSensor*);
    void requestAttackSuccess();
    void onNoGravitySupport();
    void setUp(const TVec3f&, const TQuat4f&, const TVec3f&);
    void appearBlowed(const TVec3f&, const TQuat4f&, const TVec3f&);
    void tryNonActive();
    void tryActive();
    void tryEndBlow();
    void tryEndBlowLand();
    void tryFind();
    void tryPointBind();
    void tryDead();
    void exeWander();
    void exeFindPlayer();
    void exeChase();
    void exeStagger();
    void exeBindStarPointer();
    void exeNonActive();
    void exeAppearFromBox();
    void exeBlow();
    void exeAttackSuccess();
    void exeHipDropDown();
    void exeFlatDown();
    void exePressDown();
    void exeBlowDown();
    void calcPassiveMovement();
    void isEnableKick() const;
    void isUpsideDown() const;
    void isEnableDead() const;
    void isEnablePointBind() const;
    void isEnableAttack() const;
    void isEnableStamp() const;
    void isEnablePushMove() const;
    virtual ~Kuribo();

    AnimScaleController* mAnimScaleController; // 0x90
    s32 _94;
    YoshiLockOnTarget* mYoshiLockOnTarget; // 0x98
    s32 _9C;
    s32 _A0;
    s32 _A4;
    s32 _A8;
    TQuat4f _AC;
    TVec3f _BC;
    s32 _C8;
    bool _CC;
    bool _CD;
    bool _CE;
};

namespace NrvKuribo {
    NERVE(KuriboNrvNonActive);
    NERVE(KuriboNrvAppearFromBox);
    NERVE(KuriboNrvBlow);
    NERVE(KuriboNrvBlowLand);
    NERVE(KuriboNrvWander);
    NERVE(KuriboNrvFindPlayer);
    NERVE(KuriboNrvChase);
    NERVE(KuriboNrvAttackSuccess);
    NERVE(KuriboNrvBindStarPointer);
    NERVE(KuriboNrvStagger);
    NERVE(KuriboNrvFlatDown);
    NERVE(KuriboNrvHipDropDown);
    NERVE(KuriboNrvPressDown);
    NERVE(KuriboNrvBlowDown);
};