# Actor Tutorials
### What counts as an actor?
All complex objects in SMG1 and SMG2 inherit from the `LiveActor` class. Generally, anything that is not listed in the ProductMapObjDataTable is considered an actor.
> *This tutorial requires [Syati](https://github.com/SMGCommunity/Syati) and its dependencies.*
### Creating your own actor
In a new C++ header file, we first create the class of our actor:
```cpp
#pragma once
#include "Game/LiveActor.h"

class CustomActor : public LiveActor {
public:
    CustomActor(const char *pName);
    virtual void init(const JMapInfoIter &rIter);
    virtual void movement();
    virtual void control();
};
```
This header file can be placed anywhere in the include/ directory.
Now, inside the source/ directory, create a new C++ file and include your class:
```cpp
#include "CustomActor.h"
#include "Game/Util.h"

CustomActor::CustomActor(const char *pName) : LiveActor(pName) {
	
}
```
The `constructor` (ctor) gets called when the actor first gets created. For creating *placeable* objects, you have to inherit `LiveActor::LiveActor`.

Both `movement` and `control` are called on every frame, feel free to place in your own code there.

The `init` function gets called on the first frame the actor exists, and this is what it should look like:
```cpp
void CustomActor::init (const JMapInfoIter &rIter) {
	MR::processInitFunction(this, rIter, false);
	MR::connectToSceneMapObj(this);
	LiveActor::makeActorAppeared();
	MR::validateClipping(this);
}
```
`MR::processInitFunction` does basic actor initialization. You can also call it with a model name instead of a JMapInfoIter, but using the Iter is recommended.

`MR::connectToSceneMapObj` places the object at the position set in the StageData.

However, it **does not** make it visible, so for visible actors, you also need to call `LiveActor::makeActorAppeared`. If your actor is supposed to be invisible, you can remove this line.

Finally, we call `MR::validateClipping` to make the actor disappear when the player is far enough away. If you want it to always stay visible, call `MR::invalidateClipping` instead.


Now, to make the game recognize our new actor, we need to use the `ExtNameObjFactory`. Open its header file in the include/ directory. First, include your header file at the top:
```cpp
#include "CustomActor.h"
```
Now, in the `cNewCreateNameObjTable`, add this:
```cpp
{ "Custom", createExtActor<CustomActor> }
```
This makes the game know what your actor is called. From now on, placing a `Custom` object in the level will spawn in your actor.
**If your actor is visible, make sure you also have a Custom.arc file in the ObjectData/ folder of SMG2.**
### About HitSensors
To make the player be able to interact with your actor, you need to set up a HitSensor. HitSensors are always spherical, and you need to specify a radius in game units when creating it.
Add the following to your init function:
```cpp
initHitSensor(1);
MR::addHitSensorMapObj(this, "Body", 8, 100.0f, TVec3f(0.0f, 0.0f, 0.0f));
```
Firstly, we initialize exactly one HitSensor. Then we add it to our object with the following parameters:
- `this` is a pointer to our custom actor.
- `"Body"` is the name of the sensor we want to apply. When using multiple HitSensors, you can use this to distinguish between them.
- `8` represents the receiverCount. This specifies how many objects can interact with the HitSensor at once.
- `100.0f` is the radius of the HitSensor, in this case 100 units.
- `TVec3f(0.0f, 0.0f, 0.0f)` represents the offset from the main actor. Here we simply create a new 0, 0, 0 vector so that the HitSensor gets placed at the origin of our actor.
Now we also need to handle something colliding with that HitSensor. To do that, first add the following to your header file:
```cpp
class CustomActor : public LiveActor {
public:
	// ...
	virtual bool receiveMsgPlayerAttack(u32, HitSensor *, HitSensor *);
	// ...
}
```
After that, to actually define the function, place this function into your C++ file:
```cpp
bool CustomActor::receiveMsgPlayerAttack (u32 msg, HitSensor *pSender, HitSensor *pReceiver) {

}
```
Here we are given the type of collision that occured (msg), as well as two HitSensor pointers.

To figure out what the sender is, you can call one of the 25 `MR::isSensor...` functions. When checking for the player, using `MR::isSensorPlayerOrYoshiOrRide(pSender)` is recommended.

To figure out what type of interaction ocurred, use one of the 105 `MR::isMsg` functions. For example, the player spin-attacking your actor can be checked by calling `MR::isMsgPlayerSpinAttack(msg)`.

Remember that the function has to return a bool. This is needed to let the sender of the message know that there was an interaction (`true`) or if it was simply ignored (`false`). For example, if the player interacts with it and true is returned, a certain particle effect will be created to show the impact.
> To see which functions best fit your purpose, look at the HitSensor.h file in Syati's include/Game/LiveActor directory.</div>
### About Collision
Some actors also feature collision on top of a HitSensor, which needs to be initialized seperately.
To do that, add this to the init function of your actor:
```cpp
MR::initCollisionParts(this, "Custom", getSensor("body"), nullptr);
```
This function gets passed the following arguments:

- `this` is a pointer to our custom actor.
- `"Custom"` is the name of the collision file that the game should use. In this case, the game uses the Custom.kcl file in ObjectData/Custom.arc.
- `getSensor("Body")` is needed to let the game know where to place the CollisionParts. Here we simply get the sensor we just created named "Body".
- `nullptr` is usually a MtxPtr. When given a valid MtxPtr, the game will tie the collision to that matrix. Otherwise, it stays at the HitSensor's position.

Now, if you want the actor to have collision, you probably also want it to interact with walls, floors and ceilings. To do that, initialize a binder:
```cpp
initBinder(100.0f, 0.0f, 0);
```
The first argument should match the radius of your HitSensor. Now your actor will no longer pass through walls or floor, and you can check its state by running any of the `MR::isBinded...` functions.
### Using ActorInfo
You can eliminate the need for a bunch of code in your `init` function by using a few ActorInfo bcsv files. Here is an example of a InitActor.bcsv from the [Project Template Debug](https://github.com/Lord-G-INC/SMG2-Project-Template)'s RedCoin:
![image](https://media.discordapp.net/attachments/1119750120657911849/1150562740436471950/image.png?width=833&height=359)
Here's a breakdown of what these entries do:
- *DefaultPos* will call `MR::initDefaultPos` if Data is set to o (equivalent of true).
- *Executor* will call `MR::connectToScene<Type><Light>` with <Type> being what Data is.
- *Light* will call `MR::connectToScene<Type><Light>` with <Light> being what Data is (in this example, `MR::connectToSceneItemStrongLight`).
- *Model* tells the game what model to load in and from what file.
- *Rail* tells the game whether your actor uses a path. Setting Data to an empty string means it will not use a path, using `Use` means it can use one, and using `Needs` means it has to use one.
- *Binder* will call `initBinder(<radius>, ...)` with <radius> being what Param00F32 is.
- *StarPointer* will call `initStarPointerTarget`, to make it a target for the Star Pointer if the Data field is set to o. Here it is set to x however (equivalent of false).
- *Sound* will specify the sound group to use.
- *Clipping* specifies at what distance the object is far enough away to disappear.
- *DebugNode* is useless lol.
- *UseScaleForParam* allows you to specify whether the actor should scale or not.