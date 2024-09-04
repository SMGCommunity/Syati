#pragma once

#include "syati.h"

class KeySwitch;

class Teresa : public LiveActor {
public:
    Teresa(const char*);
    virtual ~Teresa();
    virtual void init(const JMapInfoIter&);
    void initDummyModel(const JMapInfoIter&);
    void initFromJMapParam(const JMapInfoIter&);
    virtual void makeActorAppeared();
    virtual void appear();
    virtual void kill();
    virtual void control();
    virtual void calcAndSetBaseMtx();
    virtual void attackSensor(HitSensor*, HitSensor*);
    virtual bool receiveMsgPush(HitSensor*, HitSensor*);
    virtual bool receiveMsgPlayerAttack(unsigned long, HitSensor*, HitSensor*);
    virtual bool receiveOtherMsg(unsigned long, HitSensor*, HitSensor*);
    void filterBind(const Triangle*);
    void requestAttack(HitSensor*, HitSensor*);
    void requestDrift();
    void requestLoveHit(HitSensor*, HitSensor*);
    void requestSearchLightDead();
    void setStartNerve();
    bool tryAppearFromWallEnd();
    bool tryAppearFromGroundEnd();
    bool tryRailTurn();
    bool tryRailTurnEnd();
    bool tryWalk();
    bool tryWalkEnd();
    bool tryChase();
    bool tryCheseEnd();
    bool tryFreeze();
    bool tryShay();
    bool tryShayEnd();
    bool tryLoveFind();
    bool tryLoveEnd();
    bool tryLoveFindEnd();
    bool tryLoveChaseEnd();
    bool tryLoveHitEnd();
    bool tryAggressiveEnd();
    bool tryAttackSuccessEnd();
    bool tryDriftEnd();
    bool tryHideWater();
    bool tryHideWall();
    bool tryHideWallEnd();
    bool tryAscension();
    void endAppear();
    void exeAppearFromWall();
    void exeAppearFromGround();
    void exeWait();
    void exeWalk();
    void exeRailWalk();
    void exeRailTurn();
    void exeLoveFind();
    void exeLoveChase();
    void exeLoveHit();
    void exeLoveEnd();
    void exeChase();
    void exeShay();
    void exeAggressive();
    void exeAttackSuccess();
    void exeDrift();
    void exeHideWall();
    void exeHideWater();
    void exeAscension();
    void exeStop();
    void updateNormalVelocity();
    void addDriftVelocity();
    void updateDriftAnimScale();
    void updateDriftTransparency();
    void updateNormalTransparency();
    void setTransparency(f32);
    void canAttack() const;
    void canDrift() const;
    void canSearchLightDead() const;
    bool isEnableStarPieceStop() const;
    bool isCheckWater() const;
    bool isEatable() const;
    bool isFreeze() const;
    bool isShay() const;

    DummyDisplayModel* mDummyDisplayModel; // 0x90
    KeySwitch* mKeySwitch; // 0x94
    AnimScaleController* mAnimScaleController; // 0x98
    s32 _9C;
    WalkerStateBindStarPointer* mWalkerStateBindStarPointer; // 0xA0
    TQuat4f _A4;
    TVec3f _B4;
    TVec3f _C0;
    TVec3f _CC;
    TVec3f _D8;
    TVec3f _E4;
    TVec3f _F0;
    f32 _FC;
    f32 _100;
    f32 _104;
    s32 _108;
    bool _10C;
    bool _10D;
    bool _10E;
    YoshiLockOnTarget* mYoshiLockOnTarget; // 0x110
};