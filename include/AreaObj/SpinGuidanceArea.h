#pragma once

#include "AreaObj/AreaObj.h"

class SpinGuidanceArea : public AreaObj
{
public:
	SpinGuidanceArea(const char *);

	virtual ~SpinGuidanceArea();
	virtual void init(const JMapInfoIter &);
};
