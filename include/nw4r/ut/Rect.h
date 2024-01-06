#pragma once

#include "revolution/types.h"
#include "nw4r/math/arithmetic.h"

namespace nw4r {
    namespace ut {

        struct Rect {
            public:
            f32 left;
            f32 top;
            f32 right;
            f32 bottom;
    
            Rect()
            {
                left = 0;
                top = 0;
                right = 0;
                bottom = 0;
            }
    
            Rect(f32 l, f32 t, f32 r, f32 b) {
                left = l;
                top = t;
                right = r;
                bottom = b;
            }
    
            ~Rect() {}
    
            f32 GetWidth() const {
                return right - left;
            }
    
            f32 GetHeight() const {
                return bottom - top;
            }
    
            void SetWidth(f32 width) {
                right = left + width;
            }
    
            void SetHeight(f32 height) {
                bottom = top + height;
            }
    
            void MoveTo(f32 x, f32 y) {
                right = x + GetWidth();
                left = x;
                bottom = y + GetHeight();
                top = y;
            }
    
            void Move(f32 dx, f32 dy) {
                left += dx;
                right += dx;
                top += dy;
                bottom += dy;
            }
    
            void Normalize() {
                const f32 l = left;
                const f32 t = top;
                const f32 r = right;
                const f32 b = bottom;
    
                left = nw4r::math::FSelect(r - l, l, r);
                right = nw4r::math::FSelect(r - l, r, l);
                top = nw4r::math::FSelect(b - t, t, b);
                bottom = nw4r::math::FSelect(b - t, b, t);
            }
        };
    };
};