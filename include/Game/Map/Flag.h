#pragma once

#include "Game/LiveActor/LiveActor.h"

class Flag : public LiveActor {
    Flag(const char*);

    virtual ~Flag();
    virtual void init(const JMapInfoIter&);
    virtual void movement();
    virtual void draw() const;
    virtual void appear();

    // TODO: Members
};