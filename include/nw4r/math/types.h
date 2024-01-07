#pragma once

#include "revolution\types.h"
#include "c_stdlib.h"

namespace nw4r {
        namespace math {
        struct _VEC2 {
            f32 x, y;
        };
        struct _VEC3 {
            f32 x, y, z;
        };

        struct _MTX34 {
            union 
            {
                struct {
                    f32 _00, _01, _02, _03;
                    f32 _10, _11, _12, _13;
                    f32 _20, _21, _22, _23;
                };
                f32 m[3][4];
                f32 a[12];
                Mtx mtx;
            };
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
                return x != rhs.x || y != rhs.y;
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

        struct MTX34 : public _MTX34 {
            public:
            typedef MTX34 self_type;
            typedef f32 value_type;
            typedef const f32(*ConstMtxPtr)[4];

            MTX34() {}
            MTX34(const f32* p);
            MTX34(const Mtx& rhs);
            MTX34(f32 x00, f32 x01, f32 x02, f32 x03,
            f32 x10, f32 x11, f32 x12, f32 x13,
            f32 x20, f32 x21, f32 x22, f32 x23) {
                _00 = x00; _01 = x01; _02 = x02; _03 = x03;
                _10 = x10; _11 = x11; _12 = x12; _13 = x13;
                _20 = x20; _21 = x21; _22 = x22; _23 = x23;
            }

            operator f32*() { return &_00; }
            operator const f32*() const { return &_00; }
            operator MtxPtr() { return (MtxPtr)&_00; }
            operator ConstMtxPtr() const { return (ConstMtxPtr)&_00; }

            self_type& operator+=(const self_type& rhs);
            self_type& operator-=(const self_type& rhs);
            self_type& operator*=(f32 f);
            self_type& operator/=(f32 f) { return operator*=(1.f / f); }
            self_type operator+() const { return *this; }
            self_type operator-() const {
                return self_type(-_00, -_01, -_02, -_03,
                -_10, -_11, -_12, -_13,
                -_20, -_21, -_22, -_23);
            }
            self_type operator*(f32 f) const;
            self_type operator/(f32 f) const {
                return *this * (1.f / f);
            }
            
            bool operator==(const self_type& rhs) const {
                return memcmp(this, &rhs, sizeof(self_type)) == 0;
            }
            bool operator!=(const self_type& rhs) const {
                return memcmp(this, &rhs, sizeof(self_type)) != 0;
            }

            void Report(bool bNewline = true, const char* name = NULL) const;
        };
    };
};