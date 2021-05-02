#pragma once

#include "Actor/LiveActor/LiveActor.h"
#include "MapObj/MapObjActor.h"

class SimpleMapObj : public MapObjActor
{
public:
	SimpleMapObj(const char *);

	virtual void init(const JMapInfoIter &);
};