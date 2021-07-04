#pragma once

#include "Gravity/PlanetGravity.h"

class ParallelGravity : public PlanetGravity
{
public:
	ParallelGravity();

	virtual void updateMtx(const TPositionMtx &);
	virtual bool calcOwnGravityVector(TVec3f *, f32 *, const TVec3f &);
};
