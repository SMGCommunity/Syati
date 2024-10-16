#pragma once

#include "syati.h"

struct unk_8022CAE0 {
    f32 _0;
    f32 _4;
    f32 _8;
    f32 _C;
    f32 _10;
    f32 _14;
    f32 _18;
};

class SupportTico : public LiveActor {
public:
    SupportTico(const char *);
    virtual ~SupportTico();
    virtual void makeActorAppeared();
    virtual void makeActorDead();
    virtual void init(const JMapInfoIter &);
    virtual void control();
    virtual void calcAndSetBaseMtx();
    virtual void attackSensor(HitSensor *, HitSensor *);
    virtual bool receiveOtherMsg(u32, HitSensor *, HitSensor *);

    void exeDisappear();
    void tryAttachToTarget(const LiveActor *);
    void offControl();
    void onControl();
    void setFollowPlayerYDir();
    void resetFollowPlayerYDir();
    void requestHide();
    void requestShow();

    unk_8022CAE0 *_90;
    LiveActorGroup *mRequestGroup; // _94
    u32 _98;
    u32 _9C;
    u32 _A0;
    u32 _A4;
    u32 _A8;
    u32 _AC;
    u32 _B0;
    f32 _B4;
    u8 _B8;
    u8 _B9;
    u8 _BA;
    u8 _BB;
    u8 _BC;
};

namespace NrvSupportTico {
    NERVE(SupportTicoNrvBehavior);
    NERVE(SupportTicoNrvDisappear);
}