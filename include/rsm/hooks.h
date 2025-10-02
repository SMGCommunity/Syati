#ifndef __RSM_HOOKS_H
#define __RSM_HOOKS_H

#include "revolution/types.h"

// .rsm section declaration
#pragma section ".rsm"

#ifndef INTELLISENSE_FIX // If this definition is added to c_cpp_properties.json, intellisense will not show a syntax error when using hook macros.
#define rsmPatchSection __declspec(section ".rsm")
#else
#define rsmPatchSection
#endif

typedef const unsigned char rsmSymbol;

// Patch structure and ID definitions
#define rsmPatchIdNull 0
struct rsmPatchNull {
    u32 type;
};

#define rsmPatchIdWrite 1
#define rsmPatchWriteType_u8  0
#define rsmPatchWriteType_u16 1
#define rsmPatchWriteType_u32 2
struct rsmPatchWrite {
    u32 type;
    u32 addr;
    u32 val;
    u8 dataType;
};

#define rsmPatchIdBranch 2
struct rsmPatchBranch {
    u32 type;
    u32 addr;
    u32 ptr;
    s16 depEntry;
    bool isCall;
};

// General macro definitions
#define rsmIdentifier(key, counter) \
    _##key##counter

#define rsmDeclare(type, counter) \
	rsmPatchSection static const type rsmIdentifier(type, counter)

#define rsmDeclarePatch(type, counter) \
	rsmDeclare(rsmPatch##type, counter)

#define rsmWritePatch(type, ...) \
    rsmDeclarePatch(type, __COUNTER__) = { rsmPatchId##type, __VA_ARGS__ };

// Data writing patches
#define rsmWrite8(addr, val) rsmWritePatch(Write, (addr), (val), rsmPatchWriteType_u8)
#define rsmWrite16(addr, val) rsmWritePatch(Write, (addr), (val), rsmPatchWriteType_u16)
#define rsmWrite32(addr, val) rsmWritePatch(Write, (addr), (val), rsmPatchWriteType_u32)

// Branch hooks
#define rsmBranch(addr, ptr) rsmWritePatch(Branch, (addr), (u32)&(ptr), 0, false)
#define rsmCall(addr, ptr) rsmWritePatch(Branch, (addr), (u32)&(ptr), 0, true)

// Utility hooks
#define rsmNop(addr) rsmWrite32(addr, 0x60000000)
#define rsmBlr(addr) rsmWrite32(addr, 0x4E800020)

// Symbol-based hooks
#define rsmAddress(sym, off) ((u32)&(sym) + (off))
#define rsmSymWrite8(sym, off, val) rsmWrite8(rsmAddress(sym, off), val)
#define rsmSymWrite16(sym, off, val) rsmWrite16(rsmAddress(sym, off), val)
#define rsmSymWrite32(sym, off, val) rsmWrite32(rsmAddress(sym, off), val)
#define rsmSymBranch(sym, off, ptr) rsmBranch(rsmAddress(sym, off), ptr)
#define rsmSymCall(sym, off, ptr) rsmCall(rsmAddress(sym, off), ptr)

#endif