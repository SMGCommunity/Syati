#pragma once

#include "syati-light.h"

class J3DModelX
{
public:
	J3DModelX(J3DModelData*, u32, u32);

	void directDraw(J3DModel*);
};