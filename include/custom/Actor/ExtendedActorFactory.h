#pragma once

#include "kamek.h"
#include "NameObj/NameObjFactory.h"
#include "custom/Actor/MyFirstActor.h"
#include "os.h"

// ensure you bump up this value when you add more actors!
#define NUM_ACTORS 0x1

namespace ExtendedActorFactory
{
    template<typename T>
    NameObj* createExtActor(const char *pActorName);

	// change me to your custom actor!
    template<>
    NameObj* createExtActor<MyFirstActor>(const char *pActorName)
    {
        return new MyFirstActor("MyFirstActor");
    }

    const ActorEntry cCreateTable[NUM_ACTORS] =
    {
        { "MyFirstActor", createExtActor<MyFirstActor> }
    };
};