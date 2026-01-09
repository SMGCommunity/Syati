#pragma once

#include "Game/LiveActor/LiveActor.h"
#include "Game/LiveActor/ActorCameraInfo.h"

class Pole : public LiveActor {
public:
    Pole(const char*);

    virtual ~Pole();
    virtual void init(const JMapInfoIter& rIter);
    virtual void calcAnim();
    virtual void appear();
    virtual MtxPtr getBaseMtx() const;
    virtual void attackSensor(HitSensor* pSender, HitSensor* pReceiver);
    virtual bool receiveMsgPlayerAttack(u32 msg, HitSensor* pSender, HitSensor* pReceiver);
    virtual bool receiveMsgEnemyAttack(u32 msg, HitSensor* pSender, HitSensor* pReceiver);
    virtual bool receiveOtherMsg(u32 msg, HitSensor* pSender, HitSensor* pReceiver);

    void exeDemoAppear();
    void exeFree();
    void exeFreeInvalid();
    void exeBindStart();
    void exeBindWait();
    void exeBindTurn();
    void exeBindClimbUp();
    void exeBindFallDown();
    void exeBindHandstandStart();
    void exeBindHandstandWait();
    void exeBindHandstandEnd();
    void exeBindHandstandTurn();

    bool tryJump(bool, f32);
    bool tryTurn();
    bool tryClimbUp();
    bool tryFallDown();
    bool tryHandstandTurn();
    bool isEnableTurn() const;
    void updateBindTrans();
    void calcGravityMtx(TPos3f*);
    void updateTopPos(f32);
    f32 getPoleSubPadStickX() const;
    f32 getPoleSubPadStickY() const;
    // single unknown function relating to animations here


    TVec3f mBasePos;              //  0x90
    TVec3f mTopPos;               //  0x9C
    f32 mPoleLength;              //  0xA8
    f32 _AC;                      //  0xAC : seemingly something related to handstands. Defaults to 170.0f
    bool mDisableHandstand;       //  0xB0
    bool mIsSquare;               //  0xB1
    bool mIs2way;                 //  0xB2
    bool mNoModel;                //  0xB3
    bool mInvertStick;            //  0xB4
    bool mUsePole9mCollision;     //  0xB5
    bool mIsPoleTreeA;            //  0xB6
    bool mIsPoleTreeB;            //  0xB7
    bool _B8;                     //  0xB8 : Only true if the current stage is TwisterTowerGalaxy, presumably due to the lava and poles section in star 1
    f32 mClimbCoord;              //  0xBC
    f32 mClimbSpeed;              //  0xC0
    LiveActor* mRider;            //  0xC4
    ActorCameraInfo* mCameraInfo; //  0xC8
    TVec3f mCenterPos;            //  0xCC
    TVec3f mSide;                 //  0xD8
    TVec3f mUp;                   //  0xE4
    TVec3f mFront;                //  0xF0
    TPos3f mPosMtx;               //  0xFC
    MtxPtr mTopMtx;               // 0x12C : Joint Matrix for joint "PoleTop"
    MtxPtr mBottomMtx;            // 0x130 : Joint Matrix for joint "PoleBottom"
    TMtx34f mBaseMtx;             // 0x134
};

namespace NrvPole {
    NERVE(PoleNrvDemoAppear);
    NERVE(PoleNrvFree);
    NERVE(PoleNrvFreeInvalid);
    NERVE(PoleNrvBindStart);
    NERVE(PoleNrvBindStartFast);
    NERVE(PoleNrvBindWait);
    NERVE(PoleNrvBindTurnLeft);
    NERVE(PoleNrvBindTurnRight);
    NERVE(PoleNrvBindTurnEnd);
    NERVE(PoleNrvBindClimbUp);
    NERVE(PoleNrvBindFallDown);
    NERVE(PoleNrvBindHandstandStart);
    NERVE(PoleNrvBindHandstandWait);
    NERVE(PoleNrvBindHandstandEnd);
    NERVE(PoleNrvBindHandstandTurn);
}