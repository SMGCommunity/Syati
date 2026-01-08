#pragma once

#include "Game/System/NerveExecutor.h"

class GameSequenceSystemStart;
class GameSequenceTitle;
class GameSequenceInGame;
class GameSequenceEnding;
class AlreadyDoneFlagInGalaxy; // -> Game/System/AlreadyDoneFlagInGalaxy.h

class GameSequenceProgress : public NerveExecutor {
public:
	GameSequenceProgress();

	virtual ~GameSequenceProgress();

	void update();
	void draw();
	void setTitle();
	void setInGame();
	void setEnding();

	// More unknown functions


	GameSequenceSystemStart* _8; // 0x08
	GameSequenceTitle* _C; // 0x0c
	GameSequenceInGame* _10; // 0x10
	GameSequenceEnding* _14; // 0x14
	AlreadyDoneFlagInGalaxy* mAlreadyDoneFlags; // 0x18
	u8 _1C; // 0x1C possibly a bool?
	u8 _1D; // 0x1D possibly a bool?
};