#pragma once

#include "revolution\types.h"

namespace nw4r {
    namespace math {

        f32 FSelect(f32 cond, f32 ifPos, f32 ifNeg) 
        {
            f32 ret = (cond >= 0) ? ifPos: ifNeg;
            return ret;
        }
    };
};