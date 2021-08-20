#pragma once

#include "JSystem/JGeometry/TVec3.h"
#include "JSystem/JGeometry/TQuat4.h"

namespace JGeometry
{
    template<typename T>
    class SMatrix34C
    {
    public:
        void set(const SMatrix34C<T> &);
        void set(const T* [4]);
        void set(T, T, T, T, T, T, T, T, T, T, T, T);

        T val[3][4];
    };

    template<class T>
    class TMatrix34 : public T
    {
    public:
        void concat(const T &);
        void concat(const T &, const T &);

        void identity();
        void scale(f32);

        void mult(const TVec3f &, TVec3f &) const;
        void multTranspose(const TVec3f &, const TVec3f &) const;
    };

    template<typename T>
    class TPosition3 : public T
    {
    public:
        TPosition3();

        void makeRotate(const TVec3f &, f32);
        void zeroTrans();
        void getTrans(TVec3f &) const;
        void setTrans(const TVec3f &);
    };

    template<typename T>
    class TRotation3 : public T
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

        void setRotate(const TVec3f &, const TVec3f &);
        void setRotate(const TVec3f &, f32);
        void setXDir(const TVec3f &);
        void setYDir(const TVec3f &);
        void setZDir(const TVec3f &);
        void setXYZDir(const TVec3f &, const TVec3f &, const TVec3f &) const;
        void setEulerY(f32);
        void setQuat(const TQuat4f &);
        void setScale(f32, f32, f32);
    };
};

typedef JGeometry::SMatrix34C<f32> SMatrix34Cf;
typedef JGeometry::TMatrix34<SMatrix34Cf> TMatrix34f;
typedef JGeometry::TPosition3<TMatrix34f> TPositionMtx;
typedef JGeometry::TRotation3<TMatrix34f> TRotationMtx;
