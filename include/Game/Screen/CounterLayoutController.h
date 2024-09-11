#pragma once

#include "revolution.h"
#include "Game/Screen/LayoutActor.h"
#include "Game/Screen/CoinCounter.h"
#include "Game/Screen/StarPieceCounter.h"
#include "Game/Screen/PlayerLeft.h"
#include "Game/Screen/StarCounter.h"
#include "Game/Screen/MarioMeter.h"
#include "Game/Screen/CometMedalCounter.h"

class MarioMeter;

class CounterLayoutController : public LayoutActor {
public:
	CounterLayoutController();
	virtual void init(const JMapInfoIter& rIter);
	virtual void appear();
	virtual void kill();
	virtual void control();
	void forceAppear();
	void setHPMeter(MarioMeter*);
	void requestedTicoEat(bool);
	bool isInvalidSystemStateShowCounter();
	static bool isWaitToDisappearCounter(const LayoutActor* pLayout);
	void showAllLayout();
	void hideAllLayout();
	bool isHiddenOrWaitAllLayout() const;
	bool isPlayerMoving();
	void appearAllCounterWithoutStar();
	void killAllCoounter();
	void tryEndTicoEatStarPiece();
	void exePlayerMoving();
	void exePlayerNotMoving();

	s32 _2C;
	s32 _30;
	CoinCounter* mCoinCounter; // 0x34
	StarPieceCounter* mStarPieceCounter; // 0x38
	PlayerLeft* mPlayerLeft; // 0x3C
	StarCounter* mStarCounter; // 0x40
	MarioMeter* mMarioMeter; // 0x44
	CometMedalCounter* mCometMedalCounter; // 0x48
};
