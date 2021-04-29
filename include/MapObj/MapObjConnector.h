#pragma once

#include "Actor/LiveActor/LiveActor.h"

class MapObjConnector
{
public:
	MapObjConnector(LiveActor *);

	bool attachToUnder();
	bool attachToBack();
	bool attach(const TVec3f &);
	// unknown function at 802CC510

	LiveActor* mActor;
	s32 _4; // appears to be a pointer
	Mtx mMtx;
};
