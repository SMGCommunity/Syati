#pragma once

#include "Gravity/PlanetGravity.h"

class PointGravity : public PlanetGravity
{
public:
	PointGravity();

	virtual void updateMtx(const TPositionMtx &);
	virtual void calcOwnGravityVector(TVec3f *, f32 *, const TVec3f &) const;

	TVec3f _28; // unused
	TVec3f _2C;
};
