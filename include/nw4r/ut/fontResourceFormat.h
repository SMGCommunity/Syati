#pragma once

#include "revolution\types.h"


namespace nw4r {
        namespace ut {
        
        struct CharWidths
        {
            s8 left;                    // left space width of character
            u8 glyphWidth;              // glyph width of character
            s8 charWidth;               // character width  = left space width  + glyph width  + right space width
        };
    
        enum FontEncoding
        {
            FONT_ENCODING_UTF8,
            FONT_ENCODING_UTF16,
            FONT_ENCODING_SJIS,
            FONT_ENCODING_CP1252,
            NUM_OF_FONT_ENCODING
        };
    };
}