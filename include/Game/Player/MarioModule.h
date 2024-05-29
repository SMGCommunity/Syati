#pragma once

#include "revolution.h"
#include "JSystem.h"

class MarioActor;

class MarioModule {
public:
	f32 getStickY() const;
	void addVelocity(const TVec3f &) const;
	void addVelocity(const TVec3f &, f32);
    void changeAnimation(const char *, const char *);

	MarioActor* mMarioActor; // _4
};
