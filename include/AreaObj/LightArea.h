#pragma once

#include "AreaObj/AreaObj.h"
#include "Map/Light/LightZoneDataHolder.h"

class LightArea : public AreaObj
{
	LightArea(const char *);

	virtual ~LightArea();
	virtual void init(const JMapInfoIter &);
	virtual const char* getManagerName();

	bool _48;
};

class LightAreaHolder : public AreaObjMgr
{
	LightAreaHolder(s32, const char *);

	virtual ~LightAreaHolder();
	virtual void initAfterPlacement();

	void tryFindLightID(const TVec3f &, ZoneLightID *) const;
};
