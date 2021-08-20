#pragma once

#include "Enemy/StateController/WalkerStateParam.h"
#include "LiveActor/LiveActor.h"

class WalkerStateFunction
{
public:
	static bool isInSightPlayer(const LiveActor *pActor, const TVec3f &, const WalkerStateParam *pParam);
	static void calcPassiveMovement(LiveActor *pActor, const WalkerStateParam *pParam);
};
