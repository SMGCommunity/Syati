#pragma once

#include "syati.h"

class Spine;

class Nerve
{
public:
    virtual void execute(Spine *) const = 0;
    virtual void executeOnEnd(Spine *) const;
};

#define NERVE(name)\
class name : public Nerve\
{\
    public:\
    virtual void execute(Spine *) const;\
    static name sInstance;\
};\

#define ENDABLE_NERVE(name)\
class name : public Nerve\
{\
public:\
    virtual void execute(Spine *) const;\
    virtual void executeOnEnd(Spine *) const;\
    static name sInstance;\
};\
