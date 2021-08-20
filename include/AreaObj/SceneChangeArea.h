#pragma once

#include "AreaObj/AreaObj.h"

class SceneChangeArea : public AreaObj
{
public:
	SceneChangeArea(const char *pName);

	virtual ~SceneChangeArea();
	virtual void init(const JMapInfoIter &rIter);
	virtual void movement();
};
