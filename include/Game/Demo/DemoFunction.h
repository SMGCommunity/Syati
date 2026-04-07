#pragma once

class LiveActor;
class DemoDirector;
class DemoCastGroupHolder;
class DemoExecutor;
class TalkMessageCtrl;

namespace DemoFunction {
    void registerDemoTalkMessageCtrl(LiveActor*, TalkMessageCtrl*);
};
