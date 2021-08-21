#pragma once

#include "LiveActor/LiveActor.h"

class MessageSensorHolder : public LiveActor
{
public:
	MessageSensorHolder(const char *pName);

	virtual ~MessageSensorHolder();
	virtual void init(const JMapInfoIter &rIter);
};
