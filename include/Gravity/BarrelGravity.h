#pragma once

#include "Gravity/PlanetGravity.h"

class BarrelGravity : public PlanetGravity
{
public:
	BarrelGravity();

	virtual void updateMtx(const TPositionMtx &);
	virtual bool calcOwnGravityVector(TVec3f *, f32 *, const TVec3f &);

	void setLocalPosition(const TVec3f &);
	void setUpDirection(const TVec3f &);
	void setRadius(f32);
	// two unknown functions for setting Arg1 and Arg2

	TVec3f mLocalPos; // _28
	TVec3f _34;
	TVec3f mUpDir; // _40
	TVec3f _4C;
	f32 mRadius; // _58
	f32 _5C;
	f32 _60; // Obj_arg1
	f32 _64; // Obj_arg2
};
