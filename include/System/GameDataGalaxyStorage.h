#pragma once

#include "syati.h"
#include "System/GalaxyStatusAccessor.h"

class GameDataSomeScenarioAccessor {
public:
	GameDataSomeScenarioAccessor();

	void resetAllData();

	s8 mMissNum; // _0
	s32 mBestTime; // _4
	u8 mFlag; // _8
};

class GameDataSomeGalaxyStorage {
public:
	GameDataSomeGalaxyStorage(const GalaxyStatusAccessor &rGalaxyStatusAccessor);

	void resetAllData();
	s32 getPowerStarNumOwned() const;

	const char* mGalaxyName; // _0
	u8 mScenarioNum; // _4
	u8 mGalaxyState; // _5
	u8 mFlag; // _6
	GameDataSomeScenarioAccessor* mScenarioAccessors; // _8
};
