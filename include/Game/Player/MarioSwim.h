#pragma once

#include "Game/Player.h"
#include "Game/Player/MarioState.h"

class MarioSwim : public MarioState {
public:
    MarioSwim(MarioActor *);

    virtual void init();
    virtual bool start();
    virtual bool update();
    virtual bool notice();
    virtual void draw3D() const;
    virtual bool passRing(const HitSensor *);
    virtual f32 getBlurOffset() const;
    virtual f32 getStickY() const;
    
    void jet();
    void resetJet();
    void dropJet(bool);
    void startJet(u32);
    void pushedByWaterWall();
    void hitPoly(u8, const TVec3f &, HitSensor *);
    void hitWall(const TVec3f &, HitSensor *);
    void incOxygen();
    void decOxygen(u16);

    void incLife();
    void addVelocity(const TVec3f &);
    void addVelocity(const TVec3f &, f32);
    void updateTilt();
    f32 getWaterEdgeDist() const;

    u8 _0[0x208];
};