#pragma once

#include "Game/AreaObj/CubeCameraArea.h"
#include "Game/NameObj/NameObj.h"
#include "JSystem/JGeometry.h"

class CameraTargetObj : public NameObj {
public:
    CameraTargetObj(const char*);

    virtual inline ~CameraTargetObj() {

    }

    virtual void init(const JMapInfoIter&);

    virtual const TVec3f* getPosition() const = 0;
    virtual const TVec3f* getUpVec() const = 0;
    virtual const TVec3f* getFrontVec() const = 0;
    virtual const TVec3f* getSideVec() const = 0;
    virtual const TVec3f* getLastMove() const = 0;
    virtual const TVec3f* getGroundPos() const = 0;
    virtual const TVec3f* getGravityVector() const = 0;

    virtual f32 getRadius() const;
    virtual bool isTurning() const;
    virtual bool isJumping() const;
    virtual bool isLongDrop() const;
    virtual bool isFastDrop() const;
    virtual bool isFastRise() const;
    virtual bool isWaterMode() const;
    virtual bool isOnWaterSurface() const;
    virtual bool isBeeMode() const;
    virtual bool isFooFighterMode() const;
    virtual u32 getSpecialMode() const;
    virtual bool isCameraStateOn(unsigned long) const;
    virtual CubeCameraArea* getCubeCameraArea() const;
    //virtual Triangle* getGroundTriangle() const;
    //virtual GravityInfo* getGravityInfo() const;
    virtual void enableCameraWall();
    virtual void disableCameraWall();
    virtual void setCameraWall(bool);
    virtual bool isDebugMode() const;
    virtual MtxPtr getMapBaseMtx() const;
    virtual void resetStatus();

    bool mCameraWall;   // _C
};