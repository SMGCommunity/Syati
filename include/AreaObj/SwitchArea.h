#pragma once

#include "AreaObj/AreaObj.h"

class SwitchArea : public AreaObj
{
public:
	SwitchArea(const char *);

	virtual ~SwitchArea();
	virtual void init(const JMapInfoIter &);
	virtual void movement();
	virtual const char* getManagerName() const;

	void onSwitchA();
	bool isUpdate() const;
	bool checkPlayerDrillRush() const;

	s32 mRiddleSound; // _48
	bool mRiddlePlayed; // _4C
};
