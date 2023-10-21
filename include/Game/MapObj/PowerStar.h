#pragma once

#include "revolution.h"
#include "Game/LiveActor/LiveActor.h"
#include "Game/LiveActor/ModelObj.h"
#include "Game/LiveActor/ActorCameraInfo.h"
#include "Game/MapObj/PowerStarAppearPoint.h"

class PowerStar : public LiveActor {
public:
    PowerStar(const char *pName);

    virtual bool receiveOtherMsg(u32 msg, HitSensor *pSender, HitSensor *pReceiver);

    void initMapToolInfo(const JMapInfoIter &rIter);
    void initShadow(const JMapInfoIter& rIter);

    void calcAppearDemoRiseTrans(TVec3f *pDest, f32 yOffset) const;
    void applyAppearDemoRiseTrans(const TVec3f &rDest, f32 yOffset, f32);

    void processWait(f32);
    bool isEndAppearDemo() const;

    s32 mPowerStarId; //_90
    bool mUseAppearDemo; //_94
    TVec3f _98; //_98
    TVec3f _A4; //_A4
    TVec3f _B0; //_B0
    TMtx34f _BC; //_BC
    TMtx34f _EC; //_EC
    ModelObj* mDemoStar; //_11C
    DemoObj* mDemoPeach; //_120 PeachAnim
    DemoObj* mDemoTicoBaby; //_124 TicoBabyAnim
    DemoObj* mDemoSupportTico; //_128 SupportTico
    bool mIsAppearDemo; //_12C
    bool _12D; //_12D
    s32 mColor; //_130
    bool mIsGrand; //_134
    bool mIsGreen; //_135
    bool mAppearanceGravity; //_136 ObjArg1
    bool mIgnoreGravity; //_137 ObjArg2
    bool mAppearNearest; //_138 ObjArg4
    ActorCameraInfo* mActorCameraInfo; //_13C
    PowerStarAppearPoint* mNearestAppearPoint; //_140
    TMtx34f _144; //_144
    bool mHasSwitchAwake; //_174
};
