#pragma once

class ScenarioData;

class GalaxyStatusAccessor
{
public:
	GalaxyStatusAccessor(const ScenarioData *);

	ScenarioData* mScenarioData;
};

namespace MR
{
	GalaxyStatusAccessor makeGalaxyStatusAccessor(const char *);
};
