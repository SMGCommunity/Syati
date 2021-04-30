#pragma once

#include "Actor/LiveActor/LiveActor.h"
#include "JGeometry/TVec3.h"

#define CHIP_BLUE 0
#define CHIP_YELLOW 1

class PartsModel;

class ChipBase : public LiveActor
{
public:
	ChipBase(const char *, s32, const char *);

	virtual void init(const JMapInfoIter &);
	virtual void initAfterPlacement();
	virtual void makeActorAppeared();
	virtual void makeActorDead();
	virtual void control();
	virtual u32 receiveOtherMsg(u32, HitSensor *, HitSensor *);

	void initModel(const JMapInfoIter &);
	void initSensor();
	void initShadow(const JMapInfoIter &);
	void initJMapParam(const JMapInfoIter &);
	void deactive();
	void setGroupID(s32);
	void setHost(LiveActor *);
	void appearWait();
	void appearFlashing();
	void requestGet(HitSensor *, HitSensor *);
	void requestShow();
	void requestHide();

	void exeFlashing();

	void exeGot();
	bool isGettable() const;

	bool isNeedBubble(const JMapInfoIter &);

	u32* mFlashingCtrl; // 90
	u32* mRailMover; // 94
	PartsModel* mBubble; // 98
	const char* mModelName; // 9C
	NameObj* mHost; // A0
	TVec3f mClippingRange; // A4
	s32 mGroup; // B0
	s32 mType; // B4
	s32 _B8;
	u8 _BC;
	bool mArg2;
};
