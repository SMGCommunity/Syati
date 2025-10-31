#pragma once

#include "Game/LiveActor/ModelObj.h"

class PoltaArm : public ModelObj {
public:
	PoltaArm(const char* pName, const char* pModelName, MtxPtr pMtx);

	virtual ~PoltaArm();
	virtual void init(const JMapInfoIter& rIter);
	virtual void appear();
	virtual void makeActorDead();
	virtual void control();

	void initPartsModel();
	void exeDamage();
	void exeBreak();
	void exeBreakBody();
	void exeRepair();
	void exeBroken();
	bool isEnableHitSensor() const;
	bool isEnableAttack() const;
	bool isBroken() const;
	void start();
	bool requestBreakBody();
	bool requestDamage();
	bool requestStartControll(); // Possible typo from Nintendo
	bool requestControlled(const char*);
	void appearBreakModel();

	ModelObj* mFormationModel; // 0x94
	ModelObj* mBreakModel;     // 0x98
	TPos3f _9C;                // 0x9C
	s32 _CC;                   // 0xCC
	s32 _D0;                   // 0xD0
	s32 mBrokenCounter;        // 0xD4 - Counts the frames since the hand was last broken by the player
	s32 _D8;                   // 0xD8 - Unused? Seems to block mBrokenCounter from incrementing...
	bool mIsLeftArm;           // 0xDC - If true, this hand is the Left Hand. If False, this hand is the Right Hand.
};