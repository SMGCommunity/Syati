#pragma once

#include "AreaObj/AreaObj.h"

class YoshiEatGuidanceArea : public AreaObj
{
public:
	YoshiEatGuidanceArea(const char *);

	virtual ~YoshiEatGuidanceArea();
	virtual void init(const JMapInfoIter &);
	virtual void movement();
};
