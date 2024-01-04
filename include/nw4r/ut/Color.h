#pragma once

#include "revolution/gx.h"
#include "inlines.h"

namespace nw4r::ut {
    struct Color: public GXColor {
        Color() {
            operator=(0xFFFFFFFF);
        }
        Color(u32 color) {
            operator=(color);
        }
        Color(const GXColor& color) {
            operator=(color);
        }
        Color(int red, int green, int blue, int alpha = 255) {
            Set(red, green, blue, alpha);
        }
        ~Color() {}

        Color& operator=(u32 color) {
            ToU32Ref() = color;
            return *this;
        }
        Color& operator=(const GXColor& color) {
            operator=(*reinterpret_cast<const u32*>(&color));
        }
        operator u32() const {
            return ToU32Ref();
        }

        u32 ToU32() const {
            return ToU32Ref();
        }
        void Set(int red, int green, int blue, int alpha = 255) {
            r = static_cast<u8>(red);
            g = static_cast<u8>(green);
            b = static_cast<u8>(blue);
            a = static_cast<u8>(alpha);
        }
        void Set(Color color) {
            operator=(color);
        }

        const Color operator+(const Color& right) const {
            Color color(
                Min(r + right.r, 255), 
                Min(g + right.g, 255),
                Min(b + right.b, 255), 
                Min(a + right.a, 255)
            );
            return color;
        }
        const Color operator-(const Color& right) const {
            Color color(
                Max(r - right.r, 0),
                Max(g - right.g, 0),
                Max(b - right.b, 0),
                Max(a - right.a, 0)
            );
            return color;
        }
        const Color operator*(const Color& right) const {
            Color color(
                r * right.r / 255,
                g * right.g / 255,
                b * right.b / 255,
                a * right.a / 255
            );
            return color;
        }
        const Color operator/(const Color& right) const {
            Color color(
                (right.r != 0) ? Min(r * 255 / right.r, 255): 255,
                (right.g != 0) ? Min(g * 255 / right.g, 255): 255,
                (right.b != 0) ? Min(b * 255 / right.b, 255): 255,
                (right.a != 0) ? Min(a * 255 / right.a, 255): 255
            );
            return color;
        }
        
        const Color operator+(u32 rhs) const {
            const Color right = rhs;
            return operator+(right);
        }
        const Color operator-(u32 rhs) const {
            const Color right = rhs;
            return operator-(right);
        }
        const Color operator*(u32 rhs) const {
            const Color right = rhs;
            return operator*(right);
        }
        const Color operator/(u32 rhs) const {
            const Color right = rhs;
            return operator/(right);
        }

        const Color operator++() {
            (r >= 255) ? 0: r++;
            (g >= 255) ? 0: g++;
            (b >= 255) ? 0: b++;
            (a >= 255) ? 0: a++;
            return *this;
        }
        const Color operator++(int) {
            return operator++();
        }
        const Color operator--() {
            (r <= 0) ? 0: r--;
            (g <= 0) ? 0: g--;
            (b <= 0) ? 0: b--;
            (a <= 0) ? 0: a--;
        }
        const Color operator--(int) {
            return operator--();
        }

        const Color operator|(const Color& right) const {
            return (ToU32() | right.ToU32());
        }
        const Color operator&(const Color& right) const {
            return (ToU32() & right.ToU32());
        }
        const Color operator|(u32 right) const {
            return (ToU32() | right);
        }
        const Color operator&(u32 right) const {
            return (ToU32() & right);
        }

        Color& operator+=(const Color& rhs) {
            *this = *this + rhs;
            return *this;
        }
        Color& operator-=(const Color& rhs) {
            *this = *this - rhs;
            return *this;
        }
        Color& operator*=(const Color& rhs) {
            *this = *this * rhs;
            return *this;
        }
        Color& operator/=(const Color& rhs) {
            *this = *this / rhs;
            return *this;
        }

        u32& ToU32Ref() {
            return *reinterpret_cast<u32*>(this);
        }
        const u32& ToU32Ref() const {
            return *reinterpret_cast<const u32*>(this);
        }
    };
}