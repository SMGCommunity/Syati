#pragma once

#include "revolution.h"

namespace JGeometry {
    void negateInternal(const float *rSrc, float *rDest);

    template<typename T>
    class TVec2 {
    public:
        /* Constructors */
        inline TVec2() { }
        TVec2(const TVec2<T> &);

        TVec2(T _x, T _y) {
            this->x = _x;
            this->y = _y;
        };

        /* Getters and setters */
        void set(const TVec2<T> &);

        void set(T, T);

        void setMin(const TVec2<T> &);
        void setMax(const TVec2<T> &);

        void zero();

        /* Arithmetic and algebraic operations */
        void sub(const TVec2<T> &);

        T distance(const TVec2<T> &) const;
        T length() const;
        T squared(const TVec2<T> &) const;
        T dot(const TVec2<T> &) const;

        /* Operators */
        void operator=(const TVec2<T> &);
        TVec2<T> operator+(const TVec2<T> &) const;
        TVec2<T> operator-(const TVec2<T> &) const;
        TVec2<T> operator*(T) const;

        T x;
        T y;
    };

    template <typename T>
    class TVec3 {
    public:
        /* Constructors */
        inline TVec3() { }

        TVec3(const TVec3<T> &rOther) {
            this->x = rOther.x;
            this->y = rOther.y;
            this->z = rOther.z;
        }

        TVec3(const Vec &rOther) {
            this->x = rOther.x;
            this->y = rOther.y;
            this->z = rOther.z;
        }

        TVec3(T val) {
            this->x = val;
            this->y = val;
            this->z = val;
        }

        TVec3(T _x, T _y, T _z) {
            this->x = _x;
            this->y = _y;
            this->z = _z;
        }

        /* Getters and setters */
        void set(const Vec &rOther) {
            this-> x = rOther.x;
            this->y = rOther.y;
            this->z = rOther.z;
        }

        void set(const TVec3<T> &rOther) {
            this->x = rOther.x;
            this->y = rOther.y;
            this->z = rOther.z;
        }

        void set(T _x, T _y, T _z) {
            this->x = _x;
            this->y = _y;
            this->z = _z;
        }

        void setAll(T val) {
            this->x = val;
            this->y = val;
            this->z = val;
        }

        void zero() {
            this->x = 0;
            this->y = 0;
            this->z = 0;
        }

        void negate() {
            this->x = -this->x;
            this->y = -this->y;
            this->z = -this->z;
        }

        void negate(const TVec3<T> &);

        /* Arithmetic and algebraic operations */
        void add(const TVec3<T> &rOther) {
            this->x += rOther.x;
            this->y += rOther.y;
            this->z += rOther.z;
        }
    
        void add(const TVec3<T> &, const TVec3<T> &);

        void sub(const TVec3<T> &rOther) {
            this->x -= rOther.x;
            this->y -= rOther.y;
            this->z -= rOther.z;
        }

        void sub(const TVec3<T> &, const TVec3<T> &);
    
        void mul(const TVec3<T> &rOther) {
            this->x *= rOther.x;
            this->y *= rOther.y;
            this->z *= rOther.z;
        }

        void mul(const TVec3<T> &, const TVec3<T> &);

        void div(const TVec3<T> &rOther) {
            this->x /= rOther.x;
            this->y /= rOther.y;
            this->z /= rOther.z;
        }

        void scale(T scalar) {
            this->x *= scalar;
            this->y *= scalar;
            this->z *= scalar;
        }

        void scale(T, const TVec3<T> &);

        void setLength(float);
        void setLength(const TVec3<float> &, float);

        // Implementation from HeadPenguin.
        // Works properly 99% of the time
        // Intended to be the Cubic function that was included in SMG1, but excluded from SMG2 since nothing used it
        void cubic(const TVec3<T>& rv1, const TVec3<T>& rv2, const TVec3<T>& rv3, const TVec3<T>& rv4, T a) {
            TVec3 StackA = rv3 * (a * a * a - a * a);
            TVec3 StackB = rv2 * (a + a * a * a - 2 * a * a);
            TVec3 StackC = rv1 * (1 + 2 * a * a * a - 3 * a * a);
            TVec3 StackD = rv4 * (3 * a * a - 2 * a * a * a);
            TVec3 Stack = StackA + StackB + StackC + StackD;

            set(Stack);
        }

        T squared() const {
            return (this->x * this->x) + (this->y * this->y) + (this->z * this->z);
        }

        inline T squaredInline() const
        {
            #ifdef __MWERKS__
            register const JGeometry::TVec3<f32>* this_vec = this;
            register f32 _xy, _z;

            __asm {
                psq_l _xy, 0(this_vec), 0, 0
                lfs _z, 8(this_vec)
                ps_mul _xy, _xy, _xy
                ps_madd _z, _z, _z, _xy
                ps_sum0 _z, _z, _xy, _xy
            };
            return _z;
            #endif
        }

        T squared(const TVec3<T> &) const;
        T dot(const TVec3<T> &) const;
        T normalize(const TVec3<T> &);

        T angle(const TVec3<T> &) const;

        /* Checkers */
        bool epsilonEquals(const TVec3<T> &, T) const;
        bool isZero() const;

        /* Operators */
        void operator=(const TVec3<T> &rhs) {
            this->x = rhs.x;
            this->y = rhs.y;
            this->z = rhs.z;
        }

        TVec3<T> operator+(const TVec3<T>& rhs) const {
            TVec3<T> ret = *this;
            ret.x = ret.x + rhs.x;
            ret.y = ret.y + rhs.y;
            ret.z = ret.z + rhs.z;
            return ret;
        }

        TVec3<T>& operator+=(const TVec3<T>& rhs) {
            this->x = this->x + rhs.x;
            this->y = this->y + rhs.y;
            this->z = this->z + rhs.z;
            return *this;
        }

        TVec3<T> operator-(const TVec3<T> &rhs) const {
            TVec3<T> ret = *this;
            ret.x = ret.x - rhs.x;
            ret.y = ret.y - rhs.y;
            ret.z = ret.z - rhs.z;
            return ret;
        }

        TVec3<T> operator-() const {
            TVec3<T> ret = *this;
            ret.negate();
            return ret;
        }

        TVec3<T>& operator-=(const TVec3<T>& rhs) {
            this->x = this->x - rhs.x;
            this->y = this->y - rhs.y;
            this->z = this->z - rhs.z;
            return *this;
        }

        TVec3<T> operator*(T val) const {
            TVec3<T> ret = *this;
            ret.scale(val);
            return ret;
        }

        TVec3<T>& operator*=(const TVec3<T>& rhs) {
            this->x = this->x * rhs.x;
            this->y = this->y * rhs.y;
            this->z = this->z * rhs.z;
            return *this;
        }

        TVec3<T> operator/(T rhs) const {
            TVec3<T> ret = *this;
            ret.x = ret.x / rhs;
            ret.y = ret.y / rhs;
            ret.z = ret.z / rhs;
            return ret;
        }

        TVec3<T>& operator/=(const TVec3<T>& rhs) {
            this->x = this->x / rhs.x;
            this->y = this->y / rhs.y;
            this->z = this->z / rhs.z;
            return *this;
        }

        bool operator==(const TVec3<T> &) const;

        inline operator Vec*() { return (Vec*)&x; }
        inline operator const Vec*() const { return (Vec*)&x; }
        inline operator f32*() { return (f32*)&x; }
        inline operator const f32*() const { return (f32*)&x; }

        T x;
        T y;
        T z;
    };

    template<typename T>
    class TVec4 : public TVec3<T> {
    public:
        /* Constructors */
        inline TVec4() { }

        template<typename T>
        TVec4(T, T, T, T);

        /* Getters and setters */
        template<typename T>
        void set(const TVec4<T> &);

        template<typename T>
        void set(T, T, T, T);

        T w;
    };
};

typedef JGeometry::TVec2<float> TVec2f;
typedef JGeometry::TVec3<signed char> TVec3c;
typedef JGeometry::TVec3<float> TVec3f;
typedef JGeometry::TVec3<short> TVec3s;
typedef JGeometry::TVec4<float> TVec4f;
