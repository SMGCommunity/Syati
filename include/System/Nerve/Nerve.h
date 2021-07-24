#pragma once

#include "syati.h"

class Spine;

class Nerve
{
public:
    virtual void execute(Spine *) const = 0;
    virtual void executeOnEnd(Spine *) const
    {
        return;
    }
};
