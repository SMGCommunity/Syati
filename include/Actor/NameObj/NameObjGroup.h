#pragma once

#include "Actor/NameObj/NameObj.h"

class NameObjGroup : public NameObj
{
public:
	NameObjGroup(const char *, int);	

	virtual ~NameObjGroup();

    void registerObj(NameObj *);

    void pauseOffAll() const;
    void initObjArray(s32);

    s32 mMaxObjs; // _14
    s32 mNumObjs; // _18
    NameObj** mObjs; // _1C
};
