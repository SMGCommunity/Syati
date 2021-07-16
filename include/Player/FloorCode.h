#pragma once

#include "Map/Collision/Triangle.h"

class FloorCode
{
public:
	FloorCode();

	s32 getCode(const Triangle *);
};
