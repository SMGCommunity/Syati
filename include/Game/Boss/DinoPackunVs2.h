#pragma once

#include "revolution.h"
#include "Game/Boss/DinoPackunSequencer.h"

class DinoPackunFireHolder;
class DinoPackunTrackFireHolder;

class DinoPackunVs2 : public DinoPackunSequencer {
public:
	DinoPackunVs2(const char*);

	~DinoPackunVs2();
	virtual void start();
	virtual void init();
	virtual bool isUseEggShell() const;
	virtual s32 getVsCount() const;

	NerveExecutor* mDemoExecutor; // DinoPackunDemo
	NerveExecutor* mBattleEggExecutor; // DinoPackunBattleEggVs2
	NerveExecutor* mBattleLv1Executor; // DinoPackunBattleVs2Lv1
	DinoPackunTrackFireHolder* mTrackFireHolder; // 0x1C
	DinoPackunFireHolder* mFireHolder; // 0x20
};

namespace NrvDinoPackunVs2 {
	NERVE(DinoPackunVs2NrvWaitStart);
	NERVE(DinoPackunVs2NrvOpeningDemo);
	NERVE(DinoPackunVs2NrvBattleEgg);
	NERVE(DinoPackunVs2NrvCryDemo);
	NERVE(DinoPackunVs2NrvBattleLv1);
	NERVE(DinoPackunVs2NrvAngryDemo);
	NERVE(DinoPackunVs2NrvBattleLv2);
	NERVE(DinoPackunVs2NrvBattleLv3);
	NERVE(DinoPackunVs2NrvDownDemo);
}