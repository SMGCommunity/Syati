#pragma once

#include "syati-light.h"
#include "Game/LiveActor/LiveActor.h"

class RushEndInfo {
public:
	RushEndInfo(LiveActor*, u32, const TVec3f&, bool, u32);

	u32 _0;
	u32 _4;
	TVec3f _8;
	bool _14;
	u32 _18;
	u32 _1C;
	u32 _20;
};