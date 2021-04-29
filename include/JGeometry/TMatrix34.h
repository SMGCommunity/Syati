#pragma once

#include "JGeometry/TVec3.h"
#include "kamek.h"

namespace JGeometry
{
    template<typename T>
    class TMatrix34
    {
    public:
        void identity();
        void mult(const TVec3f &, TVec3f &);
        void concat(const T &);
    
        T val[3][4];
    };
    
    template<typename T>
    class SMatrix34C
    {
    public:
        /* empty */
    };
};

typedef JGeometry::SMatrix34C<f32> SMatrix34Cf;
typedef JGeometry::TMatrix34<SMatrix34Cf> TMatrix34Cf;