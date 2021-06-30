#pragma once

#include "JGeometry/TPosition3.h"

class J3DJoint;
class J3DModel;
class JointControllerInfo;
class LiveActor;

class JointController
{
public:
	JointController();

	virtual bool calcJointMatrix(TPositionMtx *, const JointControllerInfo &);
	virtual bool calcJointMatrixAfterChild(TPositionMtx *, const JointControllerInfo &);

	void registerCallBack();
	void calcJointMatrixAndSetSystem(J3DJoint *);
	void calcJointMatrixAfterChildAndSetSystem(J3DJoint *);
	bool staticCallBack(J3DJoint *, int);

	J3DModel* mModel; // _4
	J3DJoint* mJoint; // _8
};

namespace MR
{
	void setJointControllerParam(JointController *, const LiveActor *, const char *);
	void setJointControllerParam(JointController *, const LiveActor *, u16);
};

template<typename T>
class JointControlDelegator : public JointController
{
public:
	inline JointControlDelegator() : JointController() {}

	virtual bool calcJointMatrix(TPositionMtx * pMtx, const JointControllerInfo & rInfo)
	{
		if (mCalcJointMtxFunc)
		{
			return (mObjPtr->*mCalcJointMtxFunc)(pMtx, rInfo);
		}
		else
		{
			return false;
		}
	}

	virtual bool calcJointMatrixAfterChild(TPositionMtx * pMtx, const JointControllerInfo & rInfo)
	{
		if (mCalcJointMtxAfterChildFunc)
		{
			return (mObjPtr->*mCalcJointMtxAfterChildFunc)(pMtx, rInfo);
		}
		else
		{
			return false;
		}
	}
	
	virtual ~JointControlDelegator() {}

	T* mObjPtr; // _C
	bool (T::*mCalcJointMtxFunc)(TPositionMtx *, const JointControllerInfo &); // _10
	bool (T::*mCalcJointMtxAfterChildFunc)(TPositionMtx *, const JointControllerInfo &); // _1C
};
