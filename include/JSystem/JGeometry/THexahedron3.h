#pragma once

#include "JSystem/JGeometry/TVec3.h"

namespace JGeometry
{
	template<typename T>
	class THexahedron3
	{
	public:
		struct FacePlane
		{
			TVec3<T> mNormalized; // _0
			T mDistanceToOrigin; // _C
		};

		THexahedron3();

		bool mayIntersectBall3(const TVec3<T> center, T radius) const;

		FacePlane mFaces[6];
	};
};
