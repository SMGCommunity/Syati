#pragma once

#include "Gravity/PlanetGravity.h"

class WireGravity : public PlanetGravity
{
public:
	WireGravity();

	virtual void calcOwnGravityVector(TVec3f *, f32 *, const TVec3f &) const;

	void setPointListSize(u32);
	void addPoint(const TVec3f &);

	u32* mPoints; // _28
	u32 mNumPointsMax; // _2C
	s32 mNumPoints; // _30
};
