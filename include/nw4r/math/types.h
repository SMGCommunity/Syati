#pragma once

#include "revolution\types.h"

namespace nw4r::math {
    struct _VEC2 {
        f32 x, y;
    };
    struct _VEC3 {
        f32 x, y, z;
    };
    

    struct VEC2: public _VEC2 {
        public:
        typedef VEC2 self_type;
        typedef f32 value_type;
        VEC2() {}
        VEC2(const f32* p) { x = p[0]; y = p[1]; }
        VEC2(f32 fx, f32 fy) { x = fx; y = fy; }
        VEC2(const _VEC2& v) { x= v.x; y = v.y; };

        operator f32*() { return &x; }
        operator const f32*() const { return &x; }

        self_type& operator+=(const self_type& rhs) {
            x += rhs.x;
            y += rhs.y;
            return *this;
        }
        self_type& operator-=(const self_type& rhs) {
            x -= rhs.x;
            y -= rhs.y;
            return *this;
        }
        self_type& operator*=(f32 f) {
            x *= f;
            y *= f;
            return *this;
        }
        self_type& operator/=(f32 f) {
            x /= f;
            y /= f;
            return *this;
        }

        self_type operator+() const {return *this;}
        self_type operator-() const {return self_type(-x, -y);}

        self_type operator+(const self_type& rhs) const {
            return self_type(x + rhs.x, y + rhs.y);
        }
        self_type operator-(const self_type& rhs) const {
            return self_type(x - rhs.x, y - rhs.y);
        }
        self_type operator*(f32 f) const {
            return self_type(f * x, f * y);
        }
        self_type operator/(f32 f) const {
            f32 r = 1.f/f;
            return self_type(r * x, r * y);
        }
        bool operator==(const self_type& rhs) const {
            return x == rhs.x && y == rhs.y;
        }
        bool operator!=(const self_type& rhs) const {
            x != rhs.x || y != rhs.y;
        }

        f32 LenSq() const { return x * x + y * y; }

        void Report(bool bNewline = true, const char* name = NULL) const;
    };

    struct VEC3: public _VEC3 {
        public:
        typedef VEC3 self_type;
        typedef f32 value_type;
        VEC3() {}
        VEC3(const f32* p) { x = p[0]; y = p[1]; z = p[2]; }
        VEC3(f32 fx, f32 fy, f32 fz) {
            x = fx;
            y = fy;
            z = fz;
        }
        VEC3(const _VEC3& v) {
            x = v.x;
            y = v.y;
            z = v.z;
        }
        VEC3(const Vec& v) {
            x = v.x;
            y = v.y;
            z = v.z;
        }

        operator f32*() { return &x; }
        operator const f32*() const { return &x; }
        operator Vec*() { return (Vec*)&x; }
        operator const Vec*() const { return (const Vec*)&x; }

        self_type& operator+=(const self_type& rhs);
        self_type& operator-=(const self_type& rhs);
        self_type& operator*=(f32 f);
        self_type& operator/=(f32 f) {
            return operator*=(1.f / f);
        }

        self_type operator+() const { return *this; }
        self_type operator-() const { return self_type(-x, -y, -z);}

        self_type operator+(const self_type& rhs) const;
        self_type operator-(const self_type& rhs) const;
        self_type operator*(f32 f) const;
        self_type operator/(f32 f) const {
            f32 r = 1.f / f;
            return operator*(r);
        }

        bool operator==(const self_type& rhs) const {
            return x == rhs.x && y == rhs.y && z == rhs.z;
        }
        bool operator!=(const self_type& rhs) const {
            return x != rhs.y || y != rhs.y || z != rhs.z;
        }

        f32 LenSq() const { return x * x + y * y + z * z; }

        void Report(bool bNewline = true, const char* name = NULL) const;
    };
}