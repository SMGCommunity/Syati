#pragma once

#include "revolution/types.h"

class Polta;
class HitSensor;

class PoltaSensorCtrl {
public:
	PoltaSensorCtrl(Polta*);

	s32 getSensorCount() const; // Always returns 28... which is how many sensors this holds total
	void setScreamSensorSize(f32);
	void initSensor();
	bool isCoreSensor(const HitSensor*) const;
	bool isBodySensor(const HitSensor*) const;
	bool isLeftArmSensor(const HitSensor*) const;
	bool isRightArmSensor(const HitSensor*) const;
	bool isHeadSensor(const HitSensor*) const;
	bool isScreamSensor(const HitSensor*) const;

	Polta* mPoltaPtr;					// 0x00
	HitSensor* mScreamSensor;			// 0x04
	HitSensor* mHeadSensor;				// 0x08
	HitSensor** mCoreSensors;			// 0x0C  (1 element)
	HitSensor** mBodySensors;			// 0x10  (3 elements)
	HitSensor** mLeftArmSensors[11];	// 0x14  (11 elements)
	HitSensor** mRightArmSensors[11];	// 0x18  (11 elements)
};