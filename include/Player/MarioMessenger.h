#pragma once

#include "NameObj/NameObj.h"
#include "LiveActor/Sensor/HitSensor.h"

class MarioMessenger : public NameObj
{
	MarioMessenger(HitSensor *);

	virtual ~MarioMessenger();
	virtual void movement();

	void addRequest(HitSensor *, u32);

	HitSensor* mSensor; // _14
	HitSensor** _18;
	HitSensor** _1C;
	u32 _20;
};
