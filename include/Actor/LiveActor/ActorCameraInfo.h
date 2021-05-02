#pragma once
#include "JMap/JMapInfoIter.h"

class ActorCameraInfo
{
public:
	ActorCameraInfo(const JMapInfoIter &);
	ActorCameraInfo(u32, u32);

	u32 CameraSetID;
	u32 placedZoneID;
};