#pragma once

#include "revolution.h"
#include "JSystem.h"

class MarioActor;
class Mario;
class MarioState;
class MarioAnimator;

class MarioModule {
public:
	virtual f32 getStickX() const;
	virtual f32 getStickY() const;
	virtual f32 getStickP() const;
	virtual bool checkTrgA() const;
	virtual bool checkLvlA() const;
	virtual bool checkTrgZ() const;
	virtual bool checkLvlZ() const;
	virtual bool checkPreLvlZ() const;
	virtual bool isInputDisable() const;

    void changeAnimation(const char *, const char *);
    void changeAnimation(const char *, u32);
    void changeAnimationUpper(const char *, const char *);
    void changeAnimationNonStop(const char *);
    void stopAnimationUpper(const char *, const char *);
    void playSound(const char *, s32);
    void stopSound(const char *, u32);
	bool isAnimationRun(const char *) const;
	bool isAnimationTerminate(const char *) const;
	const char *getCurrentBckName() const;
	TVec3f &getWorldPadDir() const;
	bool calcWorldPadDir(TVec3f *, f32, f32, bool);

	bool isPlayerModeBee() const;
	bool isPlayerModeFire() const;
	bool isPlayerModeIce() const;
	bool isPlayerModeTeresa() const;
	bool isPlayerModeHopper() const;
	bool isPlayerModeInvincible() const;
	bool isPlayerModeFoo() const;
	bool isPlayerModeYoshi() const;
	bool isPlayerModeCloud() const;
	bool checkSquat(bool);
	bool isStatusActiveID(u32) const;
	bool isStatusActiveS(MarioState *) const;
	bool isSlipFloorCode(s32) const;
	bool isSlipPolygon(const Triangle *) const;
	TVec3f &getVelocity() const;
	TVec3f &getJumpVec() const;
	TVec3f &getTrans() const;
	/*
	* I assume these functions exist at the specified addresses, but they need to be verified.
	* TVec3f &getCamPos() const;	-- assumed 0x803EF570
    * TVec3f &getCamDirX() const;	-- assumed 0x803EF580
    * TVec3f &getCamDirY() const;	-- assumed 0x803EF590
	*/
    TVec3f &getCamDirZ() const;
    TVec3f &getGravityVec() const;
    TVec3f &getAirGravityVec() const;
    TVec3f &getFrontVec() const;
	HitSensor *getSensor(const Triangle *) const;
	f32 marioAcos(f32) const;

	void addVelocity(const TVec3f &);
	void addVelocity(const TVec3f &, f32);
	void addVelocityAfter(const TVec3f &);
	void clearVelocity();
	void cutGravityElementFromJumpVec(bool);
	void cutVecElementFromJumpVec(const TVec3f &);
	void setJumpVec(const TVec3f &) const;
	void playEffect(const char *);
	void playEffectTrans(const char *, const TVec3f &);
	void playEffectRT(const char *, const TVec3f &, const TVec3f &);
	void playEffectRTZ(const char *, const TVec3f &, const TVec3f &);
	void playEffectRTW(const char *, const TVec3f &, const TVec3f &);
	void playEffectSRT(f32, const char *, const TVec3f &, const TVec3f &);
	void stopEffect(const char *);
	void stopEffectForce(const char *);
	void startCamVib(u32);
	void startPadVib(u32);
	void startPadVib(const char *);
	void calcAngleD(const TVec3f &) const;
	void calcPolygonAngleD(const Triangle *) const;
	bool sendPunch(HitSensor *, bool);

	Mario* getPlayer() const;
	MarioAnimator *getAnimator() const;
	u16 getPlayerMode() const;
	MarioActor* mMarioActor; // _4
};