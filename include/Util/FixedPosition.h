#pragma once

#include "kamek.h"
#include "JGeometry/TVec3.h"

class LiveActor;

class FixedPosition
{
public:
	FixedPosition(const LiveActor *, const char *, const TVec3f &, const TVec3f &);
	FixedPosition(const LiveActor *, const TVec3f &, const TVec3f &);
	FixedPosition(Mtx4 *, const char *, const TVec3f &, const TVec3f &);
	FixedPosition(const LiveActor *, const char *, const LiveActor *);

	void init(Mtx4 *, const TVec3f &, const TVec3f &);
	void calc();
	void setBaseMtx(Mtx4 *);
	void setLocalTrans(const TVec3f &);
	void copyTrans(TVec3f *) const;
	void copyRotate(TVec3f *) const;

	Mtx4* mBaseMtx; // _0
	TVec3f mLocalTrans; // _4
	TVec3f _10;
	Mtx _1C;
	bool mNormalizeScale; // _4C
};
