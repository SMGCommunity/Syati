#pragma once

#include "nw4r\ut\LinkList.h"
#include "nw4r\ut\Color.h"
#include "revolution\types.h"
#include "nw4r\math\types.h"
#include "types.h"
#include "resources.h"

namespace nw4r
{

namespace ut 
{

struct Rect;

}

namespace lyt
{

namespace detail
{

class PaneBase
{

public:
PaneBase();
virtual ~PaneBase();

ut::LinkListNode mLink;

};

}

class AnimTransform;
class AnimationLink;
class AnimResource;
class Material;
class DrawInfo;
class Pane;

typedef 
ut::LinkList<Pane, offsetof(detail::PaneBase, mLink)> 
PaneList;

class Pane : public detail::PaneBase {
    Pane();
    Pane(const res::Pane* pBlock);
    virtual ~Pane();

    virtual void CalculateMtx(const DrawInfo& drawInfo);

    virtual void Draw(const DrawInfo& drawInfo);
    virtual void DrawSelf(const DrawInfo& drawInfo);
    
    virtual void Animate(u32 option);
    virtual void AnimateSelf(u32 option);

    const char* GetName() const;
    void SetName(const char* name);

    const char* GetUserData() const;
    void SetUserData(const char* userData) const;

    Pane* GetParent() const;
    const PaneList& GetChildList() const;
    PaneList& GetChildList();
    const AnimationList& GetAnimationList() const;
    AnimationList& GetAnimationList();

    void AppendChild(Pane* pChild);
    void PrependChild(Pane* pChild);
    void InsertChild(Pane* pNext, Pane* pChild);
    void InsertChild(PaneList::Iterator next, Pane* pChild);
    void RemoveChild(Pane* pChild);

    bool IsVisible() const;
    void SetVisible(bool bVisible);
    bool IsInfluencedAlpha() const;
    void SetInflucencedAlpha(bool bAplha);
    bool IsLocationAdjust() const;
    void SetLocationAdjust(bool bAdjust);

    const math::VEC3& GetTranslate() const;
    void SetTranslate(const math::VEC3& value);
    void SetTranslate(const math::VEC2& value);

    const math::VEC3& GetRotate() const;
    void SetRotate(const math::VEC3& value);

    const Size& GetSize() const;
    void SetSize(const Size& value);

    u8 GetBasePositionH() const;
    void SetBasePositionH(u8 val);

    u8 GetBasePositionV() const;
    void SetBasePositionV(u8 val);

    const math::MTX34& GetMtx() const;
    void SetMtx(const math::MTX34& mtx);

    const math::MTX34& GetGlobalMtx() const;
    void SetGlobalMtx(const math::MTX34& mtx);

    const ut::Rect GetPaneRect() const;
    // Obsolete
    const ut::Rect GetPaneRect(const DrawInfo& drawInfo) const;

    virtual const ut::Color GetVtxColor(u32 idx) const;
    virtual void SetVtxColor(u32 idx, ut::Color value);

    u8 GetAlpha() const;
    void SetAlpha(u8 alpha);
    u8 GetGlbAlpha() const;
    void SetGlbAlpha(u8 alpha);

    f32 GetSRTElement(u32 idx) const;
    void SetSRTElement(u32 idx, f32 value);

    virtual u8 GetColorElement(u32 idx) const;
    virtual void SetColorElement(u32 idx, u8 value);

    virtual Pane* FindPaneByName(const char* findName,
    bool bRecursive = true);
    virtual Material* FindMaterialByName(const char* findName,
    bool bRecursive = true);

    virtual void BindAnimation(AnimTransform* pAnimTrans,
    bool bRecursive = true, bool bDisable = false);
    virtual void UnbindAnimation(AnimTransform* pAnimtrans,
    bool bRecursive = true);
    virtual void UnbindAllAnimation(bool bRecursive = true);
    virtual void UnbindAnimationSelf(AnimTransform* pAnimTrans);

    void AddAnimationLink(AnimationLink* pAnimationLink);
    virtual AnimationLink* FindAnimationLinkSelf(AnimTransform* pAnimTrans);
    virtual AnimationList* FindAnimationLinkSelf(const AnimResource& animRes);

    virtual void SetAnimationEnable(AnimTransform* pAnimTrans,
    bool bEnable, bool bRecursive = true);
    virtual void SetAnimationEnable(const AnimResource& animRes,
    bool bEnable, bool bRecursive = true);

    virtual u8 GetMaterialNum() const;
    virtual Material* GetMaterial() const;
    virtual Material* GetMaterial(u32 idx) const;

    void SetExtUserDataList(const void* pBlock);
    u16 GetExtUserDataNum() const;
    const void* GetExtUserDataArray() const;
    const void* FindExtUserDataByName(const char* name);

    bool IsUserAllocated() const;

    virtual void LoadMtx(const DrawInfo& drawInfo);
    const math::VEC2 GetVtxPos() const;
    void CalculateMtxChild(const DrawInfo& drawInfo);

    Pane* mpParent;
    PaneList mChildList;
    AnimationList mAnimList;
    Material* mpMaterial;

    math::VEC3 mTranslate;
    math::VEC3 mRotate;
    math::VEC3 mScale;
    Size mSize;

    math::MTX34 mMtx;
    math::MTX34 mGlbMtx;

    const void* mpExtUserDataList;

    u8 mAlpha;
    u8 mGlbAlpha;
    u8 mBasePosition;
    u8 mFlag;

    char mName[17];
    char mUserData[9];
    u8 mbUserAllocated;
    u8 mPadding;

    void Init();

    private:
    Pane(const Pane& other);
    Pane& operator=(const Pane& other);
};

}

}