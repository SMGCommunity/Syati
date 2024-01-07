#pragma once

#include "revolution\types.h"
#include "nw4r\ut\LinkList.h"
#include "nw4r\math\types.h"

#ifndef offsetof
#define offsetof(TYPE, MEMBER) __builtin_offsetof (TYPE, MEMBER)
#endif

namespace nw4r
{

namespace lyt
{

struct Size {
    Size() : width(0), height(0) {}
    Size(f32 aWidth, f32 aHeight)
        : width(aWidth), height(aHeight) {}
    Size(const Size& other) : Size(other.width, other.height) {}

    f32 width;
    f32 height;
};

inline bool operator==(const Size& a, const Size& b) {
    return a.width == b.width && a.height == b.height;
}

class AnimTransform;

class AnimationLink {
    public:
    AnimationLink() {
        Reset();
    }
    void Reset() {
        Set(0, 0, false);
    }
    void Set(AnimTransform* animTrans, u16 idx, bool bDisable) {
        mAnimTrans = animTrans;
        mIdx = idx;
        mbDisable = bDisable;
    }
    void SetAnimTransform(AnimTransform* animTrans, u16 idx) {
        mAnimTrans = animTrans;
        mIdx = idx;
    }

    AnimTransform* GetAnimTransform() const {
        return mAnimTrans;
    }
    u16 GetIndex() const {
        return mIdx;
    }

    bool IsEnable() const {
        return !mbDisable;
    }
    void SetEnable(bool bEnable) {
        mbDisable = !bEnable;
    }

    ut::LinkListNode mLink;
    AnimTransform* mAnimTrans;
    u16 mIdx;
    bool mbDisable;
};

typedef 
ut::LinkList<AnimationLink, offsetof(AnimationLink, mLink)>
AnimationList;

typedef math::VEC2(*TexCoordQuad)[4];
typedef const math::VEC2(*ConstTexCoordQuad)[4];

}

}