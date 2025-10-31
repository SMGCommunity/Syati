#pragma once

#include "JSystem/JGeometry/TVec.h"
#include "Game/LiveActor/LiveActor.h"

class BombTeresa : public LiveActor {
public:
	BombTeresa(const char*);






	bool appearNormal(const TVec3f&, const TVec3f&);
	bool appearShadow(const TVec3f&, const TVec3f&); // USAGE WARNING - Upon spawning, will try to locate the floor below it. Gets eternally stuck in limbo if no floor is found.
};