#pragma once

#include "AreaObj/AreaObj.h"

class SpinSwitchArea : public AreaObj
{
public:
	SpinSwitchArea(const char *);

	virtual ~SpinSwitchArea();
	virtual void init(const JMapInfoIter &);
	virtual void movement();
};
