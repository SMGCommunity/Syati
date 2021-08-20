#pragma once

#include "AreaObj/AreaObj.h"

class CumulativeTimerSwitchArea : public AreaObj
{
public:
	CumulativeTimerSwitchArea(const char *pName);

	virtual ~CumulativeTimerSwitchArea();
	virtual void init(const JMapInfoIter &rIter);
	virtual void movement();
};
