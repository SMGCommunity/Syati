#pragma once

#include "Game/Enemy/BegomanBase.h"
#include "Game/LiveActor/ActorCameraInfo.h"

class BegomanBaby;

class BegomanSpring : public BegomanBase {
public:
    BegomanSpring(const char* pName);

    virtual ~BegomanSpring();
    virtual void init(const JMapInfoIter& rIter);
    virtual void calcAnim();
    virtual void appear();
    virtual void makeActorAppeared();
    virtual void kill();
    virtual void control();
    virtual void attackSensor(HitSensor* pSender, HitSensor* pReceiver);
    virtual bool receiveMsgPush(HitSensor* pSender, HitSensor* pReceiver);
    virtual bool receiveMsgPlayerAttack(u32 msg, HitSensor* pSender, HitSensor* pReceiver);
    virtual bool receiveMsgEnemyAttack(u32 msg, HitSensor* pSender, HitSensor* pReceiver);
    virtual bool receiveOtherMsg(u32 msg, HitSensor* pSender, HitSensor* pReceiver);
    virtual u32 getKind() const;
    virtual bool onTouchElectric(const TVec3f&, const TVec3f&);
    virtual bool setNerveReturn();
    virtual Nerve* getNerveWait();

    s32 _10C;
    TMtx34f _110;
    s32 _140;
    TMtx34f _144;
    TVec3f _174;
    u8 _180;
    ActorCameraInfo* _184;
    s32 _188; // mHitRecoverTime?
    u8 _18C;
    s32 _190;
    BegomanBaby* _194; // mChild
    TVec3f _198;
};
