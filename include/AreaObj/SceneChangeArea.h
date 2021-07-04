#pragma once

#include "AreaObj/AreaObj.h"

class SceneChangeArea : public AreaObj
{
public:
	SceneChangeArea(const char *);

	virtual ~SceneChangeArea();
	virtual void init(const JMapInfoIter &);
	virtual void movement();
};
