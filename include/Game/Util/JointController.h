#pragma once

#include "revolution.h"
#include "JSystem.h"

class J3DJoint;
class J3DModel;
class LiveActor;

struct UnkStruct {
	u32 _0;
	u32 _4;
	u32 _8;
	u32 _C;
	u32 _10;
	u16 _14;
};

struct JointControllerInfo {
	u32 _0;
	UnkStruct* _4;
};

class JointController {
public:
	JointController();

	virtual bool calcJointMatrix(TPos3f*, const JointControllerInfo &);
	virtual bool calcJointMatrixAfterChild(TPos3f*, const JointControllerInfo &);

	void registerCallBack();
	void calcJointMatrixAndSetSystem(J3DJoint *);
	void calcJointMatrixAfterChildAndSetSystem(J3DJoint *);
	bool staticCallBack(J3DJoint *, int);

	J3DModel* mModel; // _4
	J3DJoint* mJoint; // _8
};

namespace MR {
	void setJointControllerParam(JointController *, const LiveActor *, const char *);
	void setJointControllerParam(JointController *, const LiveActor *, u16);
};

template<typename T>
class JointControlDelegator : public JointController {
public:
	typedef bool (T::*CalcJointMtxFunc)(TPos3f*, const JointControllerInfo &);

	inline JointControlDelegator(T* pHost, CalcJointMtxFunc calcFunc, CalcJointMtxFunc calcAfterChild) : JointController() {
        mObjPtr = pHost;
        mCalcJointMtxFunc = calcFunc;
        mCalcJointMtxAfterChildFunc = calcAfterChild;
    }

    inline JointControlDelegator(CalcJointMtxFunc calcFunc, T* pHost, CalcJointMtxFunc calcAfterChild) : JointController() {
        mObjPtr = pHost;
        mCalcJointMtxFunc = calcAfterChild;
        mCalcJointMtxAfterChildFunc = calcFunc;
    }

	virtual bool calcJointMatrix(TPos3f* pMtx, const JointControllerInfo & rInfo) {
		if (mCalcJointMtxFunc) {
			return (mObjPtr->*mCalcJointMtxFunc)(pMtx, rInfo);
		}
		else {
			return false;
		}
	}

	virtual bool calcJointMatrixAfterChild(TPos3f* pMtx, const JointControllerInfo & rInfo) {
		if (mCalcJointMtxAfterChildFunc) {
			return (mObjPtr->*mCalcJointMtxAfterChildFunc)(pMtx, rInfo);
		}
		else {
			return false;
		}
	}
	
	virtual ~JointControlDelegator() {}

	T* mObjPtr; // _C
	CalcJointMtxFunc mCalcJointMtxFunc; // _10
	CalcJointMtxFunc mCalcJointMtxAfterChildFunc; // _1C
};

namespace MR {
    void setJointControllerParam(JointController*, const LiveActor*, const char*);

    template < class T >
    JointControlDelegator< T >* createJointDelegator(T* pHost, const LiveActor* pActor, bool (T::*calcFunc)(TPos3f*, const JointControllerInfo&),
                                                     bool (T::*calcChild)(TPos3f*, const JointControllerInfo&), const char* pName) {
        JointControlDelegator< T >* delegator = new JointControlDelegator< T >(pHost, calcFunc, calcChild);
        setJointControllerParam(delegator, pActor, pName);
        return delegator;
    }

    template < class T >
    JointControlDelegator< T >* createJointDelegatorWithNullChildFunc(T* pHost, bool (T::*calcFunc)(TPos3f*, const JointControllerInfo&),
                                                                      const char* pName) {
        JointControlDelegator< T >* delegator = new JointControlDelegator< T >(pHost, calcFunc, 0);
        setJointControllerParam(delegator, pHost, pName);
        return delegator;
    }

    template < class T >
    JointControlDelegator< T >* createJointDelegatorWithNullMtxFunc(T* pHost, bool (T::*calcFunc)(TPos3f*, const JointControllerInfo&),
                                                                    const char* pName) {
        JointControlDelegator< T >* delegator = new JointControlDelegator< T >(calcFunc, pHost, 0);
        setJointControllerParam(delegator, pHost, pName);
        return delegator;
    }

    template < class T >
    JointController* createJointController(T* pHost, const char* pName, bool (T::*calcFunc)(TPos3f*, const JointControllerInfo&)) {
        JointControlDelegator< T >* delegator = new JointControlDelegator< T >(calcFunc, pHost, 0);
        setJointControllerParam(delegator, pHost, pName);
        return delegator;
    }
};
