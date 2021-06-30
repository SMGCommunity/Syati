#pragma once

#include "Actor/Nerve/NerveExecutor.h"
#include "Scene/SceneNameObjListExecutor.h"
#include "Scene/SceneObjHolder.h"

class Scene : public NerveExecutor
{
public:
	Scene(const char *);

	virtual ~Scene();
	virtual void init();
	virtual void start();
	virtual void update() const;
	virtual void calcAnim();

	void initNameObjListExecutor();
	void initSceneObjHolder();

	SceneNameObjListExecutor* mNameObjListExecutor; // _8
	s32 _C; // unused?
	SceneObjHolder* mSceneObjHolder; // _10
};
