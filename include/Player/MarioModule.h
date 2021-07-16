#pragma once

#include "kamek.h"
#include "JGeometry/TVec3.h"

class MarioActor;

class MarioModule
{
public:
	virtual f32 getStickY() const;
	virtual void addVelocity(const TVec3f &) const;
	virtual void addVelocity(const TVec3f &, f32);

	MarioActor* mMarioActor; // _4
};
