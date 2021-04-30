#pragma once

#include "Actor/NameObj/NameObj.h"
#include "Map/Switch/StageSwitch.h"
#include "MapObj/ChipBase.h"

struct ChipStruct
{
	ChipBase* mChip;
	bool mIsCollected;
};

class ChipGroup : public NameObj
{
public:
	ChipGroup(const char *, s32);

	virtual ~ChipGroup();
	virtual void init(const JMapInfoIter &);
	virtual void movement();

	void updateUIRange();
	void registerChip(ChipBase *);
	void noticeGet(ChipBase *);
	void noticeEndCompleteDemo();
	void receiveAppearRequest();
	s32 getGotCount();
	bool isComplete();

	ChipStruct mChips[5];
	StageSwitchCtrl* mStageSwitchCtrl;
	TVec3f mTranslate;
	s32 mCollectedChips;
	s32 mNumChips;
	s32 mArg0;
	s32 mType;
	s32 mArg1;
	s32 _60;
	f32 _64;
	f32 mArg2;
	bool _6C;
	s32 _70;
	bool mUseSwAppear;
	bool mAppeared;
};

class YellowChipGroup : public ChipGroup
{
public:
	YellowChipGroup(const char *);

	virtual ~YellowChipGroup();
};
