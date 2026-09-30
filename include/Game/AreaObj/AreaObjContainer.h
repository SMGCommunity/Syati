#pragma once

#include "Game/NameObj/NameObj.h"
#include "Game/Util/Array.h"
#include "JSystem/JGeometry.h"

/* FINISHED */

class AreaObj;
class AreaObjMgr;

typedef AreaObjMgr* (*ManagerCreatorFuncPtr)(s32, const char*);

struct ManagerEntry {
    /* 0x0 */ const char* pManagerName;
	/* 0x4 */ s32 mMaxAreas;
    /* 0x8 */ ManagerCreatorFuncPtr mCreateFunc;
};

class AreaObjContainer : public NameObj {
public:
	AreaObjContainer(const char *pName);

	virtual ~AreaObjContainer(); 
	virtual void init(const JMapInfoIter &rIter);
	
	AreaObjMgr* getManager2(const char *pName) const;
	AreaObjMgr* getManager(const char *pName) const;
	AreaObj* getAreaObj(const char *pName, const TVec3f &rPosition) const;
	bool isExistAreaObj(const char *pName) const;

    template<typename T>
    static AreaObjMgr* createManager(s32 size, const char *pName);

	static ManagerEntry cCreateTable[95];

	/* 0x14 */ MR::AssignableArray<AreaObjMgr*> mManagers;
	/* 0x1C */ u32 mNumManagers;
};

namespace MR {
	AreaObjContainer* getAreaObjContainer();
}
