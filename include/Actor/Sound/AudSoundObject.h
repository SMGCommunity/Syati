#pragma once

#include "Actor/Sound/JAUSoundObject.h"

class AudSoundObject : public JAUSoundObject
{
public:
    u8 _18[0x48-0x18];

    void addToSoundObjHolder();
    void setTrans(TVec3f *);
};