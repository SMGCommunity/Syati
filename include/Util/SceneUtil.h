#pragma once

class LiveActor;

namespace MR
{
	const char* getCurrentStageName();
	bool isEqualSceneName(const char *);
	bool isEqualStageName(const char *);

	s32 getChildObjNum(const JMapInfoIter &);
	void getChildObjName(const char **, const JMapInfoIter &, int);

	void initChildObj(NameObj *, const JMapInfoIter &, int);
};
