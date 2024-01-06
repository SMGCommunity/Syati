#pragma once

#define NW4R_FROM_TOOL

namespace nw4r
{
#ifdef NW4R_COMPILER_WITH_W64
typedef __w64 unsigned long IntPtr;
typedef __w64 signed long PtrDiff;
#else
typedef unsigned long IntPtr;
typedef signed long PtrDiff;
#endif
}

#ifndef NW4R_ASSERTMSG
#ifdef  NW4R_FROM_TOOL
#define NW4R_ASSERTMSG  true ? 0:
#else
#define NW4R_ASSERTMSG  NW4R_DB_ASSERTMSG
#endif
#endif

#ifndef NW4R_ANY_TO_PTR_VALUE
#define NW4R_ANY_TO_PTR_VALUE(ptr) reinterpret_cast<nw4r::IntPtr>(reinterpret_cast<const void*>(ptr))
#endif

#ifndef NW4R_POINTER_ASSERT
#ifdef  NW4R_PLATFORM_RVL
#define NW4R_POINTER_ASSERT(exp)                                                                                            \
            NW4R_ASSERTMSG(                                                                                                 \
                   ((NW4R_ANY_TO_PTR_VALUE(exp) & 0xFF000000) == 0x80000000)    /* 8000_0000 - 80FF_FFFF MEM1 Cached   */    \
                || ((NW4R_ANY_TO_PTR_VALUE(exp) & 0xFF800000) == 0x81000000)    /* 8100_0000 - 817F_FFFF MEM1 Cached   */    \
                || ((NW4R_ANY_TO_PTR_VALUE(exp) & 0xF8000000) == 0x90000000)    /* 9000_0000 - 97FF_FFFF MEM2 Cached   */    \
                || ((NW4R_ANY_TO_PTR_VALUE(exp) & 0xFF000000) == 0xC0000000)    /* C000_0000 - C0FF_FFFF MEM1 Uncached */    \
                || ((NW4R_ANY_TO_PTR_VALUE(exp) & 0xFF800000) == 0xC1000000)    /* C100_0000 - C17F_FFFF MEM1 Uncached */    \
                || ((NW4R_ANY_TO_PTR_VALUE(exp) & 0xF8000000) == 0xD0000000)    /* D000_0000 - D7FF_FFFF MEM2 Uncached */    \
                || ((NW4R_ANY_TO_PTR_VALUE(exp) & 0xFFFFC000) == 0xE0000000),   /* E000_0000 - E000_3FFF Locked Cache  */    \
                "NW4R:Pointer Error\n"#exp"(=%p) is not valid pointer.", (exp) )
#else
#define NW4R_POINTER_ASSERT(exp)                                                                \
            NW4R_ASSERTMSG(                                                                     \
                   ((NW4R_ANY_TO_PTR_VALUE(exp) & 0xF0000000) == 0x80000000)    /* Cached   */  \
                || ((NW4R_ANY_TO_PTR_VALUE(exp) & 0xF0000000) == 0xC0000000),   /* Uncached */  \
                "NW4R:Pointer Error\n"#exp"(=%p) is not valid pointer.", (exp) )
#endif
#endif

#ifndef NW4R_REFERENCE_ASSERT
#define NW4R_REFERENCE_ASSERT(ref) NW4R_POINTER_ASSERT(&ref)
#endif