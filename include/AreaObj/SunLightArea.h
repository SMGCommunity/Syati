#pragma once

#include "AreaObj/AreaObj.h"

class SunLightArea : public AreaObj
{
public:
	SunLightArea(const char *);

	virtual ~SunLightArea();
	virtual const char* getManagerName() const;
};
