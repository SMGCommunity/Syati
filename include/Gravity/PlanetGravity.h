#pragma once

#include "JGeometry/TPosition3.h"
#include "NameObj/NameObj.h"

// Gravity vector calculation flags
#define GRAVITY_TYPE_NORMAL 1
#define GRAVITY_TYPE_SHADOW 2
#define GRAVITY_TYPE_MAGNET 4
#define GRAVITY_TYPE_MARIO_LAUNCHER 8

// Gravity power types
#define GRAVITY_POWER_LIGHT 0
#define GRAVITY_POWER_NORMAL 1
#define GRAVITY_POWER_HEAVY 2

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

	f32 mRange; // _4
	f32 mDistant; // _8
	s32 mPriority; // _C
	s32 mGravityId; // _10
	NameObj* mFollowHost; // _14
	u32 mGravityType; // _18
	u32 mGravityPower; // _1C
	bool _20;
	bool mIsInverse; // _21
	bool mIsZero; // _22
	bool _23;
	bool mIsRegistered; // _24
	bool mIsActive; // _25
};
