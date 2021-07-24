#pragma once

#include "NameObj/NameObj.h"

class NameObjHolder
{
public:
    NameObjHolder(s32);

    void add(NameObj *);
    void suspendAllObj();
    void resumeAllObj();
    void syncWithFlags();
    void callMethodAllObj();
    void clearArray();
    NameObj* find(const char *);

    NameObj** mObjs; // _0
    s32 _4;
    s32 mNumObjs; // _8
    u8 _C[0x4C - 0x0C];
    s32 _4C;
};
