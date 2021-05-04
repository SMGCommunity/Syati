#pragma once

namespace JGeometry
{
    template<typename T>
    class TRotation3
    {
    public:
        void getEulerXYZ(TVec3f &) const;

        T _0[3][4];
    };
};

typedef JGeometry::TRotation3<TMatrix34Cf> TRotationMtx;