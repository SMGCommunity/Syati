#pragma once

#include "Game/AreaObj/AreaObj.h"

/* FINISHED */

class ZoneLightID;

class LightAreaHolder : public AreaObjMgr {
public:
	LightAreaHolder(s32 size, const char *pName);

	virtual ~LightAreaHolder();
	virtual void initAfterPlacement();

	void tryFindLightID(const TVec3f &rPosition, ZoneLightID *pLightID) const;
};
