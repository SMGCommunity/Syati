#pragma once

#include "System/Nerve/NerveExecutor.h"

class ActorStateBaseInterface : public NerveExecutor
{
public:
    virtual void init();
    virtual void appear();
    virtual void kill();
    virtual bool update();
    virtual void control();

    bool mIsDead; // _8
};
