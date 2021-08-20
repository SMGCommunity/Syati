#pragma once

#include "AreaObj/AreaObj.h"
#include "Map/Light/LightZoneDataHolder.h"

class LightArea : public AreaObj
{
	LightArea(const char *pName);

	virtual ~LightArea();
	virtual void init(const JMapInfoIter &rIter);
	virtual const char* getManagerName();

	bool _48;
};

class LightAreaHolder : public AreaObjMgr
{
	LightAreaHolder(s32 size, const char *pName);

	virtual ~LightAreaHolder();
	virtual void initAfterPlacement();

	void tryFindLightID(const TVec3f &, ZoneLightID *) const;
};
