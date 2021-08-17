#include "kamekLoader.h"

void loadSMGBinary();

typedef void *(*JKRHeap_Alloc_t) (u32 size, s32 align, void *heap);
typedef void (*JKRHeap_Free_t) (void *buffer, void *heap);

struct loaderFunctionsEx {
	loaderFunctions base;
	JKRHeap_Alloc_t eggAlloc;
	JKRHeap_Free_t eggFree;
	void **gameHeapPtr;
	void **archiveHeapPtr;
};

void *allocAdapter(u32 size, bool isForCode, const loaderFunctions *funcs) {
	const loaderFunctionsEx *funcsEx = (const loaderFunctionsEx *)funcs;
    
	void **heapPtr = isForCode ? funcsEx->gameHeapPtr : funcsEx->archiveHeapPtr;
	return funcsEx->eggAlloc(size, 0x20, *heapPtr);
}
void freeAdapter(void *buffer, bool isForCode, const loaderFunctions *funcs) {
	const loaderFunctionsEx *funcsEx = (const loaderFunctionsEx *)funcs;
	void **heapPtr = isForCode ? funcsEx->gameHeapPtr : funcsEx->archiveHeapPtr;
	funcsEx->eggFree(buffer, *heapPtr);
}

#ifdef USA
const loaderFunctionsEx functions = {
	{
		(OSReport_t) 0x805B6210,
		(OSFatal_t) 0x805B8500,
		(DVDConvertPathToEntrynum_t) 0x805D1370,
		(DVDFastOpen_t) 0x805D1680,
		(DVDReadPrio_t) 0x805D1A50,
		(DVDClose_t) 0x805D1810,
		(sprintf_t) 0x80633CBC,
		allocAdapter,
		freeAdapter
	},
	(JKRHeap_Alloc_t) 0x80501310,
	(JKRHeap_Free_t) 0x80501360,
	(void **) 0x807D6110, // JKRHeap::sSystemHeap
	(void **) 0x807D6110 // JKRHeap::sRootHeap
};
#endif

#ifdef PAL
const loaderFunctionsEx functions = {
	{
		(OSReport_t) 0x805B6210,
		(OSFatal_t) 0x805B8500,
		(DVDConvertPathToEntrynum_t) 0x805D1370,
		(DVDFastOpen_t) 0x805D1680,
		(DVDReadPrio_t) 0x805D1A50,
		(DVDClose_t) 0x805D1810,
		(sprintf_t) 0x80633CBC,
		allocAdapter,
		freeAdapter
	},
	(JKRHeap_Alloc_t) 0x80501310,
	(JKRHeap_Free_t) 0x80501360,
	(void **) 0x807DB810, // JKRHeap::sSystemHeap
	(void **) 0x807DB810 // JKRHeap::sRootHeap
};
#endif

#ifdef JAP
const loaderFunctionsEx functions = {
	{
		(OSReport_t) 0x805B6210,
		(OSFatal_t) 0x805B8500,
		(DVDConvertPathToEntrynum_t) 0x805D1370,
		(DVDFastOpen_t) 0x805D1680,
		(DVDReadPrio_t) 0x805D1A50,
		(DVDClose_t) 0x805D1810,
		(sprintf_t) 0x80633CBC,
		allocAdapter,
		freeAdapter
	},
	(JKRHeap_Alloc_t) 0x80501310,
	(JKRHeap_Free_t) 0x80501360,
	(void **) 0x807D58D0, // JKRHeap::sSystemHeap
	(void **) 0x807D58D0 // JKRHeap::sRootHeap
};
#endif

#ifdef TWN
const loaderFunctionsEx functions = {
	{
		(OSReport_t) 0x805B6310,
		(OSFatal_t) 0x805B8600,
		(DVDConvertPathToEntrynum_t) 0x805D1470,
		(DVDFastOpen_t) 0x805D1780,
		(DVDReadPrio_t) 0x805D1B50,
		(DVDClose_t) 0x805D1910,
		(sprintf_t) 0x8063422C,
		allocAdapter,
		freeAdapter
	},
	(JKRHeap_Alloc_t) 0x805013A0,
	(JKRHeap_Free_t) 0x805013F0,
	(void **) 0x8072F710, // JKRHeap::sSystemHeap
	(void **) 0x8072F710 // JKRHeap::sRootHeap
};
#endif

#ifdef KOR
const loaderFunctionsEx functions = {
	{
		(OSReport_t) 0x805B6310,
		(OSFatal_t) 0x805B8600,
		(DVDConvertPathToEntrynum_t) 0x805D1470,
		(DVDFastOpen_t) 0x805D1780,
		(DVDReadPrio_t) 0x805D1B50,
		(DVDClose_t) 0x805D1910,
		(sprintf_t) 0x8063422C,
		allocAdapter,
		freeAdapter
	},
	(JKRHeap_Alloc_t) 0x805013A0,
	(JKRHeap_Free_t) 0x805013F0,
	(void **) 0x8072E2B0, // JKRHeap::sSystemHeap
	(void **) 0x8072E2B0 // JKRHeap::sRootHeap
};
#endif

void unknownVersion()
{
	// can't do much here!
	// we can't output a message on screen without a valid OSFatal addr
	for (;;);
}

void loadSMGBinary()
{
#if defined(USA)
	loadKamekBinaryFromDisc(&functions.base, "/CustomCode/CustomCode_USA.bin");
#elif defined(PAL)
	loadKamekBinaryFromDisc(&functions.base, "/CustomCode/CustomCode_PAL.bin");
#elif defined(JAP)
	loadKamekBinaryFromDisc(&functions.base, "/CustomCode/CustomCode_JAP.bin");
#elif defined(TWN)
	loadKamekBinaryFromDisc(&functions.base, "/CustomCode/CustomCode_TWN.bin");
#elif defined(KOR)
	loadKamekBinaryFromDisc(&functions.base, "/CustomCode/CustomCode_KOR.bin");
#endif
}

// GameSystemException::init
#if defined(TWN) || defined(KOR)
	kmBranch(0x804B7DA8, loadSMGBinary);
#else
	kmBranch(0x804B7D38, loadSMGBinary);
#endif
