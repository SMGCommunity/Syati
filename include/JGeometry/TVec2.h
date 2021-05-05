#pragma once

namespace JGeometry
{
    template<typename T>
    class TVec2
    {
    public:
        TVec2();

        T x; // _0
        T y; // _4
    };
};

typedef JGeometry::TVec2<f32> TVec2f;
