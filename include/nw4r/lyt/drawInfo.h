#pragma once

#include "types.h"
#include "nw4r\ut\Rect.h"

namespace nw4r
{

namespace lyt
{

class DrawInfo {
    public:
    DrawInfo();
    virtual ~DrawInfo();

    const math::MTX34& GetViewMtx() const {
        return mViewMtx;
    }
    void SetViewMtx(const math::MTX34& value) {
        mViewMtx = value;
    }
    bool IsMultipleViewMtxOnDraw() const {
        return mFlag.mulViewDraw;
    }
    void SetMultipleViewMtxOnDraw(bool value) {
        mFlag.mulViewDraw = value;
    }
    const ut::Rect& GetViewRect() const {
        return mViewRect;
    }
    void SetViewRect(const ut::Rect& value) {
        mViewRect = value;
    }
    bool IsYAxisUp() const { return true; }
    bool IsInfluencedAlpha() const {
        return mFlag.influencedAlpha;
    }
    void SetInfluencedAlpha(bool bEnable) {
        mFlag.influencedAlpha = bEnable;
    }
    bool IsLocationAdjust() const {
        return mFlag.locationAdjust;
    }
    void SetLocationAdjust(bool bEnable) {
        mFlag.locationAdjust = bEnable;
    }
    const math::VEC2& GetLocationAdjustScale() const {
        return mLocationAdjustScale;
    }
    void SetLocationAdjustScale(const math::VEC2& scale) {
        mLocationAdjustScale = scale;
    }
    f32 GetGlobalAlpha() const {
        return mGlobalAplha;
    }
    void SetGlobalAlpha(f32 alpha) {
        mGlobalAplha = alpha;
    }
    bool IsInvisiblePaneCalculateMtx() const {
        return mFlag.invisiblePaneCalculateMtx;
    }
    void SetInvisiblePaneCalculateMtx(bool bEnabled) {
        mFlag.invisiblePaneCalculateMtx = bEnabled;
    }

    math::MTX34 mViewMtx;
    ut::Rect mViewRect;
    math::VEC2 mLocationAdjustScale;
    f32 mGlobalAplha;

    struct {
        u8 mulViewDraw : 1;
        u8 influencedAlpha : 1;
        u8 locationAdjust : 1;
        u8 invisiblePaneCalculateMtx : 1;
    } mFlag;
};

}

}