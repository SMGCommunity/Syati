#pragma once

#include "syati.h"

class GameDataSomeGalaxyStorage;

class GameDataFunction {
public:
	static GameDataSomeGalaxyStorage* makeSomeGalaxyStorage(const char *pStageName);

	static s32 calcCurrentPowerStarNum();
};
