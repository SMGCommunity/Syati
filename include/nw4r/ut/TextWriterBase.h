#pragma once

#include "revolution.h"
#include "CharWriter.h"
#include "TagProcessorBase.h"
#include "Rect.h"

namespace nw4r {
	namespace ut {

        template <typename CharT>
        class TextWriterBase: public CharWriter {
            public:

            // Originally public

            enum PositionFlag {
                HORIZONTAL_ALIGN_LEFT       = 0x0,
                HORIZONTAL_ALIGN_CENTER     = 0x1,
                HORIZONTAL_ALIGN_RIGHT      = 0x2,
                HORIZONTAL_ALIGN_MASK       = 0x3,

                HORIZONTAL_ORIGIN_LEFT      = 0x00,
                HORIZONTAL_ORIGIN_CENTER    = 0x10,
                HORIZONTAL_ORIGIN_RIGHT     = 0x20,
                HORIZONTAL_ORIGIN_MASK      = 0x30,

                VERTICAL_ORIGIN_TOP         = 0x000,
                VERTICAL_ORIGIN_MIDDLE      = 0x100,
                VERTICAL_ORIGIN_BOTTOM      = 0x200,
                VERTICAL_ORIGIN_BASELINE    = 0x300,
                VERTICAL_ORIGIN_MASK        = 0x300
            };
            enum ContextFlag
            {
                CONTEXT_NO_CHAR_SPACE       = 0x1
            };

            typedef CharT CharType;
            typedef const CharType* StreamType;
            typedef TagProcessorBase<CharType> TagProcessor;
            typedef TextWriterBase<CharType> SelfType;

            static const u32 DEFAULT_DRAWFLAG = (HORIZONTAL_ALIGN_LEFT | HORIZONTAL_ORIGIN_LEFT | VERTICAL_ORIGIN_TOP);

            TextWriterBase();
            ~TextWriterBase();

            void SetLineHeight(f32 height);
            f32 GetLineHeight() const;
            void SetLineSpace(f32 space) {
                mLineSpace = space;
            }
            void SetCharSpace(f32 space) {
                mCharSpace = space;
            }
            f32 GetLineSpace() const {
                return mLineSpace;
            }
            f32 GetCharSpace() const {
                return mCharSpace;
            }
            void SetTabWidth(int tabWidth) {
                mTabWidth = tabWidth;
            }
            int GetTabWidth() const {
                return mTabWidth;
            }
            void SetWidthLimit(f32 limit) {
                return mWidthLimit = limit;
            }
            void ResetWidthLimit() {
                SetWidthLimit(__FLT_MAX__)
            }
            f32 GetWidthLimit() const {
                return mWidthLimit;
            }

            void SetDrawFlag(u32 flags) {
                mDrawFlag = flags;
            }
            u32 GetDrawFlag() const {
                return mDrawFlag;
            }

            void SetTagProcessor(TagProcessor* tagProcessor) {
                mTagProcessor = tagProcessor;
            }
            void ResetTagProcessor() {
                mTagProcessor = &mDefaultTagProcessor;
            }
            TagProcessor& GetTagProcessor() const {
                return *mTagProcessor;
            }

            f32 CalcFormatStringWidth(StreamType format, ...) const;
            f32 CalcFormatStringHeight(StreamType format, ...) const;
            void CalcFormatStringRect(Rect* pRect, StreamType format, ...) const;
            void CalcVStringRect(Rect* pRect, StreamType format, va_list args) const;
            f32 CalcStringWidth(StreamType str, int length) const;
            f32 CalcStringHeight(StreamType str, int length) const;
            void CalcStringRect(Rect* pRect, StreamType str, int length) const;
            f32 CalcStringWidth(StreamType str) const {
                return CalcStringWidth(str, StrLen(str));
            }
            f32 CalcStringHeight(StreamType str) const {
                return CalcStringHeight(str, StrLen(str));
            }
            void CalcStringRect(Rect* pRect, StreamType str) const {
                CalcStringRect(pRect, str, StrLen(str));
            }

            f32 Printf(StreamType format, ...);
            f32 VPrintf(StreamType format, va_list args);
            f32 Print(StreamType str, int length);
            f32 Print(StreamType str) {
                return Ptring(str, StrLen(str));
            }
            f32 PrintfMutable(StreamType format, ...);
            f32 VPrintfMutable(StreamType format, va_list args);
            f32 PrintMutable(StreamType str, int length);
            f32 PrintMutable(StreamType str) {
                return PrintMutable(str, StrLen(str));
            }
            static void* SetBuffer(CharType* buffer, size_t size) {
                void* oldBuffer = mFormatBuffer;
                mFormatBuffer = buffer;
                mFormatBufferSize = size;
                return oldBuffer;
            }
            static void* SetBuffer(size_t size) {
                void* oldBuffer = mFormatBuffer;
                mFormatBuffer = NULL;
                mFormatBufferSize = size;
                return oldBuffer;
            }
            static size_t GetBufferSize() {
                return mFormatBufferSize;
            }
            static const void* GetBuffer() {
                return mFormatBuffer;
            }

            static int VSNPrintf(char* buffer, size_t count, const char* format, va_list arg) {
                return vsnprintf(buffer, count, format, arg);
            }
            static int VSNPrintf(wchar_t* buffer, size_t count, const wchar_t* format, va_list arg) {
                return vswprintf(buffer, count, format, arg);
            }
            static int StrLen(const char* str) {
                return static_cast<int>(strlen(str));
            }
            static int StrLen(const wchar_t* str) {
                return static_cast<int>(wcslen(str));
            }

            using CharWriter::Print;

            // Originally private

            static const int DEFAULT_FORMAT_BUFFER_SIZE = 256;

            f32 mWidthLimit;
            f32 mCharSpace;
            f32 mLineSpace;
            int mTabWidth;
            u32 mDrawFlag;
            TagProcessor* mTagProcessor;

            static CharType* mFormatBuffer;
            static size_t mFormatBufferSize;

            static TagProcessor mDefaultTagProcessor;

            f32 CalcLineWidth(StreamType str, int length);
            bool CalcLineRectImpl(Rect* pRect, StreamType* pStr, int length);
            void CalcStringRectImpl(Rect* pRect, StreamType str, int length);
            f32 PrintImpl(StreamType str, int length, bool bMutable);
            f32 AdjustCursor(f32* xOrigin, f32* yOrigin, StreamType str, int length);
            bool IsDrawFlagSet(u32 mask, u32 flag) const {
                return (mDrawFlag & mask) == flag;
            } 
        };
	};
};

namespace MR {
    nw4r::ut::Font* getFontOnCurrentLanguage();
    nw4r::ut::Font* getPictureFontNW4R();
}
