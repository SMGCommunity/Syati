#pragma once

#include "syati-light.h"
#include "Game/LiveActor/LiveActor.h"
#include "Game/Player/GhostPacketReader.h"

class XanimeResourceTable;

class RaceDataReader
{
public:
	RaceDataReader(LiveActor* pActor, const char* pFilename, const XanimeResourceTable* pAnimeTable);

	LiveActor* pActor;
	GhostPacketReader* mPacketReader; //_4
	Mtx _8; //_8

	XanimePlayer* _38; //_38
	XanimePlayer* _3C; //_3C
	bool mUseXanimePlayer; //_40

	void startActionName(const char* pName);
	void startActionHash(u32 hash); //Only supported with XanimePlayer enabled
	void setBckFrame(f32 frame);
	void setTrackWeight(u32 track, f32 weight);
	void setBckRate(f32 rate);
	void setMtxTR();

	bool receivePacket(); //Returns false when data has run out
};