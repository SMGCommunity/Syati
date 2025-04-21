#ifndef SC_H
#define SC_H

#include "revolution/os.h"
#include "revolution/nand.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef u8 SCType;

typedef struct {
    u8 mode;
    u8 led;
} SCIdleModeInfo;

typedef struct {
    union {
        u8 type_u8;
        s8 type_s8;
        u16 type_u16;
        s16 type_s16;
        u32 type_u32;
        s32 type_s32;
        u64 type_u64;
        s64 type_s64;
        u8 longPrecision64[sizeof(u64)];
    } integer;

    SCType typeInteger;
    SCType typeByteArray;
    u32 nameLen;
    u32 dataSize;
    char* name;
    u8* data;
    u32 packedSize;
} SCItem;

typedef void (*SCReloadConfFileCallback)(s32 result);
typedef void (*SCFlushCallback)(u32 result);

typedef enum {
    SC_ITEM_ID_IPL_COUNTER_BIAS,
    SC_ITEM_ID_IPL_ASPECT_RATIO,
    SC_ITEM_ID_IPL_AUTORUN_MODE,
    SC_ITEM_ID_IPL_CONFIG_DONE,
    SC_ITEM_ID_IPL_CONFIG_DONE2,
    SC_ITEM_ID_IPL_DISPLAY_OFFSET_H,
    SC_ITEM_ID_IPL_EURGB60_MODE,
    SC_ITEM_ID_IPL_EULA,
    SC_ITEM_ID_IPL_FREE_CHANNEL_APP_COUNT,
    SC_ITEM_ID_IPL_IDLE_MODE,
    SC_ITEM_ID_IPL_INSTALLED_CHANNEL_APP_COUNT,
    SC_ITEM_ID_IPL_LANGUAGE,
    SC_ITEM_ID_IPL_OWNER_NICKNAME,
    SC_ITEM_ID_IPL_PARENTAL_CONTROL,
    SC_ITEM_ID_IPL_PROGRESSIVE_MODE,
    SC_ITEM_ID_IPL_SCREEN_SAVER_MODE,
    SC_ITEM_ID_IPL_SIMPLE_ADDRESS,
    SC_ITEM_ID_IPL_SOUND_MODE,
    SC_ITEM_ID_IPL_UPDATE_TYPE,
    SC_ITEM_ID_NET_CONFIG,
    SC_ITEM_ID_NET_CONTENT_RESTRICTIONS,
    SC_ITEM_ID_NET_PROFILE,
    SC_ITEM_ID_NET_WC_RESTRICTION,
    SC_ITEM_ID_NET_WC_FLAGS,
    SC_ITEM_ID_DEV_BOOT_MODE,
    SC_ITEM_ID_DEV_VIDEO_MODE,
    SC_ITEM_ID_DEV_COUNTRY_CODE,
    SC_ITEM_ID_DEV_DRIVESAVING_MODE,
    SC_ITEM_ID_BT_DEVICE_INFO,
    SC_ITEM_ID_BT_CMPDEV_INFO,
    SC_ITEM_ID_BT_DPD_SENSIBILITY,
    SC_ITEM_ID_BT_SPEAKER_VOLUME,
    SC_ITEM_ID_BT_MOTOR_MODE,
    SC_ITEM_ID_BT_SENSOR_BAR_POSITION,
    SC_ITEM_ID_DVD_CONFIG,
    SC_ITEM_ID_WWW_RESTRICTION,
    SC_ITEM_ID_MAX_PLUS1
} SCItemID;

typedef struct {
        OSThreadQueue threadQueue;
        NANDFileInfo nandFileInfo;
        NANDCommandBlock nandCommandBlock;

        union {
            u8 nandType;
            NANDStatus nandStatus;
        } u;

        u8 nandStep;
        u8 nandNeedClose;
        u8 reloadFileCount;
        SCReloadConfFileCallback reloadCallback;
        s32 reloadResult;
        const char* reloadFileName[2];
        u8* reloadBufp[2];
        u32 reloadSizeExpected[2];
        u32 reloadedSize[2];
        SCFlushCallback flushCallback;
        u32 flushResult;
        u32 flushSize;
} SCControl;

s32 SCReloadConfFileAsync(u8 *, u32, SCReloadConfFileCallback);

extern u8 SCGetLanguage(void);

u8* __SCGetConfBuf(void);
u32 __SCGetConfBufSize(void);

void SCInit(void);
u32 SCCheckStatus(void);
u32 SCGetCounterBias(void);

BOOL SCGetIdleMode(SCIdleModeInfo *);

BOOL SCFindByteArrayItem(void *, u32, SCItemID);
BOOL SCFindU8Item(u8* , SCItemID);
BOOL SCFindS8Item(s8 *, SCItemID);
BOOL SCFindU32Item(u32 *, SCItemID);

s8 SCGetProductGameRegion(void);

BOOL __SCF1(const char *, char *, u32);

s8 SCGetDisplayOffsetH(void);
s8 SCGetProductArea(void);
u8 SCGetScreenSaverMode(void);

u8 SCGetSoundMode(void);

#ifdef __cplusplus
}
#endif

#endif // SC_H
