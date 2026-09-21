#pragma once

#include "revolution.h"
#include "Game/AreaObj/AreaObj.h"

/* FINISHED */

class SwitchArea : public AreaObj {
public:
	SwitchArea(const char *pName);

	virtual ~SwitchArea();
	virtual void init(const JMapInfoIter &rIter);
	virtual void movement();
	virtual const char* getManagerName() const;

	void onSwitchA();
	bool isUpdate() const;
	bool checkPlayerDrillRush() const;

	/* 0x48 */ s32 mRiddleSound;
	/* 0x4c */ bool mRiddlePlayed;
};
