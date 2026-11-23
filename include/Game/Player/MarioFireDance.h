#pragma once

#include "revolution.h"
#include "Game/Player/MarioState.h"

class MarioFireDance : public MarioState {
public:
    MarioFireDance(MarioActor *);
    virtual bool start();
    virtual bool close();
    virtual bool update();
    void impact();
    void impactEffect();

    TVec3f _14;
    f32 _20;
    u8 _24;
    u16 _26;
    u8 _28;
    u8 _29;
    u16 _2A;
    u16 _2C;
};