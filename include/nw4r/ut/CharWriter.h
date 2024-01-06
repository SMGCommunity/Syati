#pragma once

#include "revolution.h"
#include "nw4r/ut/Font.h"
#include "nw4r/ut/Color.h"
#include "nw4r/misc.h"
#include "nw4r/math/types.h"

namespace nw4r {
    namespace ut {
        class CharWriter {
            public:
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

            void SetFont(const Font& font) {
                mFont = &font;
            }
            const Font* GetFont() const {
                return mFont;
            }
            void SetupGX();
            void ResetTextureCache() {
                mLoadingTexture.Reset();
            }
            void SetColorMapping(Color min, Color max) {
                mColorMapping.min = min;
                mColorMapping.max = max;
            }
            const Color GetColorMappingMin() const {
                return mColorMapping.min;
            }
            const Color GetColorMappingMax() const {
                return mColorMapping.max;
            }
            void ResetColorMapping() {
                SetColorMapping(DEFAULT_COLOR_MAPPING_MIN, DEFAULT_COLOR_MAPPING_MAX);
            }
            void SetAlpha(u8 alpha) {
                mAlpha = alpha;
                UpdateVertexColor();
            }
            u8 GetAlpha() const {
                return mAlpha;
            }
            void SetGradationMode(GradationMode mode) {
                mTextColor.gradationMode = mode;
                UpdateVertexColor();
            }
            GradationMode GetGradationMode() const {
                return mTextColor.gradationMode;
            }
            void SetTextColor(Color color) {
                mTextColor.start = color;
                UpdateVertexColor();
            }
            void SetTextColor(Color start, Color end) {
                mTextColor.start = start;
                mTextColor.end = end;
                UpdateVertexColor();
            }
            const Color GetTextColor() const {
                return mTextColor.start;
            }
            const Color GetGradationStartColor() const {
                return mTextColor.start;
            }
            const Color GetGradationEndColor() const {
                return mTextColor.end;
            }
            void SetScale(f32 hScale, f32 vScale) {
                mScale.x = hScale;
                mScale.y = vScale;
            }
            void SetScale(f32 hvScale) {
                mScale.x = hvScale;
                mScale.y = hvScale;
            }
            f32 GetScaleH() const {
                return mScale.x;
            }
            f32 GetScaleV() const {
                return mScale.y;
            }
            void SetFontSize(f32 width, f32 height);
            void SetFontSize(f32 height);
            f32 GetFontWidth() const;
            f32 GetFontHeight() const;
            f32 GetFontAscent() const;
            f32 GetFontDescent() const;
            void EnableLinearFilter(bool atSmall, bool atLarge);
            bool IsLinearFilterEnableAtSmall() const {
                return mFilter.atSmall == GX_LINEAR;
            }
            bool IsLinearFilterEnableAtLarge() const {
                return mFilter.atLarge == GX_LINEAR;
            }
            bool IsWidthFixed() const {
                return mIsWidthFixed;
            }
            void EnableFixedWidth(bool isFixed) {
                mIsWidthFixed = isFixed;
            }
            f32 GetFixedWidth() const {
                return mFixedWidth;
            }
            void SetFixedWidth(f32 width) {
                mFixedWidth = width;
            }
            f32 Print(CharCode code);
            void DrawGlyph(const Glyph& glyph);
            void SetCursor(f32 x, f32 y) {
                mCursorPos.x = x;
                mCursorPos.y = y;
            }
            void SetCursor(f32 x, f32 y, f32 z) {
                mCursorPos.x = x;
                mCursorPos.y = y;
                mCursorPos.z = z;
            }
            void MoveCursor(f32 dx, f32 dy) {
                mCursorPos.x += dx;
                mCursorPos.y += dy;
            }
            void MoveCursor(f32 dx, f32 dy, f32 dz) {
                mCursorPos.x += dx;
                mCursorPos.y += dy;
                mCursorPos.z += dz;
            }
            void MoveCurosr(f32 dx, f32 dy) {
                MoveCursor(dx, dy);
            }
            void SetCursorX(f32 x) {
                mCursorPos.x = x;
            }
            void SetCursorY(f32 y) {
                mCursorPos.y = y;
            }
            void SetCursorZ(f32 z) {
                mCursorPos.z = z;
            }
            void MoveCursorX(f32 dx) {
                mCursorPos.x += dx;
            }
            void MoveCursorY(f32 dy) {
                mCursorPos.y += dy;
            }
            void MoveCursorZ(f32 dz) {
                mCursorPos.z += dz;
            }
            f32 GetCursorX() const {
                return mCursorPos.x;
            }
            f32 GetCursorY() const {
                return mCursorPos.y;
            }
            f32 GetCursorZ() const {
                return mCursorPos.z;
            }

            // Originally private

            struct ColorMapping
            {
                Color min;
                Color max;
            };

            struct TextColor {
                Color start;
                Color end;
                GradationMode gradationMode;
            };

            struct VertexColor {
                Color lu;
                Color ru;
                Color ld;
                Color rd;
            };

            class TextureFilter {
                public:
                GXTexFilter atSmall;
                GXTexFilter atLarge;
                bool operator!=(const TextureFilter& rhs) {
                    return (atSmall != rhs.atSmall)
                    || (atLarge != rhs.atLarge);
                }
            };

            class LoadingTexture {
                public:
                GXTexMapID slot;
                const void* texture;
                TextureFilter filter;
                bool operator!=(const LoadingTexture& rhs) {
                    return (slot != rhs.slot)
                    || (texture != rhs.texture)
                    || (filter != rhs.filter);
                }
                void Reset() {
                    slot = GX_TEXMAP_NULL;
                    texture = NULL;
                }
            };

            static LoadingTexture mLoadingTexture;
            ColorMapping mColorMapping;
            VertexColor mVertexColor;
            TextColor mTextColor;
            nw4r::math::VEC2 mScale;
            nw4r::math::VEC3 mCursorPos;
            TextureFilter mFilter;
            u8 padding_[2];
            u8 mAlpha;
            bool mIsWidthFixed;
            f32 mFixedWidth;
            const Font* mFont;

            static void SetupGXDefault();
            static void SetupGXWithColorMapping(Color min, Color max);
            static void SetupGXForRGBA();
            static void SetupGXForI();
            static void SetupVertexFormat();
            void PrintGlyph(f32 x, f32 y, f32 z, const Glyph& glyph);
            void UpdateVertexColor();
            void LoadTexture(const Glyph& glyph, GXTexMapID slot);
        };
    };
};