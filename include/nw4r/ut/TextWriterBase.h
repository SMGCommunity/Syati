#pragma once

#include "revolution.h"

namespace nw4r {
	namespace ut {
        class Glyph;
        class Font;
        class Rect;
        class Color;

        class CharWriter {
        public:
            CharWriter();
            ~CharWriter();
            void SetFontSize(f32, f32);
            void SetFontSize(f32);
            f32 GetFontWidth() const;
            f32 GetFontHeight() const;
            f32 GetFontAscent() const;
            void Print(u16);
            void PrintGlyph(f32, f32, f32, const Glyph&);
            void UpdateVertexColor();
            void SetupVertexFormat();
            void SetupGXDefault();
            void SetupGXWithColorMapping(Color, Color);
            void SetupGXForI();
            void SetupGXForRGBA();
            f32 GetCursorX() const;
            f32 GetCursorY() const;
            void MoveCursorX(f32);
            void MoveCursorY(f32);
            void SetFont(const Font&);
            void ResetColorMapping();
            void SetupGX();

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

        template<typename T>
		class TextWriterBase : public CharWriter {
        public: 
            TextWriterBase();
            ~TextWriterBase();
            void SetLineHeight(float);
            f32 GetLineHeight(void) const;
            s32 CalcFormatStringWidth(const T*, ...) const;
            s32 CalcFormatStringHeight(const T*, ...) const;
            s32 CalcFormatStringRect(Rect*, const T*, ...) const;
            //s32 CalcVStringRect(Rect*, const T*, __va_list_struct*) const;
            s32 CalcStringWidth(const T*, int) const;
            s32 CalcStringHeight(const T*, int) const;
            s32 CalcStringRect(Rect*, const T*, int) const;
            f32 Printf(const T*, ...);
            //void VPrintf(const T*, __va_list_struct*);
            f32 Print(const T*, int);
            f32 PrintfMutable(const T*, ...);
            //void VPrintfMutable(const T*, __va_list_struct*);
            void PrintMutable(const T*, int);
            //int VSNPrintf(T*, unsigned long, const T*, __va_list_struct*);
            s32 CalcLineWidth(const T*, int);
            s32 CalcLineRectImpl(Rect*, const T*, int);
            s32 CalcStringRectImpl(Rect*, const T*, int);
            void PrintImpl(const T*, int, bool);
            void AdjustCursor(float*, float*, const T*, int);
            bool IsDrawFlagSet(unsigned long, unsigned long) const;
            f32 GetLineSpace() const;
            f32 GetCharSpace() const;

            s32 _4C;
            s32 _50;
            s32 _54;
            s32 _58;
            s32 _5C;
            s32 _60;
        };
	};
};

namespace MR {
    nw4r::ut::Font* getFontOnCurrentLanguage();
    nw4r::ut::Font* getPictureFontNW4R();
}
