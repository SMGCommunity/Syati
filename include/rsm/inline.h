#pragma once

#include "revolution/types.h"

class InlineDataStream {
public:
    inline InlineDataStream(u8 *pData, s32 size) {
        mStart = pData;
        mCurr = pData;
        mEnd = pData + size;
    }

    template<typename T>
    inline T read() {
        T val = *(T *)mCurr;
        mCurr += sizeof(T);
        return val;
    };

    template<typename T>
    inline T* dataAs() {
        return (T*)mCurr;
    }

    inline void skip(s32 cnt) {
        mCurr += cnt;
    }

    inline bool isEnd() {
        return mCurr >= mEnd;
    }

    u8* mStart;
    u8* mCurr;
    u8* mEnd;
};