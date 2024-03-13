#ifndef __REVOLUTION_GX_H
#define __REVOLUTION_GX_H

#include "revolution/types.h"

#ifdef __cplusplus
extern "C" {
#endif

    struct _GXColor {
        u8 r, g, b, a;
    };

    typedef struct _GXTexObj {
        u32 dummy[8];
    } GXTexObj;

    typedef _GXColor GXColor;

    typedef enum _GXTlut {
        GX_TLUT0 = 0,
        GX_TLUT1,
        GX_TLUT2,
        GX_TLUT3,
        GX_TLUT4,
        GX_TLUT5,
        GX_TLUT6,
        GX_TLUT7,
        GX_TLUT8,
        GX_TLUT9,
        GX_TLUT10,
        GX_TLUT11,
        GX_TLUT12,
        GX_TLUT13,
        GX_TLUT14,
        GX_TLUT15,
        GX_BIGTLUT0,
        GX_BIGTLUT1,
        GX_BIGTLUT2,
        GX_BIGTLUT3
    } GXTlut;

    typedef enum _GXTexMapID {
        GX_TEXMAP0,
        GX_TEXMAP1,
        GX_TEXMAP2,
        GX_TEXMAP3,
        GX_TEXMAP4,
        GX_TEXMAP5,
        GX_TEXMAP6,
        GX_TEXMAP7,
        GX_MAX_TEXMAP,
        GX_TEXMAP_NULL = 0xff,
        GX_TEX_DISABLE = 0x100
    } GXTexMapID;

    typedef enum _GXTexFmt {
    #define _GX_TF_CTF     0x20 /* copy-texture-format only */
    #define _GX_TF_ZTF     0x10 /* Z-texture-format */

        GX_TF_I4     = 0x0,
        GX_TF_I8     = 0x1,
        GX_TF_IA4    = 0x2,
        GX_TF_IA8    = 0x3,
        GX_TF_RGB565 = 0x4,
        GX_TF_RGB5A3 = 0x5,
        GX_TF_RGBA8  = 0x6,
        GX_TF_CMPR   = 0xE,

        GX_CTF_R4    = 0x0 | _GX_TF_CTF,
        GX_CTF_RA4   = 0x2 | _GX_TF_CTF,
        GX_CTF_RA8   = 0x3 | _GX_TF_CTF,
        GX_CTF_YUVA8 = 0x6 | _GX_TF_CTF,
        GX_CTF_A8    = 0x7 | _GX_TF_CTF,
        GX_CTF_R8    = 0x8 | _GX_TF_CTF,
        GX_CTF_G8    = 0x9 | _GX_TF_CTF,
        GX_CTF_B8    = 0xA | _GX_TF_CTF,
        GX_CTF_RG8   = 0xB | _GX_TF_CTF,
        GX_CTF_GB8   = 0xC | _GX_TF_CTF,

        GX_TF_Z8     = 0x1 | _GX_TF_ZTF,
        GX_TF_Z16    = 0x3 | _GX_TF_ZTF,
        GX_TF_Z24X8  = 0x6 | _GX_TF_ZTF,

        GX_CTF_Z4    = 0x0 | _GX_TF_ZTF | _GX_TF_CTF,
        GX_CTF_Z8M   = 0x9 | _GX_TF_ZTF | _GX_TF_CTF,
        GX_CTF_Z8L   = 0xA | _GX_TF_ZTF | _GX_TF_CTF,
        GX_CTF_Z16L  = 0xC | _GX_TF_ZTF | _GX_TF_CTF,

        GX_TF_A8     = GX_CTF_A8
    } GXTexFmt;


#ifdef __cplusplus
}
#endif

#endif // __REVOLUTION_GX_H
