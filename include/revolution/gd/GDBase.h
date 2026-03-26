#ifndef GDBASE_H
#define GDBASE_H

#include "revolution/types.h"

#ifdef __cplusplus
extern "C" {
#endif

#define SS_MASK(mask) ((u32)((0xfe << 24) | (mask)))

typedef struct _GDLObj {
    u8* start;
    u32 length;
    u8* ptr;
    u8* top;
} GDLObj;

typedef void (*GDOverflowCallback)(void);

extern GDLObj* __GDCurrentDL;

void GDInitGDLObj(GDLObj*, void*, u32);

void GDPadCurr32();

void GDOverflowed();

static void GDOverflowCheck(u32 size);

static void __GDWrite(u8 data);

static void GDWrite_u8(u8 data);

static void GDWrite_u16(u16 data);

static void GDWrite_u32(u32 data);

static void GDWrite_f32(f32 data);

static inline void GDWriteBPCmd(u32 regval);

static inline void GDWriteCPCmd(u8 addr, u32 val);

static inline void GDWriteXFCmd(u16 addr, u32 val);

static inline void GDWriteXFCmdHdr(u16 addr, u8 len);

void GDOverflowed(void);

static void GDPosition3f32(f32 x, f32 y, f32 z);

inline static void GDSetCurrent(GDLObj* dl) {
    __GDCurrentDL = dl;
}

static inline u32 GDGetCurrOffset(void) {
    return (u32)(__GDCurrentDL->ptr - __GDCurrentDL->start);
}

static inline void GDSetCurrOffset(u32 offset) {
    __GDCurrentDL->ptr = __GDCurrentDL->start + offset;
}

static inline void* GDGetCurrPointer(void) {
    return (void*)__GDCurrentDL->ptr;
}

static inline u32 GDGetGDLObjOffset(const GDLObj* dl) {
    return (u32)(dl->ptr - dl->start);
}

static void GDColor4u8(u8 r, u8 g, u8 b, u8 a);

void GDFlushCurrToMem();

#ifdef __cplusplus
}
#endif

#endif  // GDBASE_H
