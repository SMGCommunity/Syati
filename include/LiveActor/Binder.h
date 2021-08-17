#pragma once

#include "syati.h"
#include "JGeometry/TVec3.h"

class Binder
{
public:
    Binder(Mtx *, const TVec3f *, const TVec3f *, f32, f32, u64);

    static void bind(TVec3f &, Binder *, const TVec3f &);
    void clear();

    u8 _0[0x1F0];
};