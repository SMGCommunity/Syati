#pragma once

#include "revolution.h"
#include "Game/Screen/LayoutActor.h"

class SimpleLayout : public LayoutActor {
public:
	SimpleLayout(const char* pName, const char* pArchive, u32, int drawType);

	~SimpleLayout();
};