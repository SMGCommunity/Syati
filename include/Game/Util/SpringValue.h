#pragma once

#include "revolution.h"

class SpringValue {
public:
	SpringValue();
	SpringValue(f32, f32, f32, f32, f32);

	void setParam(f32, f32, f32, f32, f32);
	void update();
	void reset();
	// unknown function here

	f32 mRestValue;   // 0x00
	f32 mSpringValue; // 0x04
	f32 mAccelFactor; // 0x08
	f32 mDamping;     // 0x0C
	f32 mVelocity;    // 0x10
};
