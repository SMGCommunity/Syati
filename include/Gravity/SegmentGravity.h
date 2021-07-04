#pragma once

#include "Gravity/PlanetGravity.h"

class SegmentGravity : PlanetGravity
{
public:
	SegmentGravity();

	virtual void updateMtx(const TPositionMtx &);
	virtual void calcOwnGravityVector(TVec3f *, f32 *, const TVec3f &) const;

	void setGravityPoint(u32, const TVec3f &);
	void setSideVector(const TVec3f &);
	void setValidSideDegree(f32);
	void setEdgeValid(u32, bool);
	void updateLocalParam();

	TVec3f mGravityPoint1; // _28
	TVec3f mGravityPoint2; // _34
	TVec3f _40;
	TVec3f _4C;
	TVec3f mSideVec; // _58
	TVec3f _64;
	TVec3f _70;
	TVec3f _7C;
	f32 _88;
	f32 mSideDegree; // _8C
	f32 _90;
	f32 _94;
	f32 _98;
	u8 mEdge; // _9C
};
