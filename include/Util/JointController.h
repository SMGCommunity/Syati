#pragma once

#include "JGeometry/TPosition3.h"

class J3DJoint;
class LiveActor;

class JointController
{
	JointController();

	// not sure about the return types
	virtual u32 calcJointMatrix(TPositionMtx *, const JointControllerInfo &);
	virtual u32 calcJointMatrixAfterChild(TPositionMtx *, const JointControllerInfo &);

	void registerCallBack();
	void calcJointMatrixAndSetSystem(J3DJoint *);
	void calcJointMatrixAfterChildAndSetSystem(J3DJoint *);
	u32 staticCallBack(J3DJoint *, int); // not sure about return type
};

namespace MR
{
	void setJointControllerParam(JointController *, const LiveActor *, const char *);
	void setJointControllerParam(JointController *, const LiveActor *, u16);
};
