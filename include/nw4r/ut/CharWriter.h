#pragma once

#include "revolution.h"
#include "Font.h"

namespace nw4r::ut {
    // Undocumented atm
    
    class Color;

    class CharWriter {
        enum GradationMode
        {
            GRADMODE_NONE,
            GRADMODE_H,
            GRADMODE_V,
            NUM_OF_GRADMODE
        };

        static const u32 DEFAULT_COLOR_MAPPING_MIN = 0x00000000UL;
        static const u32 DEFAULT_COLOR_MAPPING_MAX = 0xFFFFFFFFUL;

        CharWriter();
        ~CharWriter();

        // Originally public

        void SetFont(const Font& font);
        const Font* GetFont() const;
        void SetupGX();
        void ResetTextureCache();
        void SetColorMapping(Color min, Color max);
        const Color GetColorMappingMin() const;
        const Color GetColorMappingMax() const;
        void ResetColorMapping();
        void SetAlpha(u8 alpha);
        u8 GetAlpha() const;
        void SetGradationMode(GradationMode mode);
        GradationMode GetGradationMode() const;
        void SetTextColor(Color color);
        void SetTextColor(Color start, Color end);
        const Color GetTextColor() const;
        const Color GetGradationStartColor() const;
        const Color GetGradationEndColor() const;
        void SetScale(f32 hScale, f32 vScale);
        void SetScale(f32 hvScale);
        f32 GetScaleH() const;
        f32 GetScaleV() const;
        void SetFontSize(f32 width, f32 height);
        void SetFontSize(f32 height);
        f32 GetFontWidth() const;
        f32 GetFontHeight() const;
        f32 GetFontAscent() const;
        f32 GetFontDescent() const;
        void EnableLinearFilter(bool atSmall, bool atLarge);
        bool IsLinearFilterEnableAtSmall() const;
        bool IsLinearFilterEnableAtLarge() const;
        bool IsWidthFixed() const;
        void EnableFixedWidth(bool isFixed);
        f32 GetFixedWidth() const;
        void SetFixedWidth(f32 width);
        f32 Print(CharCode code);
        void DrawGlyph(const Glyph& glyph);
        void SetCursor(f32 x, f32 y);
        void SetCursor(f32 x, f32 y, f32 z);
        void MoveCursor(f32 dx, f32 dy);
        void MoveCursor(f32 dx, f32 dy, f32 dz);
        void MoveCurosr(f32 dx, f32 dy);
        void SetCursorX(f32 x);
        void SetCursorY(f32 y);
        void SetCursorZ(f32 z);
        void MoveCursorX(f32 dx);
        void MoveCursorY(f32 dy);
        void MoveCursorZ(f32 dz);
        f32 GetCursorX() const;
        f32 GetCursorY() const;
        f32 GetCursorZ() const;

        // Originally private
        
        s32 _0;
        s32 _4;
        s32 _8;
        s32 _C;
        s32 _10;
        s32 _14;
        s32 _18;
        s32 _1C;
        s32 _20;
        s32 _24;
        s32 _28;
        s32 _2C;
        s32 _30;
        s32 _34;
        s32 _38;
        s32 _3C;
        s32 _40;
        s32 _44;
        s32 _48;
    };
}