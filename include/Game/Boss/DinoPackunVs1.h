#pragma once

#include "revolution.h"
#include "Game/Boss/DinoPackunSequencer.h"

class DinoPackunVs1 : public DinoPackunSequencer {
public:
	DinoPackunVs1(const char*);

	~DinoPackunVs1();
	virtual void start();
	virtual void init();
	virtual bool isUseEggShell() const;
	virtual s32 getVsCount() const;

	NerveExecutor* mDemoExecutor; // DinoPackunDemo
	NerveExecutor* mBattleEggExecutor; // DinoPackunBattleEgg
	NerveExecutor* mBattleLv1Executor; // DinoPackunBattleVs1Lv1
	NerveExecutor* mBattleLv2Executor; // DinoPackunBattleVs1Lv2
};

namespace NrvDinoPackunVs1 {
	NERVE(DinoPackunVs1NrvWaitStart);
	NERVE(DinoPackunVs1NrvOpeningDemo);
	NERVE(DinoPackunVs1NrvBattleEgg);
	NERVE(DinoPackunVs1NrvCryDemo);
	NERVE(DinoPackunVs1NrvBattleLv1);
	NERVE(DinoPackunVs1NrvAngryDemo);
	NERVE(DinoPackunVs1NrvBattleLv2);
	NERVE(DinoPackunVs1NrvBattleLv3);
	NERVE(DinoPackunVs1NrvDownDemo);
}