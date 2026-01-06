#include "syati.h"

#if defined(SB4P)
#define KAMEK_BINARY_NAME "/CustomCode/CustomCode_SB4P.bin"
#elif defined(SB4E)
#define KAMEK_BINARY_NAME "/CustomCode/CustomCode_SB4E.bin"
#elif defined(SB4J)
#define KAMEK_BINARY_NAME "/CustomCode/CustomCode_SB4J.bin"
#elif defined(SB4W)
#define KAMEK_BINARY_NAME "/CustomCode/CustomCode_SB4W.bin"
#elif defined(SB4K)
#define KAMEK_BINARY_NAME "/CustomCode/CustomCode_SB4K.bin"
#endif

#define ALIGN_32(a) ((a + 31) & ~31)

namespace {
    struct KamekHeader {
        u32 magic1;
        u16 magic2;
        u16 version;
        u32 bssSize;
        u32 codeSize;
    };
    /// @brief Added in Kamek 2.0, we dont need any of this info as we already have it elsewhere.
    struct KamekExtra {
        u32 ctorStart;
        u32 ctorEnd;
        u32 unk[2];
    };

    void SyatiInit();
    void SyatiLink(u8 *linkedBuffer, u32 linkedSize, u8 *kamekBuffer, u32 kamekSize);

    void SyatiError(const char *msg);
};


#define kAddr32 1
#define kAddr16Lo 4
#define kAddr16Hi 5
#define kAddr16Ha 6
#define kRel24 10
#define kWrite32 32
#define kWrite16 33
#define kWrite8 34
#define kCondWritePointer 35
#define kCondWrite32 36
#define kCondWrite16 37
#define kCondWrite8 38
#define kBranch 64
#define kBranchLink 65
