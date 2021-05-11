#pragma once

#include "Actor/Nerve/NerveExecutor.h"

class LiveActor;
class AnimScaleController;

class WalkerStateBindStarPointer : public NerveExecutor
{
public:
    WalkerStateBindStarPointer(LiveActor *, AnimScaleController *);

    virtual ~WalkerStateBindStarPointer();
    virtual void appear();
    virtual void kill();

    bool tryStartPointBind() const;

    u8 _8[0x1C-0x8];
};