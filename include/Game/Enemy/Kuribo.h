#pragma once

#include "syati.h"

class Kuribo : public LiveActor {
    public:

    Kuribo(const char*);
    virtual ~Kuribo();
    virtual void init(const JMapInfoIter&);
    virtual void initAfterPlacement();
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
    void initState();
    void initAppearState(const JMapInfoIter&);
    bool requestDead();
    bool requestFlatDown(HitSensor*, HitSensor*);
    bool requestHipDropDown(HitSensor*, HitSensor*);
    bool requestPressDown();
    bool requestStagger(HitSensor*, HitSensor*);
    bool requestBlowDown(HitSensor*, HitSensor*);
    bool requestAttackSuccess();
    void onNoGravitySupport();
    void setUp(const TVec3f&, const TQuat4f&, const TVec3f&);
    void appearBlowed(const TVec3f&, const TQuat4f&, const TVec3f&);
    bool tryNonActive();
    bool tryActive();
    bool tryEndBlow();
    bool tryEndBlowLand();
    bool tryFind();
    bool tryPointBind();
    bool tryDead();
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
    bool calcPassiveMovement();
    bool isEnableKick() const;
    bool isUpsideDown() const;
    bool isEnableDead() const;
    bool isEnablePointBind() const;
    bool isEnableAttack() const;
    bool isEnableStamp() const;
    bool isEnablePushMove() const;

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