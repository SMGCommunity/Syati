#pragma once

#include "JSystem/J3DGraphBase/J3DModel.h"
#include "JSystem/J3DGraphBase/J3DModelData.h"

class J3DModelX
{
public:
	J3DModelX(J3DModelData*, u32, u32);

	void directDraw(J3DModel*);
	void setDynamicDL(u8 *, u32);
};