#pragma once

#include "syati.h"

class ScenarioTitle : public LayoutActor {
public:
    ScenarioTitle(void);
    virtual ~ScenarioTitle();
    virtual void init(const JMapInfoIter&);
    void start(void);
    void end(void);
    void exeAppear(void);
    void exeEnd(void);
};

namespace NrvScenarioTitle {
    NERVE(ScenarioTitleNrvAppear);
    NERVE(ScenarioTitleNrvWait);
    NERVE(ScenarioTitleNrvEnd);
};