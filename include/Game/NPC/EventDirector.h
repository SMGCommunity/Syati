#pragma once

#include "revolution.h"
#include "JSystem.h"

class EventFunction {
public:
	static bool isStartCometEvent(const char *);
};

namespace MR {
	void appearEventPowerStar(const char*, s32, const TVec3f *, bool, bool, bool);
	s32 getEventPowerStarID(const char *);
	void pauseCometTimer();
	void resumeCometTimer();
	void showCometTimer();
	void hideCometTimer();
	void addCometTimer(s32);
	void decCometTimer(s32);
};
