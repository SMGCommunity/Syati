#pragma once

#include "Gravity/PlanetGravity.h"

class CubeGravity : public PlanetGravity
{
	CubeGravity();

	virtual void updateMtx(const TPositionMtx &);
	virtual bool calcOwnGravityVector(TVec3f *, f32 *, const TVec3f &);

	void setCube(const TPositionMtx &);
	void calcGravityArea(const TVec3f &) const;
	void calcFaceGravity(const TVec3f &, s32, TVec3f *, f32 *) const;
	void calcEdgeGravity(const TVec3f &, s32, TVec3f *, f32 *) const;
	void calcCornerGravity(const TVec3f &, s32, TVec3f *, f32 *) const;

	Mtx mLocalMtx; // _28
	Mtx mGlobalMtx; // _58
	f32 _88;
	f32 _8C;
	f32 _90;
	u8 mFlags; // _94, always 63
};
