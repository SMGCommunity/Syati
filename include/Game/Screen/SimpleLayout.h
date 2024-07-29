#pragma once

#include "revolution.h"
#include "Game/Screen/LayoutActor.h"

class SimpleLayout : public LayoutActor {
public:
	SimpleLayout(const char* FileName, const char* ManagerName, u32, s32);

	~SimpleLayout();
};