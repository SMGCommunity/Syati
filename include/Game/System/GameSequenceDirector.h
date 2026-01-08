#pragma once

#include "revolution/types.h"

class SystemDataTableHolder;
class GameSequenceProgress;
class SaveDataHandleSequence;
class StarPointerOnOffController;
class NWC24Messenger;

class GameSequenceDirector {
public:
	GameSequenceDirector(SystemDataTableHolder* pSystemDataTable);

	void initAfterResourceLoaded();
	void update();
	void draw() const;
	bool isInitializedGameDataHolder() const;

	// The remaining functions from SMG1 seem to have not been included in SMG2...

	GameSequenceProgress* mGameSequenceProgress; // 0x00
	u32 _4; // 0x04 : seems to be a pointer to a class that just manages a SystemDataTableHolder
	SaveDataHandleSequence* mSaveDataHandleSequence; // 0x08
	StarPointerOnOffController* mStarPointerOnOffController; // 0x0C
	NWC24Messenger* mNWC24Messenger; // 0x10
};