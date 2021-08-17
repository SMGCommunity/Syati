#pragma once

#include "Gravity/PlanetGravity.h"

class ParallelGravity : public PlanetGravity
{
public:
	enum RANGE_TYPE
	{
		SPHERE = 0,
		BOX = 1,
		CYLINDER = 2
	};

	enum DISTANCE_CALC_TYPE
	{
		DistanceCalcType_Default = -1,
		DistanceCalcType_0 = 0,
		DistanceCalcType_1 = 1,
		DistanceCalcType_2 = 2
	};

	ParallelGravity();

	virtual void updateMtx(const TPositionMtx &);
	virtual bool calcOwnGravityVector(TVec3f *, f32 *, const TVec3f &);

	void setPlane(const TVec3f &, const TVec3f &);
	void setRangeBox(const TPositionMtx &);
	void setRangeCylinder(f32, f32);
	void setRangeType(RANGE_TYPE);
	void setBaseDistance(f32);
	void setDistanceCalcType(DISTANCE_CALC_TYPE);
	bool isInSphereRange(const TVec3f &, f32 *) const;
	bool isInBoxRange(const TVec3f &, f32 *) const;
	bool isInCylinderRange(const TVec3f &, f32 *) const;
	bool inInRange(const TVec3f &, f32 *) const;

	Mtx _28;
	Mtx _58;
	f32 _88;
	f32 _8C;
	f32 _90;
	TVec3f _94;
	TVec3f _A0;
	TVec3f _AC;
	f32 _B8;
	f32 _BC;
	f32 _C0;
	f32 mRangeCylinder1; // _C4
	f32 mRangeCylinder2; // _C8
	f32 mBaseDistance; // _CC
	RANGE_TYPE mRangeType; // _D0
	DISTANCE_CALC_TYPE mDistanceCalcType; // _D4
};
