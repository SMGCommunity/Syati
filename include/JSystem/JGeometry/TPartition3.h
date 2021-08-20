#pragma once

#include "JSystem/JGeometry/TVec3.h"

namespace JGeometry
{
	template<typename T>
	class TPartition3
	{
	public:
		void set(const TVec3<T> &, const TVec3<T> &);
		void set(const TVec3<T> &, const TVec3<T> &, const TVec3<T> &);

		TVec3<T> _0;
		T _C;
	};
};

typedef JGeometry::TPartition3<f32> TPartition3f;
