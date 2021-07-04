#pragma once

#include "JGeometry/TPosition3.h"
#include "NameObj/NameObj.h"

class PlanetGravity
{
public:
	PlanetGravity();

	virtual void updateMtx(const TPositionMtx &);
	virtual bool calcOwnGravityVector(TVec3f *, f32 *, const TVec3f &);

	void calcGravity(TVec3f *, const TVec3f &) const;
	void calcGravityFromMassPosition(TVec3f *, f32 *, const TVec3f &, const TVec3f &) const;

	bool isInRangeSquare(f32) const;
	bool isInRangeDistance(f32) const;

	void setPriority(s32);
	void updateIdentityMtx();

	f32 _4;
	f32 _8;
	s32 mPriority; // _C
	s32 _10;
	NameObj* mFollowHost; // _14
	s32 _18;
	s32 _1C;
	bool mIsActive; // _20
	u8 _21;
	bool mIsZero; // _22
	u8 _23;
	u8 _24;
	u8 _25;
};
