#pragma once

#include "Game/AreaObj/AreaObj.h"

class LightArea : public AreaObj {
public:
	LightArea(const char *pName);

	virtual ~LightArea();
	virtual void init(const JMapInfoIter &rIter);
	virtual const char* getManagerName();

	bool _48;
};
