#pragma once

#include "JSystem/JGeometry/TVec.h"
#include "JSystem/JGeometry/TQuat.h"

namespace JGeometry {
    template<typename T>
    struct SMatrix34C {
    public:
        void set(const float (*)[4]);
        void set(const SMatrix34C<T> &rSrc);
        void set(T rxx, T ryx, T rzx, T tx, T rxy, T ryy, T rzy, T ty, T rxz, T ryz, T rzz, T tz);

        void scale(T);

        inline Mtx* toMtx() {
            return (Mtx*)mMtx;
        }

        inline const Mtx* toCMtx() const {
            return (const Mtx*)mMtx;
        }

        inline MtxPtr toMtxPtr() {
            return (MtxPtr)mMtx;
        }

        T mMtx[3][4];
    };

    template<typename T>
    struct TMatrix34 : public T {
    public:
        void identity();
        void concat(const T &rSrcA, const T &rSrcB);
        void concat(const T &rSrc);
        void invert(const TMatrix34<T> &rDest);

        void mult(const TVec3f &rSrc, TVec3f &rDest) const;

        void multTranspose(const TVec3f &a1, const TVec3f &a2) const;
        
    };

    template<class T>
    struct TRotation3 : public T {
    public:
        void identity33();

        void getXDir(TVec3f &rDest) const  {
            rDest.set<f32>(mMtx[0][0], mMtx[1][0], mMtx[2][0]);
        };

        void getYDir(TVec3f &rDest) const  {
            rDest.set<f32>(mMtx[0][1], mMtx[1][1], mMtx[2][1]);
        };

        void getZDir(TVec3f &rDest) const  {
            rDest.set<f32>(mMtx[0][2], mMtx[1][2], mMtx[2][2]);
        };

        void getXYZDir(TVec3f &rDestX, TVec3f &rDestY, TVec3f &rDestZ) const;
        void setXDir(const TVec3f &rSrc);
        void setXDir(f32 x, f32 y, f32 z);
        void setYDir(const TVec3f &rSrc);
        void setYDir(f32 x, f32 y, f32 z);
        void setZDir(const TVec3f &rSrc);
        void setZDir(f32 x, f32 y, f32 z);
        void setXYZDir(const TVec3f &rSrcX, const TVec3f &rSrcY, const TVec3f &rSrcZ);

        void getEuler(TVec3f &rDest) const;
        void getEulerXYZ(TVec3f &rDest) const;
        void setEulerY(f32 val);
        void setEulerZ(f32 val);

        void getQuat(TQuat4f &rDest) const;
        void setQuat(const TQuat4f &rSrc);

        void getScale(TVec3f &rDest) const;
        void setScale(const TVec3f &rSrc);

        void setRotate(const TVec3f &, const TVec3f &);
        void setRotate(const TVec3f &, f32);

        void mult33(TVec3f &) const;
        void mult33(const TVec3f &, TVec3f &) const;

        inline void getXDirInline(TVec3f &rDest) const {
            f32 z = mMtx[2][0];
            f32 y = mMtx[1][0];
            f32 x = mMtx[0][0];
            rDest.set(x, y, z);
        }
    };

    template<class T>
    struct TPosition3 : public TRotation3<T> {
    public:
        void getTrans(TVec3f &rDest) const;
        void setTrans(const TVec3f &rSrc);
        void setTrans(f32 x, f32 y, f32 z);
        void zeroTrans();

        void makeRotate(const TVec3f &, f32);
        void makeQuat(const TQuat4f &rSrc);
        void setPositionFromLookAt(const TPosition3<T> &rLookAt);
        void setQT(const TQuat4f &rSrcQuat, const TVec3f &rSrcTrans);

        inline void getTransInline(TVec3f &rDest) const {
            f32 z = mMtx[2][3];
            f32 y = mMtx[1][3];
            f32 x = mMtx[0][3];
            rDest.set(x, y, z);
        }
    };
}

typedef JGeometry::SMatrix34C<f32> TSMtxf;
typedef JGeometry::TMatrix34<TSMtxf> TMtx34f;
typedef JGeometry::TRotation3<TMtx34f> TRot3f;
typedef JGeometry::TPosition3<TMtx34f> TPos3f;