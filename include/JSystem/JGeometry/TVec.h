#pragma once

#include "revolution.h"

namespace JGeometry {
    void negateInternal(const f32 *rSrc, f32 *rDest);

    template<typename T>
    struct TVec2<T> {
        /* Constructors */
        inline TVec2() { }
        TVec2(const TVec2<T> &);

        template<typename T>
        TVec2(T, T);

        /* Getters and setters */
        template<typename T>
        void set(const TVec2<T> &);

        template<typename T>
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

    template<template T>
    class TVec3<T> {
        /* Constructors */
        inline TVec3() { }

        TVec3(const TVec3<T> &rOther) {
            x = rOther.x;
            y = rOther.y;
            z = rOther.z;
        }

        TVec3(const Vec &rOther) {
            x = rOther.x;
            y = rOther.y;
            z = rOther.z;
        }

        TVec3(T val) {
            x = val;
            y = val;
            z = val;
        }

        template<typename T>
        TVec3(T _x, T _y, T _z) {
            x = _x;
            y = _y;
            z = _z;
        }

        /* Getters and setters */
        void set(const Vec &rOther) {
            x = rOther.x;
            y = rOther.y;
            z = rOther.z;
        }

        template<typename T>
        void set(const TVec3<T> &rOther) {
            x = rOther.x;
            y = rOther.y;
            z = rOther.z;
        }

        template<typename T>
        void set(T _x, T _y, T _z) {
            x = _x;
            y = _y;
            z = _z;
        }

        template<typename T>
        void setAll(T val) {
            x = val;
            y = val;
            z = val;
        }

        void zero() {
            x = 0;
            y = 0;
            z = 0;
        }

        void negate() {
            x = -x;
            y = -y;
            z = -z;
        }

        void negate(const TVec3<T> &);

        /* Arithmetic and algebraic operations */
        void add(const TVec3<T> &);
        void add(const TVec3<T> &, const TVec3<T> &);
        void sub(const TVec3<T> &);
        void sub(const TVec3<T> &, const TVec3<T> &);
        void mul(const TVec3<T> &);
        void mul(const TVec3<T> &, const TVec3<T> &);
        void scale(T);
        void scale(T, const TVec3<T> &);

        void setLength(T);
        void setLength(const TVec3<T> &, T);

        T squared() const;
        T squared(const TVec3<T> &) const;
        T dot(const TVec3<T> &) const;
        T normalize(const TVec3<T> &);

        T angle(const TVec3<T> &) const;

        /* Checkers */
        bool epsilonEquals(const TVec3<T> &, T) const;
        bool isZero() const;

        /* Operators */
        void operator=(const TVec3<T> &);
        TVec3<T> operator+(const TVec3<T> &) const;
        void operator+=(const TVec3<T> &);
        TVec3<T> operator-(const TVec3<T> &) const;
        TVec3<T> operator-() const;
        void operator-=(const TVec3<T> &);
        TVec3<T> operator*(T) const;
        void operator*=(T);
        TVec3<T> operator/(T) const;
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
    struct TVec4<T> {
        /* Constructors */
        inline TVec4() { }

        template<typename T>
        TVec4(T, T, T, T);

        /* Getters and setters */
        template<typename T>
        void set(const TVec4<T> &);

        template<typename T>
        void set(T, T, T, T);

        /* Arithmetic and algebraic operations */
        void scale(T);

        T x;
        T y;
        T z;
        T w;
    };
};

typedef JGeometry::TVec2<f32> TVec2f;
typedef JGeometry::TVec3<s8> TVec3c;
typedef JGeometry::TVec3<f32> TVec3f;
typedef JGeometry::TVec3<s16> TVec3s;
typedef JGeometry::TVec4<f32> TVec4f;
