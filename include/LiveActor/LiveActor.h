#pragma once

#include "LiveActor/Animation/ActorAnimKeeper.h"
#include "LiveActor/Camera/ActorPadAndCameraCtrl.h"
#include "LiveActor/Effect/EffectKeeper.h"
#include "LiveActor/Light/ActorLightCtrl.h"
#include "NameObj/NameObj.h"
#include "LiveActor/Spine.h"
#include "LiveActor/Rail/RailRider.h"
#include "LiveActor/Sensor/HitSensor.h"
#include "LiveActor/Sensor/HitSensorKeeper.h"
#include "LiveActor/Shadow/ShadowController.h"
#include "LiveActor/Sound/AudAnmSoundObject.h"
#include "LiveActor/StarPointer/StarPointerTarget.h"
#include "LiveActor/Binder.h"
#include "Map/Collision/CollisionParts.h"
#include "JGeometry/TVec3.h"
#include "LiveActor/Model/ModelManager.h"
#include "Map/Switch/StageSwitch.h"

class ResourceHolder;

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
    virtual bool receiveMessage(u32, HitSensor *, HitSensor *);
    virtual Mtx* getBaseMtx() const;
    virtual Mtx* getTakingMtx() const;
    virtual void startClipped();
    virtual void endClipped();
    virtual void control();
    virtual void calcAndSetBaseMtx();
    virtual void updateHitSensor(HitSensor *);
    virtual void attackSensor(HitSensor *, HitSensor *);
    virtual bool receiveMsgPush(HitSensor *, HitSensor *);
    virtual bool receiveMsgPlayerAttack(u32, HitSensor *, HitSensor *);
    virtual bool receiveMsgEnemyAttack(u32, HitSensor *, HitSensor *);
    virtual bool receiveOtherMsg(u32, HitSensor *, HitSensor *);
    
    void setNerve(const Nerve *);
    bool isNerve(const Nerve*) const;
    s32 getNerveStep() const;

    HitSensor* getSensor(const char *) const;

    void initModelManagerWithAnm(const char *, const char *, bool, bool);
    void initNerve(const Nerve *, s32);
    void initHitSensor(s32);
    void initBinder(f32, f32, u32);
    void initRailRider(const JMapInfoIter &);
    void initEffectKeeper(s32, const char *, bool);
    void initSound(s32, const char *, bool, const TVec3f &);
    void initShadowControllerList(u32);
    void initActorCollisionParts(const char *, HitSensor *, ResourceHolder *, MtxPtr, bool, bool);
    void initStageSwitch(const JMapInfoIter &iter);
    void initActorStarPointerTarget(f32, const TVec3f *, MtxPtr, TVec3f);
	void initActorLightCtrl();

    void updateBinder();

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
