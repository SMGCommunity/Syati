#pragma once

#include "revolution.h"
#include "CharWriter.h"

namespace nw4r {
	namespace ut {

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
