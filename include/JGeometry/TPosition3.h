#pragma once

#include "JGeometry/TMatrix34.h"

namespace JGeometry
{
    template<typename T>
    class TPosition3
    {
    public:
        void setTrans(const TVec3f &);
        void setTrans(f32, f32, f32);
        
        T val;
    };
};

typedef JGeometry::TPosition3<TMatrix34Cf> TPositionMtx;
