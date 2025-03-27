#pragma once

#include "revolution.h"
#include "Game/LiveActor/LiveActor.h"
#include "Game/LiveActor/FlashingCtrl.h"

class BenefitItemObj : public LiveActor {
public:
    BenefitItemObj(const char *pName, const char *pModelName);
    virtual void init(const JMapInfoIter &rIter);
    virtual void appear();
    // sub_80276CD0, sub_80276CF0, sub_80276D10
    virtual void initAfterPlacement();
    virtual void makeActorAppeared();
    virtual void control();
    virtual bool receiveMsgPlayerAttack(u32 msg, HitSensor *pSender, HitSensor *pReceiver);
    virtual bool receiveOtherMsg(u32 msg, HitSensor *pSender, HitSensor *pReceiver);
    virtual void calcAndSetBaseMtx();

    void doRotateY();
    void initEscape();
    void appearGround();
    void appearThrowUp();
    void appearThrowUpQuestionBox();
    // sub_80277450, sub_802774A0, sub_80277530, sub_80277590, sub_802775A0
    void exeWait();
    void exeShoot();
    void exeAppearGround();
    // sub_80277A20, sub_80277B10, sub_80277B90, sub_80277C50, sub_80277DC0, 
    void exeEscape();
    // sub_802782A0, sub_80278300, sub_802784F0, sub_80278590

    u32 _90;
    // Padding? Struct?
    u32 _94;
    u32 _98;
    u32 _9C;
    // 
    f32 _A0;
    f32 _A4;
    f32 _A8;
    TVec3f _AC;                     // Related to appearThrowUp
    u16 _B8;
    u16 _BA;
    u16 _BC;
    u16 _BE;
    u16 _C0;
    TVec3f _C4;                     // Related to doEscape
    TVec3f _D0;                     // Related to doEscape
    bool _DC;
    u8 mAppearanceType;             // _DD
    u8 mEscapeType;                 // _DE
    u8 mRotateType;                 // _DF
    u8 mShadowType;                 // _E0
    u32 _E4;
    TVec3f _E8;
    bool _F4;
    bool mAppearBehavior;           // _F5
    bool mIsDead;                   // _F6
    bool mIsActive;                 // _F7
    bool _F8;
    bool mIsAppearanceCamera;       // _F9
    bool _FA;
    bool _FB;
    f32 mPathSpeed;                 // _FC
    f32 _100;                       // mRotateY?
    Mtx _104;
    const char *mModelName;         // _134
    FlashingCtrl *_138;
    ActorCameraInfo *mCameraInfo;   // _13C
    u32 _140;
    u32 mAppearTimer;               // _144
    f32 _148;
    f32 _14C;
    f32 _150;
};

namespace NrvBenefitItemObj {
    NERVE(HostTypeNrvWait);
    NERVE(HostTypeNrvShoot);
    NERVE(HostTypeNrvCatch);
    NERVE(HostTypeNrvAppearGround);
    NERVE(HostTypeNrvPreEscape);
    NERVE(HostTypeNrvEscape);
};