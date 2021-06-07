#pragma once

#include "JGeometry/TQuat4.h"
#include "JGeometry/TMatrix34.h"

namespace JGeometry
{
    template<typename T>
    class TRotation3
    {
    public:
        void identity33();
        void mult33(TVec3f &) const;
        void mult33(TVec3f &, TVec3f &) const;

        void getXDir(TVec3f &) const;
        void getYDir(TVec3f &) const;
        void getZDir(TVec3f &) const;
        void getXYZDir(TVec3f &, TVec3f &, TVec3f &) const;
        void getEuler(TVec3f &) const;
        void getEulerXYZ(TVec3f &) const;
        void getQuat(TQuat4f &) const;
        void getScale(TVec3f &) const;

        // void setRotate(const TVec3f &, const TVec3f &); does this still exist in SMG2 ?
        void setRotate(const TVec3f &, f32);
        void setXDir(const TVec3f &);
        void setYDir(const TVec3f &);
        void setZDir(const TVec3f &);
        // void setXDir(f32, f32, f32); does this still exist in SMG2 ?
        // void setYDir(f32, f32, f32); does this still exist in SMG2 ?
        // void setZDir(f32, f32, f32); does this still exist in SMG2 ?
        void setXYZDir(const TVec3f &, const TVec3f &, const TVec3f &) const;
        void setEulerY(f32);
        // void setEulerZ(f32); does this still exist in SMG2?
        void setQuat(const TQuat4f &);
        void setScale(f32, f32, f32);

        f32 val[3][4];
    };
};

typedef JGeometry::TRotation3<TMatrix34Cf> TRotationMtx;
