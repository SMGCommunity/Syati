#pragma once

#include "Game/AreaObj/AreaObj.h"

/* FINISHED */

class MorphSwitchArea : public AreaObj {
public:
	MorphSwitchArea(const char *pName);

	virtual ~MorphSwitchArea();
	virtual void init(const JMapInfoIter &rIter);
	virtual void movement();
	
	bool checkCondition() const;

	/* 0x48 */ s32 mCondition;
};
