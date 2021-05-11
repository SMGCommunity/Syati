#pragma once

namespace JGeometry
{
    template<typename T>
    class TVec2
    {
    public:
        TVec2() { }
        TVec2(const TVec2<T> &);
        TVec2(T a, T b) : x(a), y(b) { }

        template<typename T>
        TVec2(T, T, T);

        T dot(const TVec2<T> &) const;

        template<typename T>
        void set(const TVec2<T> &);

        template<typename T>
        void set(T, T);

        void setMin(const TVec2<T> &);
        void setMax(const TVec2<T> &);

        void operator =(const TVec2<T> &);
        TVec2<T> operator +(const TVec2<T> &) const; // pl
        TVec2<T> operator -(const TVec2<T> &) const; // mi
        TVec2<T> operator *(T) const; // ml

        T x; // _0
        T y; // _4
    };
};

typedef JGeometry::TVec2<f32> TVec2f;
