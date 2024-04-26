#pragma once

#include "Game/Camera/CameraParamChunkID.h"
#include "Game/NameObj/NameObj.h"
#include "JSystem/JGeometry.h"

class CameraCover;
class CameraDirector;
class CameraHolder;
class CameraMan;
class CameraManGame;
class CameraManEvent;
class CameraManPause;
class CameraManSubjective;
class CameraParamChunkEvent;
class CameraParamChunkHolder;
class CameraPoseParam;
class CameraRailHolder;
class CameraRegisterHolder;
class CameraRotChecker;
class CameraTargetHolder;
class CameraShaker;
class CameraTargetArg;
class CameraTargetMtx;
class CameraTargetObj;
class CameraViewInterpolator;
class GameCameraCreator;
class LiveActor;
class MarioActor;
class OnlyCamera;

namespace MR {
    CameraDirector* getCameraDirector();
}

class CameraParamChunkID_Tmp : public CameraParamChunkID {
public:
    inline CameraParamChunkID_Tmp() : CameraParamChunkID() {

    }

    virtual char* getBuffer(unsigned long);

    char mBuffer[0x100]; // _C
};

#define CAMERA_MAN_CAPACITY 8

class CameraDirector : public NameObj {
public:
    class CameraManStack {
    public:
        inline CameraManStack() {
            mElements = new CameraMan * [CAMERA_MAN_CAPACITY];
            mCapacity = CAMERA_MAN_CAPACITY;
            mCount = 0;
            mElements = new CameraMan * [CAMERA_MAN_CAPACITY];
        }

        CameraMan** mElements;
        u32 mCapacity;
        u32 mCount;
    };

    CameraDirector(const char*);
    virtual ~CameraDirector();

    virtual void init(const JMapInfoIter&);
    virtual void movement();

    void setTarget(CameraTargetObj*);
    CameraTargetObj* getTarget();
    void push(CameraMan*);
    CameraMan* pop();
    void backLastMtx();
    CameraMan* getCurrentCameraMan() const;
    void updateCameraMan();
    void calcPose();
    void calcSubjective(); // TODO
    bool isInterpolationOff();
    void switchAntiOscillation();
    void createViewMtx();
    void checkStartCondition();
    void startEvent(long, const char*, const CameraTargetArg&, long);
    void endEvent(long, const char*, bool, long);
    void endEventAtLanding(long, const char*, long); // TODO, need more info on _5C
    CameraParamChunkEvent* getEventParameter(long, const char*);
    void requestToResetCameraMan();
    void setInterpolation(unsigned long);
    void cover(unsigned long);
    void closeCreatingCameraChunk();
    void initCameraCodeCollection(const char*, long);
    void registerCameraCode(unsigned long);
    void termCameraCodeCollection();
    void declareEvent(long, const char*);
    void started();
    void setTargetActor(const LiveActor*);
    void setTargetPlayer(const MarioActor*);
    bool isRotatingHard() const;
    bool isSubjectiveCamera() const;
    bool isEnableToControl() const;
    bool isEnableToRoundLeft() const;
    bool isEnableToRoundRight() const;
    bool isEnableToReset() const;
    bool isEventCameraActive(long, const char*) const;
    bool isEventCameraActive() const;
    void startStartPosCamera(bool);
    bool isInterpolatingNearlyEnd() const;
    bool isForceCameraChange() const;
    f32 getDefaultFovy() const;
    void startStartAnimCamera();
    bool isStartAnimCameraEnd() const;
    u32 getStartAnimCameraFrame() const;
    void endStartAnimCamera();
    void startTalkCamera(const TVec3f&, const TVec3f&, float, float, long);
    void endTalkCamera(bool, long);
    void startSubjectiveCamera(long);
    void endSubjectiveCamera(long);
    bool isAnimCameraEnd(long, const char*) const;
    u32 getAnimCameraFrame(long, const char*) const;
    void pauseOnAnimCamera(long, const char*);
    void pauseOffAnimCamera(long, const char*);
    void zoomInGameCamera();
    void zoomOutGameCamera();
    void checkEndOfEventCamera();
    void controlCameraSE();
    void removeEndEventAtLanding(long, const char*);
    void calcViewMtxFromPoseParam(TPos3f*, const CameraPoseParam*);
    bool isPlayableCameraSE(bool);
    void resetCameraMan();
    void createStartAnimCamera();
    void createTalkCamera();
    void createSubjectiveCamera();

    // _164[0] and _164[1] seems to be a struct of size 0x88 with the following layout:
    // 0x00: mZoneID
    // 0x04: mName
    // 0x84: unknown

    // These are the only members which have been found accessed

    CameraTargetObj* _14;
    CameraManStack* mStack;                     // _18
    OnlyCamera* mOnlyCamera;                    // _1C
    CameraPoseParam* mPoseParam1;               // _20
    CameraPoseParam* mPoseParam2;               // _24
    CameraHolder* mHolder;                      // _28
    CameraParamChunkHolder* mChunkHolder;       // _2C
    GameCameraCreator* mCameraCreator;          // _30
    CameraRailHolder* mRailHolder;              // _34
    CameraRegisterHolder* mRegisterHolder;      // _38
    CameraTargetHolder* mTargetHolder;          // _3C
    CameraShaker* mShaker;                      // _40
    CameraViewInterpolator* mViewInterpolator;  // _3C
    CameraCover* mCover;                        // _48
    CameraRotChecker* mRotChecker;              // _4C
    CameraManGame* mCameraManGame;              // _50
    CameraManEvent* mCameraManEvent;            // _54
    CameraManPause* mCameraManPause;            // _58
    CameraManSubjective* mCameraManSubjective;  // _5C
    bool _60;
    u8 _61[3];
    s32 _64[2][34];
    u32 _174;
    bool _178;
    u8 _179[3];
    s32 _17C;
    bool mStartCameraCreated;                   // _180
    u8 _181[3];
    CameraTargetMtx* mTargetMatrix;             // _184
    TMtx34f _188;
    bool mRequestCameraManReset;                // _1B8
    bool _1B9;
    bool mIsSubjectiveCamera;                   // _1BA
    bool _1BB;
    s32 _1BC;
    u8 _1C0[4];
    f32 _1C4;
    TPos3f _1C8;
    bool _1F8;
    bool _1F9;
    bool _1FA;
    u8 _1FB;
};