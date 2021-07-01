#pragma once

#include "kamek.h"

void JMAVECScaleAdd(const Vec *, const Vec *, Vec *, f32);
void JMAVECLerp(const Vec *, const Vec *, Vec *, f32);

namespace JMath
{
	void gekko_ps_copy12(void *, void const *);
	void gekko_ps_copy16(void *, void const *);
};
