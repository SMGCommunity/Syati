#pragma once

#include "NameObj/NameObj.h"

class MovementOnOffGroupHolder : public NameObj
{
public:
	MovementOnOffGroupHolder(const char *);

	virtual ~MovementOnOffGroupHolder();

	NameObj* mObjs[32]; // _14
	s32 mNumObjs; // _94
};
