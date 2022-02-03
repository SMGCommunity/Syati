#pragma once

#include "syati.h"
#include "JGeometry.h"

class EventFunction
{
public:
	static bool isStartCometEvent(const char *);
};

namespace MR {
	void appearEventPowerStar(const char*, s32, const TVec3f *, bool, bool, s32);
};
