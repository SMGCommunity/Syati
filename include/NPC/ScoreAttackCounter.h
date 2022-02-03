#pragma once

#include "syati.h"

class LiveActor;

class ScoreAttackFunction {
	void score100Points(const LiveActor *pHost);
	void score10PointsMultiply(const LiveActor *pHost, s32 factor);
	void score10PointsMultiply(s32 factor);
	void score1000Points(const LiveActor *pHost);
	void score300Points(const LiveActor *pHost);
};
