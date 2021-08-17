#pragma once

#include "AreaObj/AreaObj.h"

class ShadowColorArea : public AreaObj
{
public:
	ShadowColorArea(const char *);

	virtual ~ShadowColorArea();
	virtual void init(const JMapInfoIter &);
};
