#pragma once

#include "AreaObj/AreaObj.h"

class WaterArea : public AreaObj
{
public:
	WaterArea(const char *);

	virtual ~WaterArea();
	virtual void init(const JMapInfoIter &);
};

class WaterAreaMgr : public AreaObjMgr
{
public:
	WaterAreaMgr(s32, const char *);

	virtual ~WaterAreaMgr();
};
