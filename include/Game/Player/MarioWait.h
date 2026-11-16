#pragma once

#include "revolution.h"

class MarioWait : public MarioState {
public:
    MarioWait(MarioActor *);
    virtual bool start();
    virtual bool update();
    virtual bool close();

    u16 _12;
    u16 _14;
    u16 _16;
};