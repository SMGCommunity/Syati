#pragma once

#include "syati.h"

class CrystalCage : public LiveActor {
public:
    CrystalCage(const char* pName);
    virtual ~CrystalCage();
    virtual void init(const JMapInfoIter& rIter);
    virtual void initAfterPlacement();
    virtual void appear();
    virtual void kill();
    virtual void attackSensor(HitSensor* pSender, HitSensor* pReceiver);
    virtual bool receiveMsgPlayerAttack(u32 msg, HitSensor* pSender, HitSensor* pReceiver);
    virtual bool receiveMsgEnemyAttack(u32 msg, HitSensor* pSender, HitSensor* pReceiver);

    void exeBreak();
    void initMapToolInfo(const JMapInfoIter& rIter);
    void initModel();
    bool tryOnSwitchDead();


    u32 mType; // 0x90
    u32 _94;
    TMtx34f _98;
    u32 _C8;
    u32 _CC;
    RumbleCalculatorCosMultLinear* mRumbleCalculator; // 0xD0
    f32 _D4;
    f32 _D8;
    f32 _DC;
    TVec3f _E0;
    TVec3f _EC;
    DummyDisplayModel* mDummyDisplayModel; // 0xF8
    TVec3f _FC;
    bool mSwitchDisappear; // 0x108
    bool mIsInPlaneModeCube; // 0x109
    bool mIsFalling; // 0x10A
    s32 mHideRemains; // 0x10C
    u32 _110;
    s32 mPlayRiddleSfx; // 0x114
    bool mUseBinder; // 0x118
    TVec3f _11C;
};

const size_t crystal = sizeof(CrystalCage);