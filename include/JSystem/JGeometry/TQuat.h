#pragma once

#include "JSystem/JGeometry/TVec.h"

namespace JGeometry {
    template<typename T>
    struct TQuat4 : public TVec4<T> {
    };

    template<>
    struct TQuat4<f32> : public TVec4<f32> {
        /* Constructors */
        inline TQuat4() { }

        template<typename T>
        TQuat4(T, T, T, T);

        /* Getters and setters */
        void getXDir(const TVec3<f32> &) const;
        void getYDir(const TVec3<f32> &) const;
        void getZDir(const TVec3<f32> &) const;

        void getEuler(const TVec3<f32> &) const;
        void setEuler(f32, f32, f32);

        void setRotate(const TVec3<f32> &, f32);
        void setRotate(const TVec3<f32> &, const TVec3<f32> &);
        void setRotate(const TVec3<f32> &, const TVec3<f32> &, f32);

        /* Arithmetic and algebraic operations */
        void transform(TVec3<f32> &) const;
        void transform(const TVec3<f32> &, const TVec3<f32> &) const;

        void rotate(const TVec3<f32> &) const;

        void normalize();
        void normalize(const TQuat4<f32> &);
        void slerp(const TQuat4<f32> &, f32);

        // This version of Slerp was not included in SMG2's assembly due to only being used by Megaleg. We know it exists though.
        void slerp(const TQuat4<f32>& a1, const TQuat4<f32>& a2, f32 a3) {
            this->x = a1.x;
            this->y = a1.y;
            this->z = a1.z;
            this->w = a1.w;
            this->slerp(a2, a3);
        }

        /* Operators */
        void operator=(const TQuat4<f32> &);

        inline operator Quaternion*() { return (Quaternion*)&x; }
        inline operator const Quaternion*() const { return (Quaternion*)&x; }
    };
};

typedef JGeometry::TQuat4<f32> TQuat4f;
