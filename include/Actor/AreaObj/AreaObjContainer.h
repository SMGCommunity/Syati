#pragma once

#include "Actor/AreaObj/AreaObj.h"
#include "Util/AssignableArray.h"

struct ManagerEntry
{
    const char* pManagerName; // _0
	s32 mMaxAreas; // _4
    NameObj* (*mCreationFunc)(const char *); // _8
};

class AreaObjContainer : public NameObj
{
	AreaObjContainer(const char *);

	virtual ~AreaObjContainer(); 
	virtual void init(const JMapInfoIter &);
	
	// there is a jump to getManager before this
	AreaObjMgr* getManager(const char *) const;
	AreaObj* getAreaObj(const char *) const;
	bool isExistAreaObj(const char *) const;

    template<typename T>
    NameObj* createManager(s32, const char *);

	static ManagerEntry cCreateTable[95];

	MR::AssignableArray<AreaObjMgr*> mManagers; // _14
	s32 mNumManagers; // _1C
};

namespace MR
{
	AreaObjContainer* getAreaObjContainer();
};
