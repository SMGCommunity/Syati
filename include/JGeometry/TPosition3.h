#pragma once

#include "JGeometry/TMatrix34.h"

namespace JGeometry
{
    template<typename T>
    class TPosition3
    {
    public:
        T _0[3][4];
    };
};

typedef JGeometry::TPosition3<TMatrix34Cf> TPositionMtx;