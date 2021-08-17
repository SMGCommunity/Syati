#pragma once

#include "Gravity/PlanetGravity.h"

class DiskGravity : public PlanetGravity
{
public:
	DiskGravity();

	virtual void updateMtx(const TPositionMtx &);
	virtual bool calcOwnGravityVector(TVec3f *, f32 *, const TVec3f &);

	void setLocalPosition(const TVec3f &);
	void setLocalDirection(const TVec3f &);
	void setSideDirection(const TVec3f &);
	void setRadius(f32);
	void setValidDegree(f32);
	void setBothSide(bool);
	void setEnableEdgeGravity(bool);
	void updateLocalParam();

	TVec3f mLocalPos; // _28
	TVec3f _34;
	TVec3f mLocalDir; // _40
	TVec3f _4C;
	TVec3f mSideDir; // _58
	TVec3f _64;
	TVec3f _70;
	f32 mRadius; // _7C
	f32 _80;
	f32 mDegree; // _84
	f32 _88;
	bool mBothSide; // _8C
	bool mEnableEdge; // _8D
};
