#pragma once

#include "Game/Screen/SimpleLayout.h"
#include "revolution/types.h"

class MapGalaxyZoomButton : public SimpleLayout {
public:
    MapGalaxyZoomButton();

    virtual ~MapGalaxyZoomButton();
    virtual void init(const JMapInfoIter&);
    virtual void appear();
	virtual void kill();
	virtual void control();

    void show();

    u32 _2C;
    const char* _30;
    const char* _34;
};