#pragma once

#include "Enemy/AnimScaleController.h"
#include "LiveActor/LiveActor.h"
#include "LiveActor/State/ActorStateBase.h"

class WalkerStateBindStarPointer : public ActorStateBaseInterface
{
public:
    WalkerStateBindStarPointer(LiveActor *, AnimScaleController *);

    virtual ~WalkerStateBindStarPointer();
    virtual void appear();
    virtual void kill();

    bool tryStartPointBind() const;
    void exeBind();

    u8 _8[0x1C-0x8];
};
