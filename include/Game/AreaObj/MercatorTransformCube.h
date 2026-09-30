#pragma once

#include "Game/AreaObj/AreaObj.h"

class LiveActor;

class DivideMercatorRailPosInfo {
public:
	virtual void setPosition(s32, const TVec3f &rPosition) = 0;
};

class MercatorTransformCube : public AreaObj {
public:
	MercatorTransformCube(int, const char *pName);

	virtual ~MercatorTransformCube();
	virtual void init(const JMapInfoIter &rIter);

	void convertTransAndRotate(TVec3f *, MtxPtr , const TVec3f &, bool) const;
	f32 getSphereRadius() const;
	void calcUV(TVec2f * pUV, const TVec3f &) const;
	void calcLocalBoxSize(TVec3f *pLocalBoxSize) const;

	/* 0x48 */ TMtx34f mZonePlacementMtx;
};

namespace MR {
	MercatorTransformCube* getMercatorCube();
	f32 calcRailClippingInfoForMercator(TVec3f *, f32 *, LiveActor *, f32, f32);
	void getDivideMercatorRailPosition(DivideMercatorRailPosInfo *, const LiveActor *, u32, f32, u32);
}
