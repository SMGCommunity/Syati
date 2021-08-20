#pragma once

#include "AreaObj/AreaObj.h"

class SpinSwitchArea : public AreaObj
{
public:
	SpinSwitchArea(const char *pName);

	virtual ~SpinSwitchArea();
	virtual void init(const JMapInfoIter &rIter);
	virtual void movement();
};
