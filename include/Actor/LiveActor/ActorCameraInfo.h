#pragma once
#include "JMap/JMapInfoIter.h"

class ActorCameraInfo
{
public:
	ActorCameraInfo(const JMapInfoIter &);
	ActorCameraInfo(u32, u32);

	u32 mCameraSetID; //_0
	u32 mPlacedZoneID; //_4
};