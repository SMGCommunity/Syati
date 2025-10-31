#pragma once

#include "Game/Boss/PoltaActionBase.h"

class Polta;

class PoltaDemo : public PoltaActionBase {
public:
	PoltaDemo(Polta*);

	virtual void init();
	virtual void control(); // empty function in-game

	const Nerve* _14;
	const char* _18;
	const char* _1C; // New to SMG2
};