#pragma once

#include "Actor/LiveActor/LiveActor.h"

class MapObjConnector
{
public:
	MapObjConnector(LiveActor *);

	bool attachToUnder();
	bool attachToBack();
	bool attach(const JGeometry::TVec3<f32> &);
	// unknown function at 802CC510

	LiveActor* mActor;
	s32 _4; // appears to be a pointer
	Mtx mMtx;
};
