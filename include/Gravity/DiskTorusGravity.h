#pragma once

#include "Gravity/PlanetGravity.h"

class DiskTorusGravity : public PlanetGravity
{
public:
	DiskTorusGravity();

	virtual void updateMtx(const TPositionMtx &);
	virtual bool calcOwnGravityVector(TVec3f *, f32 *, const TVec3f &);

	void setPosition(const TVec3f &);
	void setDirection(const TVec3f &);
	void setRadius(f32);
	void setDiskRadius(f32);
	void setEdgeType(s32);
	void setBothSide(bool);

	TVec3f mLocalPos; // _28
	TVec3f _34;
	TVec3f mLocalDir; // _40
	TVec3f _4C;
	f32 mRadius; // _58
	f32 _5C;
	f32 mDiskRadius; // _60
	s32 mEdgeType; // _64
	bool mBothSide; // _68
};
