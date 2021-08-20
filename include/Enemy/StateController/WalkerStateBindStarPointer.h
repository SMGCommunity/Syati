#pragma once

#include "Enemy/StateController/AnimScaleController.h"
#include "LiveActor/LiveActor.h"
#include "LiveActor/State/ActorStateBase.h"

class WalkerStateBindStarPointer : public ActorStateBaseInterface
{
public:
    WalkerStateBindStarPointer(LiveActor *pActor, AnimScaleController *pAnimScaleCtrl);

    virtual ~WalkerStateBindStarPointer();
    virtual void appear();
    virtual void kill();

    bool tryStartPointBind() const;
    void exeBind();

    LiveActor* mActor; // _C
    AnimScaleController* mAnimScaleCtrl; // _10
    s32 mNoBindStepCount; // _14
    bool mUsePointerTouchEffect; // _18
};

namespace NrvWalkerStateBindStarPointer
{
    NERVE(WalkerStateBindStarPointerNrvBind);
};
