#pragma once

#include "Game/LiveActor/LiveActor.h"

class SpinHitController;
class AnimScaleController;
class StringSpiderString;
class WalkerStateBindStarPointer;
class FixedPosition;
class YoshiLockOnTarget;

class StringSpider : public LiveActor {
public:
    StringSpider(const char*);

    virtual ~StringSpider();
    virtual void init(const JMapInfoIter&);
    virtual void initAfterPlacement();
    virtual void calcAnim();
    virtual void kill();
    virtual void startClipped();
    virtual void endClipped();
    virtual void control();
    virtual void calcAndSetBaseMtx();
    virtual void attackSensor(HitSensor*, HitSensor*);
    virtual bool receiveMsgPush(HitSensor*, HitSensor*);
    virtual bool receiveMsgPlayerAttack(u32, HitSensor*, HitSensor*);
    virtual bool receiveMsgEnemyAttack(u32, HitSensor*, HitSensor*);
    virtual bool receiveOtherMsg(u32, HitSensor*, HitSensor*);

    s32 getSearchToAttackTime();
    void doSwingAction(f32, bool);
    void reactDPD();
    void reactStringForce();
    bool isOverStringLength(TVec3f*, f32*);
    TVec3f calcToRootVector();
    void calcPosture(f32, bool);
    void tearDownDpdGripped();
    void extendString();
    void shortenString(f32);
    bool reactSpinHit(HitSensor*, HitSensor*);
    void startSwingLevelSound();
    bool isEatable() const;
    bool isDamaging() const;

    void exeWait();
    void endWait();
    void exeDownStart();
    void exeDownEnd();
    void exeDown();
    void exeUp();
    void exeSearch();
    void exeAttack();
    void exeHit();
    void exeSpinned();
    void exeTrampleFall();
    void exeWallHitDeath();
    void exeBlow();
    void exeDpdGripped();
    void endDpdGripped();

    /* 0x90 */ SpinHitController* mSpinHitController;
    /* 0x94 */ AnimScaleController* mScaleController;
    /* 0x98 */ StringSpiderString* mString;
    /* 0x9C */ WalkerStateBindStarPointer* mBindStarPointer;
    /* 0xA0 */ FixedPosition* mFixedPos;
    /* 0xA4 */ YoshiLockOnTarget* mYoshiLockOnTarget;
    /* 0xA8 */ TQuat4f _A8;
    /* 0xB8 */ TQuat4f _B8;
    /* 0xC8 */ f32 _C8;
    /* 0xCC */ f32 _CC;
};

class StringSpiderString : public LiveActor {
public:
    StringSpiderString(const char*);

    virtual ~StringSpiderString();
    virtual void calcAndSetBaseMtx();

    /* 0x90 */ TQuat4f _90;
    /* 0xA0 */ TVec3f _A0;
};
