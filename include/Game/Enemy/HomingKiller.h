#pragma once

#include "Game/LiveActor/LiveActor.h"
#include "Game/LiveActor/PartsModel.h"
#include "Game/LiveActor/ModelObj.h"
#include "Game/Player/YoshiLockOnTarget.h"
#include "Game/Enemy/AnimScaleController.h"

class HomingKiller : public LiveActor {
public:
    enum Type { Type_HomingKiller = 0, Type_Torpedo = 1, Type_MagnumKiller = 2 };

    HomingKiller(const char*);

    virtual void init(const JMapInfoIter&);
    virtual void appear();
    virtual void control();
    virtual void calcAndSetBaseMtx();
    virtual void attackSensor(HitSensor* pSender, HitSensor* pReceiver);
    virtual bool receiveMsgPlayerAttack(u32 msg, HitSensor* pSender, HitSensor* pReceiver);
    virtual bool receiveMsgEnemyAttack(u32 msg, HitSensor* pSender, HitSensor* pReceiver);
    virtual bool receiveOtherMsg(u32 msg, HitSensor* pSender, HitSensor* pReceiver);

    void appear(const TVec3f&, const TVec3f&);
    bool isMoveStart() const;


    Type mType; // 0x90
    f32 _94; // 0x94
    f32 _98; // 0x98
    f32 _9C; // 0x9C
    f32 _A0; // 0xA0
    f32 _A4; // 0xA4
    TVec3f mFront; // 0xA8
    TVec3f mUp; // 0xB4
    TVec3f mBasePos; // 0xC0
    TVec3f mBaseFront; // 0xCC
    TVec3f mBaseUp; // 0xD8
    TPos3f mBaseMtx; // 0xE4
    s32 _114; // 0x114
    s32 _118; // 0x118
    s32 _11C; // 0x11C
    TPos3f mEffectMtx; // 0x120
    HitSensor* mTargetSensor; // 0x150
    bool mDisableChase; // 0x154
    bool mIsLinearShot; // 0x155
    bool mUseFullSightAngle; // 0x156
    PartsModel* mPropeller; // 0x158
    ModelObj* mTorpedoLight; // 0x15C
    s32 _160; // 0x160 : NEW to SMG2
    YoshiLockOnTarget* mYoshiTarget; // 0x164 : NEW to SMG2
    s32 _168; // 0x168 : NEW to SMG2
    s32 mMaxLifeTime; // 0x16C : NEw to SMG2
    s32 mBinderActivationDelay; // 0x170 : New to SMG2
    s32 _174; // 0x174 : NEW to SMG2
    AnimScaleParam* mAnimScaleParam; // 0x178 : NEW to SMG2
    AnimScaleController* mAnimScaleCtrl; // 0x17C : NEW to SMG2
};