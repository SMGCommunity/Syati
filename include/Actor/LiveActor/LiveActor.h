#pragma once

#include "Actor/Animation/ActorAnimKeeper.h"
#include "Actor/Camera/ActorPadAndCameraCtrl.h"
#include "Actor/Effect/EffectKeeper.h"
#include "Actor/Light/ActorLightCtrl.h"
#include "Actor/NameObj/NameObj.h"
#include "Actor/Nerve/Spine.h"
#include "Actor/Rail/RailRider.h"
#include "Actor/Sensor/HitSensor.h"
#include "Actor/Sensor/HitSensorKeeper.h"
#include "Actor/Shadow/ShadowController.h"
#include "Actor/Sound/AudAnmSoundObject.h"
#include "Actor/StarPointer/StarPointerTarget.h"
#include "Collision/Binder.h"
#include "Collision/CollisionParts.h"
#include "JGeometry/TVec3.h"
#include "Actor/Model/ModelManager.h"
#include "Map/Switch/StageSwitch.h"

class LiveActorFlag
{
public:
    LiveActorFlag();

    bool mIsDead; // _0
    bool mIsNotReleasedAnimFrame; // _1
    bool mIsOnCalcAnim; // _2
    bool mIsNoCalcView; // _3
    bool mIsNoEntryDrawBuffer; // _4
    bool mIsOnBind; // _5
    bool mIsCalcGravity; // _6
    bool mIsClipped; // _7
    bool mIsClippingInvalid; // _8
};

class LiveActor : public NameObj
{
public:
    LiveActor(const char *);

    virtual void init(JMapInfoIter const &);

    virtual void movement();

    virtual void calcAnim();
    virtual void calcViewAndEntry();

    virtual void appear();
    virtual void makeActorAppeared();
    virtual void kill();
    virtual void makeActorDead();
    virtual s32 receiveMessage(u32, HitSensor *, HitSensor *);
    virtual Mtx* getBaseMtx() const;
    virtual Mtx* getTakingMtx() const;
    virtual void startClipped();
    virtual void endClipped();
    virtual void control();
    virtual void calcAndSetBaseMtx();
    virtual void updateHitSensor(HitSensor *);
    virtual void attackSensor(HitSensor *, HitSensor *);
    virtual u32 receiveMsgPush(HitSensor *, HitSensor *);
    virtual u32 receiveMsgPlayerAttack(u32, HitSensor *, HitSensor *);
    virtual u32 receiveMsgEnemyAttack(u32, HitSensor *, HitSensor *);
    virtual u32 receiveOtherMsg(u32, HitSensor *, HitSensor *);

    void initStageSwitch(const JMapInfoIter &iter);
    void initActorStarPointerTarget(f32, const TVec3f *, Mtx4 *, TVec3f);
	
    void initRailRider(const JMapInfoIter &);
    void initHitSensor(s32);
    void initModelManagerWithAnm(const char *, const char *);
    void initEffectKeeper(s32, const char *, bool);
    void initSound(s32, const char *, bool, const TVec3f &);
    void initNerve(const Nerve *, s32);
    void initShadowControllerList(u32);
    void initBinder(f32, f32, u32);

    void setNerve(const Nerve *);
    bool isNerve(const Nerve*) const;
    s32 getNerveStep() const;

    void func_8000C170(const JMapInfoIter &, const char *, bool);

    HitSensor* getSensor(const char *) const;

    TVec3f mTranslation; // _14
    TVec3f mRotation; // _20
    TVec3f mScale; // _2C
    TVec3f mVelocity; // _38
    TVec3f mGravity; // _44
    ModelManager* mModelManager; // _50
    ActorAnimKeeper* mAnimKeeper; // _54
    Spine* mSpine; // _58
    HitSensorKeeper* mSensorKeeper; //_5C
    Binder* mBinder; // _60
    RailRider* mRailRider; // _64
    EffectKeeper* mEffectKeeper; // _68
    AudAnmSoundObject* mSoundObj; // _6C
    LiveActorFlag mFlags; // _70
    ShadowControllerList* mShadowController; // _7C
    CollisionParts* mCollisionParts; // _80
    StageSwitchCtrl* mStageSwitchCtrl; // _84
    StarPointerTarget* mPointerTarget; // _88
    ActorLightCtrl* mLightCtrl; // _8C
};
