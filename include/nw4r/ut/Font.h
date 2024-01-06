#pragma once

#include "revolution.h"
#include "fontResourceFormat.h"
#include "revolution\gx.h"
#include "CharStrmReader.h"

namespace nw4r {

namespace ut {
    
typedef u16 CharCode;

struct Glyph {
    const void* pTexture;
    CharWidths widths;
    u8 height;
    GXTexFmt textFormat;
    u16 texWidth;
    u16 texHeight;
    u16 cellX;
    u16 cellY;
};

class Font {
    public:
    enum Type {
        TYPE_NULL,
        TYPE_ROM,
        TYPE_RESOURCE,
        TYPE_PAIR
    };

    static const CharCode INVALID_CHARACTER_CODE = (u16)~0;

    Font() {
        mReaderFunc = &CharStrmReader::ReadNextCharCP1252;
    }
    virtual ~Font() {}

    virtual int GetWidth() const = 0;
    virtual int GetHeight() const = 0;
    virtual int GetAscent() const = 0;
    virtual int GetDescent() const = 0;
    virtual int GetBaselinePos() const = 0;
    virtual int GetCellHeight() const = 0;
    virtual int GetCellWidth() const = 0;
    virtual int GetMaxCharWidth() const = 0;
    virtual Type GetType() const = 0;
    virtual GXTexFmt GetTextureFormat() const = 0;
    virtual int GetLineFeed() const = 0;
    virtual const CharWidths GetDefaultCharWidths() const = 0;

    virtual void SetDefaultCharWidths(const CharWidths& widths) = 0;
    virtual bool SetAlternateChar(CharCode c) = 0;
    virtual void SetLineFeed(int linefeed) = 0;

    virtual int GetCharWidth(CharCode c) const = 0;
    virtual const CharWidths GetCharWidths(CharCode c) const = 0;
    virtual void GetGlyph(Glyph* glyphPtr, CharCode c) const = 0;
    virtual bool HasGlyph(CharCode c) const = 0;

    virtual FontEncoding GetEncoding() const = 0;
    const CharStrmReader GetCharStrmReader() const;

    void InitReaderFunc(FontEncoding encoding);

    CharStrmReader::CharStrmReaderFunc mReaderFunc;
};

}

}