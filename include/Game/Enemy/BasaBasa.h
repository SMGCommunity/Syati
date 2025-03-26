#pragma once

#include "Game/Enemy/AnimScaleController.h"
#include "Game/Enemy/AnimStampController.h"
#include "Game/Enemy/SpinHitController.h"
#include "Game/LiveActor/LiveActor.h"
#include "Game/LiveActor/ModelObj.h"
#include "Game/System/NerveExecutor.h"

class BasaBasa : public LiveActor {
public:
    BasaBasa(const char*);

    virtual ~BasaBasa();
    virtual void init(const JMapInfoIter& rIter);
    virtual void initAfterPlacement();
    virtual void kill();
    virtual void control();
    virtual void calcAndSetBaseMtx();
    virtual void attackSensor(HitSensor* pSender, HitSensor* pReceiver);
    virtual bool receiveMsgPush(HitSensor* pSender, HitSensor* pReceiver);
    virtual bool receiveMsgPlayerAttack(u32 msg, HitSensor* pSender, HitSensor* pReceiver);
    virtual bool receiveMsgEnemyAttack(u32 msg, HitSensor* pSender, HitSensor* pReceiver);
    virtual bool receiveOtherMsg(u32 msg, HitSensor* pSender, HitSensor* pReceiver);

    static void trySetMarioHolderFrozenIceFlag(const JMapInfoIter& rIter); // Needs Symbol added to Symbol Map

    void exeWait();
    void exeAirWait();
    void exeChaseStart();
    void exeChase();
    void exeQuickTurnStart();
    void exeQuickTurn();
    void exeTrampleDown();
    void exePunchDown();
    void exeAttackStart();
    void exeAttack();
    void exeAttackEnd();
    void exeAttackEndRecover();
    void exeHitBack();
    void exeHitBackEnd();
    void exeComeHome();
    void exeAttachCeiling();
    void exeDPDSwoon();
    void exeStun();

    void initHangModel();
    bool tryClippingAndResetPos();
    bool trySetNerveDPDSwoon();
    bool tryComeHome();
    void updateRailType();
    void controlVelocity();
    void tuneHeight();
    bool isNearTarget(f32 range) const;
    bool isNrvEnableStun() const;

    ModelObj* mHangModel; // 0x90
    AnimScaleController* mAnimScaleCtrl; // 0x94
    AnimStampController* mAnimStampCtrl; // 0x98
    SpinHitController* mSpinHitController; // 0x9C
    TVec3f _A0; // 0xA0
    f32 mDetectionRange; // 0xAC
    f32 _B0; // 0xB0
    s32 _B4; // 0xB4 | Seemingly unused?
    TVec3f* mTargetPosition; // 0xB8
    f32 _BC;
    TVec3f _C0;
    bool mIsIceBasaBasa; // 0xCC
    TVec3f mHomePos; // 0xD0
    TVec3f _DC;
    f32 mAttackRange; // 0xE8
    s32 _EC;
    bool mIsHanging; // 0xF0
};

namespace NrvBasaBasa {
    NERVE(BasaBasaNrvWait);
    NERVE(BasaBasaNrvAirWait);
    NERVE(BasaBasaNrvChaseStart);
    NERVE(BasaBasaNrvChase);
    NERVE(BasaBasaNrvQuickTurnStart);
    NERVE(BasaBasaNrvQuickTurn);
    NERVE(BasaBasaNrvPunchDown);
    NERVE(BasaBasaNrvTrampleDown);
    NERVE(BasaBasaNrvAttackStart);
    NERVE(BasaBasaNrvAttack);
    NERVE(BasaBasaNrvAttackEnd);
    NERVE(BasaBasaNrvAttackEndRecover);
    NERVE(BasaBasaNrvHitBack);
    NERVE(BasaBasaNrvHitBackEnd);
    NERVE(BasaBasaNrvComeHome);
    NERVE(BasaBasaNrvAttachCelling);
    ENDABLE_NERVE(BasaBasaNrvDPDSwoon);
    NERVE(BasaBasaNrvStun);
}