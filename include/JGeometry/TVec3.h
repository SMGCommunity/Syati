#pragma once

namespace JGeometry
{
    void negateInternal(const f32 *, f32 *);

    // Todo: Do angle and cubic<T> still exist in SMG2?

    // f32 is used most of the time, s16 is also found
    template<typename T>
    class TVec3
    {
    public:
        TVec3() {}
        TVec3(T);
        TVec3(const TVec3<T> &);
        TVec3(const Vec &);
        TVec3(T a, T b, T c) : x(a), y(b), z(c) {}

        template<typename T>
        TVec3(T, T, T); // supports int and f32
        
        void add(const TVec3<T> &);
        void add(const TVec3<T> &, const TVec3<T> &);
        void sub(const TVec3<T> &);
        void sub(const TVec3<T> &, const TVec3<T> &);
        void mul(const TVec3<T> &);
        void mul(const TVec3<T> &, const TVec3<T> &);
        T squared() const;
        T squared(const TVec3<T> &) const;
        T dot(const TVec3<T> &) const;

        bool epsilonEquals(const TVec3<T> &, T) const;
        bool isZero() const;

        void zero();
        void negate();
        void negate(const TVec3<T> &);
        T normalize(const TVec3<T> &);

        template<typename T>
        void set(const TVec3<T> &);
    
        template<typename T>
        void set(T, T, T); // supports int and f32

        void set(const Vec &);

        template<typename T>
        void setAll(T);

        void setLength(f32);
        void setLength(const TVec3<T> &, f32);
        void scale(T);
        void scale(T, const TVec3<T> &);

        void operator =(const TVec3<T> &); // as
        TVec3<T> operator +(const TVec3<T> &) const; // pl
        TVec3<T> operator +=(const TVec3<T> &); // apl
        TVec3<T> operator -(const TVec3<T> &) const; // mi
        TVec3<T> operator -() const; // mi
        TVec3<T> operator -=(const TVec3<T> &); // ami
        TVec3<T> operator *(T) const; // ml
        TVec3<T> operator *=(T); // amu
        TVec3<T> operator /(T) const; // dv
        bool operator ==(const TVec3<T> &) const; // eq

        T x; // _0
        T y; // _4
        T z; // _8
    };
};

typedef JGeometry::TVec3<f32> TVec3f;
