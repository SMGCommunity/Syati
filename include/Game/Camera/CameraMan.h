#pragma once

#include "Game/NameObj/NameObj.h"

class CameraDirector;
class CameraPoseParam;

class CameraMan : public NameObj {
public:
    CameraMan(const char *);
    
    virtual inline ~CameraMan() {

    }

    virtual void init(const JMapInfoIter &);
    virtual void movement();

    virtual void calc();
    virtual void notifyActivate();
    virtual void notifyDeactivate();
    virtual bool isInterpolationOff() const;
    virtual bool isCollisionOff() const;
    virtual bool isZeroFrameMoveOff() const;
    virtual bool isSubjectiveCameraOff() const;
    virtual bool isCorrectingErpPositionOff() const;
    virtual bool isEnableToReset() const;
    virtual bool isEnableToRoundLeft() const;
    virtual bool isEnableToRoundRight() const;
    virtual void roundLeft();
    virtual void roundRight();

    void owned(CameraDirector *);
    void released(CameraDirector *);
    void activate(CameraDirector *);
    void deactivate(CameraDirector *);

    CameraDirector *mDirector;      // 0x14
    CameraPoseParam *mPoseParam;    // 0x18
    bool mIsActivated;              // 0x1C
    bool _1D;
    u8 _1E[2];
    TMtx34f mMatrix;                // 0x20
};