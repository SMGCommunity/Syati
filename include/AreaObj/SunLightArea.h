#pragma once

#include "AreaObj/AreaObj.h"

class SunLightArea : public AreaObj
{
public:
	SunLightArea(const char *pName);

	virtual ~SunLightArea();
	virtual const char* getManagerName() const;
};
