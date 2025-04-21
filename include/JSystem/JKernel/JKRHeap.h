#pragma once

#include "JSystem/JKernel/JKRDisposer.h"
#include "JSystem/JSupport/JSUList.h"

class JKRHeap : public JKRDisposer {
public:
    
    class TState {
    public:
        u32 _0;
        u32 _4;
    };

    JKRHeap(void *, u32, JKRHeap *, bool);

    virtual ~JKRHeap();
    virtual void callAllDisposer();
    virtual s32 getHeapType() = 0;
    virtual void check() = 0;
    virtual s32 dump_sort();
    virtual JKRHeap* dump() = 0;
    virtual void do_destroy() = 0;
    virtual void* do_alloc(u32, s32) = 0;
    virtual void do_free(void *) = 0;
    virtual void do_freeAll() = 0;
    virtual void do_freeTail() = 0;
    virtual void do_fillFreeArea() = 0;
    virtual s32 do_resize(void *, u32) = 0;
    virtual s32 do_getSize(void *) = 0;
    virtual s32 do_getFreeSize() = 0;
    virtual s32 do_getMaxFreeBlock() = 0;
    virtual s32 do_getTotalFreeSize() = 0;

    u32 getSize(void*);
    u32 getFreeSize();
    u32 getMaxFreeBlock();
    u32 getTotalFreeSize();

    u32 initArena(char **, u32 *, s32);
    JKRHeap* becomeSystemHeap();
    JKRHeap* becomeCurrentHeap();
    static void destroy(JKRHeap *);
    static void* alloc(u32, int, JKRHeap *);
    static void free(void *, JKRHeap *);
    void free(void *);
    void freeAll();
    void freeTail();
    void fillFreeArea();
    void resize(void *, u32);
    u32 getMaxAllocatableSize(int);

    // ... more functions

    static JKRHeap* findFromRoot(void *);
    static void copyMemory(void *dest, void *src, u32 len);
    static void* setErrorHandler(void (*)(void *, u32, s32));

    u32 _C;
    u32 _10;
    u32 _14;
    u32 _18;
    u32 _1C;
    u32 _20;
    u32 _24;
    u32 _28;
    u32 _2C;
    u32 _30;
    u32 _34;
    u32 _38;
    u32 _3C;
    u32 _40;
    u32 _44;
    u32 _48;
    u32 _4C;
    u32 _50;
    u32 _54;
    u32 _58;
    JSUPtrList mPtrList; // _5C

    static void* mCodeStart;
    static void* mCodeEnd;
    static void* mUserRamStart;
    static void* mUserRamEnd;
    static s32 mMemorySize;

    static JKRHeap* sSystemHeap;
    static JKRHeap* sCurrentHeap;
    static JKRHeap* sRootHeap;
    static void* sErrorHandler;
};

void JKRDefaultMemoryErrorRoutine(void *, u32, s32);

void* operator new(size_t);
void* operator new(size_t, int);
void* operator new(size_t, JKRHeap*, int);

void* operator new[](size_t);
void* operator new[](size_t, int);
void* operator new[](size_t, JKRHeap*, int);

void operator delete(void*);
void operator delete[](void*);
