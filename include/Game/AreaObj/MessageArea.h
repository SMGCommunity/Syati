#pragma once

#include "Game/AreaObj/AreaObj.h"

/* FINISHED */

class MessageArea : public AreaObj {
public:
	MessageArea(const char *pName);

	virtual ~MessageArea();
	virtual void init(const JMapInfoIter &rIter);

	/* 0x48 */ s32 mZoneID;
};
