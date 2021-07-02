#pragma once

#include "kamek.h"
#include "NameObj/NameObj.h"
#include "os.h"

class MyFirstActor : public NameObj
{
public:
	// actor constructor
	MyFirstActor(const char *pActorName) : NameObj(pActorName)
	{
		
	}
	
	// actor initialization, reads from BCSV entry
	virtual void init(const JMapInfoIter &rIter)
	{
		OSReport("Init!\n");
	}
};