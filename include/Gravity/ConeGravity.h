#pragma once

#include "Gravity/PlanetGravity.h"

class ConeGravity : public PlanetGravity
{
	ConeGravity();

	virtual void updateMtx(const TPositionMtx &);
	virtual bool calcOwnGravityVector(TVec3f *, f32 *, const TVec3f &);

	void setLocalMatrix(const TPositionMtx &);
	void setEnableBottom(bool);
	void setTopCutRate(f32);

	Mtx mLocalMtx; // _28
	Mtx mGlobalMtx; // _58
	f32 _88; // unused
	f32 _8C; // unused
	f32 _90; // unused
	bool mEnableBottom; // _94
	f32 mTopCutRate; // _98
};
