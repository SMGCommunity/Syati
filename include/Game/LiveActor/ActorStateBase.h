#pragma once

#include "revolution.h"
#include "Game/System/NerveExecutor.h"

/* FINISHED */

class ActorStateBaseInterface : public NerveExecutor {
public:
    inline ActorStateBaseInterface(const char* pName) : NerveExecutor(pName) {

    }

    virtual void init();
    virtual void appear();
    virtual void kill();
    virtual bool update();
    virtual void control();

    bool mIsDead; // _8
};

template<typename T>
class ActorStateBase : public ActorStateBaseInterface {
public:
    inline ActorStateBase(const char* pName) : ActorStateBaseInterface(pName) {

    }

    virtual ~ActorStateBase();
};
