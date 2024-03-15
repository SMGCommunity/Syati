#pragma once

#include "revolution.h"
#include "JSystem.h"

class ActorCameraInfo {
public:
	ActorCameraInfo(const JMapInfoIter &);
	ActorCameraInfo(s32, s32);

	s32 mCameraSetID; //_0
	s32 mPlacedZoneID; //_4
};
