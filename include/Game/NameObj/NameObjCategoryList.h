#pragma once

#include "revolution.h"
#include "Game/NameObj/NameObj.h"
#include "Game/Util/Array.h"
#include "Game/Util/Functor.h"

class NameObjDelegator {
public:
    virtual void operator()(NameObj *) = 0;
};

namespace {
    template<typename T>
    class NameObjRealDelegator : public NameObjDelegator {
    public:
        inline NameObjRealDelegator(T pFunc) {
            mFunctionPtr = pFunc;
        }

        void operator()(NameObj *pObj) {
            (pObj->*mFunctionPtr)(pObj, this);
        }

        T mFunctionPtr; // _4
    };
};

typedef void (NameObj::*TNameObjFunc)(const void *, void *);
typedef void (NameObj::*TNameObjConstFunc)(const void *, const void *);

struct CategoryListInitialTable {
    s32 mIndex; // _0
    s32 mCount; // _4
};

class NameObjCategoryList {
public:
    class CategoryInfo {
    public:
        CategoryInfo();
        ~CategoryInfo();

        MR::AssignableArray<NameObj*> mObjs; // _0
        u32 _8;
        MR::FunctorBase* _C;
        s32 mChecks;                        // _10
    };

    NameObjCategoryList(u32, const CategoryListInitialTable *, TNameObjFunc, bool, const char *);
    NameObjCategoryList(u32, const CategoryListInitialTable *, TNameObjConstFunc, bool, const char *);

    ~NameObjCategoryList();

    void execute(s32);
    void incrementCheck(NameObj *, s32);
    void allocateBuffer();
    void add(NameObj *, s32);
    void remove(NameObj *, s32);
    void registerExecuteBeforeFunction(const MR::FunctorBase &, int);
    // one missing boolean function between here
    void initTable(u32, const CategoryListInitialTable *);

    MR::AssignableArray<NameObjCategoryList::CategoryInfo*> mCategoryInfo; // _0
    NameObjDelegator* mDelegator; // _8
    u8 _C;
    u8 _D;
};
