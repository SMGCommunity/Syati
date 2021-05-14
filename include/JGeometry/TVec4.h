#pragma once

namespace JGeometry
{
    template<typename T>
    class TVec4
    {
    public:
        template<typename T>
        TVec4(T, T, T, T);

        template<typename T>
        void set(const TVec4<T> &);
    
        template<typename T>
        void set(T, T, T, T); // does it still support int?

        void scale(T);

        T x; // _0
        T y; // _4
        T z; // _8
        T w; // _C
    };
};

typedef JGeometry::TVec4<f32> TVec4f;
