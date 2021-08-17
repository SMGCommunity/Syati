#pragma once

#include "NameObj/NameObjListExecutor.h"

class SceneNameObjListExecutor : public NameObjListExecutor
{
public:
	inline SceneNameObjListExecutor() : NameObjListExecutor {}

	virtual ~SceneNameObjListExecutor();
	virtual void initMovementList();
	virtual void initCalcAnimList();
	virtual void initCalcViewAndEntryList();
	virtual void initDrawList();
};
