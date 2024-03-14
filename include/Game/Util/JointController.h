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

	virtual bool calcJointMatrix(MtxPtr , const JointControllerInfo &);
	virtual bool calcJointMatrixAfterChild(MtxPtr , const JointControllerInfo &);

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
	typedef bool (T::*CalcJointMtxFunc)(MtxPtr , const JointControllerInfo &);

	inline JointControlDelegator() : JointController() {}

	virtual bool calcJointMatrix(MtxPtr  pMtx, const JointControllerInfo & rInfo) {
		if (mCalcJointMtxFunc) {
			return (mObjPtr->*mCalcJointMtxFunc)(pMtx, rInfo);
		}
		else {
			return false;
		}
	}

	virtual bool calcJointMatrixAfterChild(MtxPtr  pMtx, const JointControllerInfo & rInfo) {
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
