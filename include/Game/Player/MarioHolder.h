#pragma once

#include "revolution.h"
#include "Game/Player/MarioActor.h"

class MarioHolder : public NameObj {
public:
	MarioHolder();

	virtual ~MarioHolder();

	void setMarioActor(MarioActor *);
	MarioActor* getMarioActor() const;

	MarioActor* mMarioActor; // _14
	bool mCreateBee; // _18
	bool mCreateHopper; // _19
	bool mCreateFire; // _1A
	bool mCreateIce; // _1B
	bool mCreateInvincible; // _1C
	bool mCreateTeresa; // _1D
	bool mCreateTornado; // _1E
	bool _1F;
	bool mCreateYoshi; // _20
	bool mCreateYoshiBalloon; // _21
	bool mCreateCloud; // _22
	bool mCreateRock; // _23
	bool mCreateHairAndHead; // _24
	bool mCreateFreezeIce; // _25
};

namespace MR {
	MarioHolder* getMarioHolder();
	void enablePlayerResourceBee();
	void enablePlayerResourceHopper(const JMapInfoIter&);
	void enablePlayerResourceFire();
	void enablePlayerResourceIce();
	void enablePlayerResourceInvincible(const JMapInfoIter&);
	void enablePlayerResourceTeresa();
	void enablePlayerResourceTornado(const JMapInfoIter&);
	void enablePlayerResourceYoshi(const JMapInfoIter&);
	void enablePlayerResourceYoshiBaloon(const JMapInfoIter&);
	void enablePlayerResourceCloud(const JMapInfoIter&);
	void enablePlayerResourceRock();
	void enablePlayerResourceHairAndHead(const JMapInfoIter&);
	void enablePlayerResourceFreezeIce(const JMapInfoIter&);
	void enablePlayerResourceMorph(const JMapInfoIter&);
	void enablePlayerResourceMeramera(const JMapInfoIter&); // unconfirmed name
	void enablePlayerResourceBasaBasa(const JMapInfoIter&); // unconfirmed name
	bool isCreatePlayerResourceBee();
	bool isCreatePlayerResourceHopper();
	bool isCreatePlayerResourceFire();
	bool isCreatePlayerResourceIce();
	bool isCreatePlayerResourceInvincible();
	bool isCreatePlayerResourceTeresa();
	bool isCreatePlayerResourceTornado();
	bool isCreatePlayerResourceYoshi();
	bool isCreatePlayerResourceYoshiBaloon();
	bool isCreatePlayerResourceCloud();
	bool isCreatePlayerResourceRock();
	bool isCreatePlayerResourceHairAndHead();
	bool isCreatePlayerResourceFreezeIce();
	void enablePlayerResourceHopperComet();
	void enablePlayerResourceInvincibleComet();
	void enablePlayerResourceNoHat();
};
