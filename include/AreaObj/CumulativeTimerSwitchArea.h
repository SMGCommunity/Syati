#pragma once

#include "AreaObj/AreaObj.h"

class CumulativeTimerSwitchArea : public AreaObj
{
public:
	CumulativeTimerSwitchArea(const char *);

	virtual ~CumulativeTimerSwitchArea();
	virtual void init(const JMapInfoIter &);
	virtual void movement();
};
