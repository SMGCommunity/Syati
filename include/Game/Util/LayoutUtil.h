#pragma once

#include "revolution.h"

class LayoutActor;
class IconAButton;
class ResourceHolder;
class LayoutGroupCtrl;
class LayoutPaneCtrl;
struct TextBoxRecursiveOperation;
class SimpleLayout;
class Nerve;

namespace MR {
	ResourceHolder* createAndAddLayoutHolder(const char*);
	ResourceHolder* createAndAddLayoutHolderRawData(const char*);
	LayoutPaneCtrl* createAndAddPaneCtrl(LayoutActor* pLayout, const char* pPaneName, u32 animTrackCount);
	LayoutGroupCtrl* createAndAddGroupCtrl(LayoutActor* pLayout, const char* pPaneName, u32 animTrackCount);

	bool isExistPaneCtrl(LayoutActor*, const char*);
	// one unknown function

	void setInfluencedAlphaToChild(const LayoutActor*);
	void setLayoutAlphaFloat(const LayoutActor*, f32);

	void executeTextBoxRecursive(LayoutActor*, const char*, const TextBoxRecursiveOperation&);

	void setTextBoxSystemMessageRecursive(LayoutActor* pLayout, const char* pPaneName, const char* pMessageLabel);
	void setTextBoxGameMessageRecursive(LayoutActor* pLayout, const char* pPaneName, const char* pMessageLabel);
	void setTextBoxNumberRecursive(LayoutActor* pLayout, const char* pPaneName, s32 value);
	void setTextBoxMessageRecursive(LayoutActor* pLayout, const char* pPaneName, const wchar_t* value);
	void setTextBoxFormatRecursive(LayoutActor* pLayout, const char* pPaneName, const wchar_t* format ...);
	void setTextBoxArgNumberRecursive(LayoutActor* pLayout, const char* pPaneName, s32, s32);
	void setTextBoxArgStringRecursive(LayoutActor* pLayout, const char* pPaneName, const wchar_t*, s32);
	void setTextBoxVerticalPositionCenterRecursive(LayoutActor* pLayout, const char* pPaneName);
	void setTextBoxVerticalPositionBottomRecursive(LayoutActor* pLayout, const char* pPaneName);
	void clearTextBoxMessageRecursive(LayoutActor* pLayout, const char* pPaneName);
	void updateClearTimeTextBox(LayoutActor* pLayout, const char*, u32);
	void updateMinuteAndSecondTextBox(LayoutActor* pLayout, const char*, u32);

	void calcTextBoxRectRecursive(TBox2f*, const LayoutActor*, const char*);
	// setTextBoxFontRecursive

	void showPane(LayoutActor* pLayout, const char* pPaneName);
	void showPaneRecursive(LayoutActor* pLayout, const char* pPaneName);
	void hidePane(LayoutActor* pLayout, const char* pPaneName);
	void hidePaneRecursive(LayoutActor* pLayout, const char* pPaneName);
	bool isHiddenPane(const LayoutActor* pLayout, const char* pPaneName);
	void showScreen(LayoutActor* pLayout);
	void hideScreen(LayoutActor* pLayout);

	// various more functions here...

	void startAnim(LayoutActor* pLayout, const char* pAnimName, u32);
	void startAnimAtFirstStep(LayoutActor*, const char* pAnimName, u32);
	void startPaneAnim(LayoutActor* pLayout, const char* pPaneName, const char* pAnimName, u32 animTrackId);
	void startPaneAnimAtStep(LayoutActor* pLayout, const char* pPaneName, const char* pAnimName, s32 step, u32 animTrackId);
	void startPaneAnimAtFirstStep(LayoutActor* pLayout, const char* pPaneName, const char* pAnimName, u32 animTrackId);
	void startAnimAndSetFrameAndStop(LayoutActor* pLayout, const char* pAnimName, f32 frame, u32);
	void startPaneAnimAndSetFrameAndStop(LayoutActor* pLayout, const char* pPaneName, const char* pAnimName, f32 frame, u32 animTrackId);
	void setAnimFrameAndStop(LayoutActor* pLayout, f32, u32);
	void setAnimFrameAndStopAtEnd(LayoutActor* pLayout, u32);
	void setAnimFrameAndStopAdjustTextWidth(LayoutActor* pLayout, const char*, u32);
	void setAnimFrameAndStopAdjustTextHeight(LayoutActor* pLayout, const char*, u32);
	void setPaneAnimFrameAndStop(LayoutActor* pLayout, const char* pPaneName, f32 frame, u32 animTrackId);
	void setAnimFrame(LayoutActor* pLayout, f32 frame, u32);
	void setPaneAnimFrame(LayoutActor* pLayout, const char* pPaneName, f32 frame, u32 animTrackId);
	void setAnimRate(LayoutActor* pLayout, f32 rate, u32);
	void setPaneAnimRate(LayoutActor* pLayout, const char* pPaneName, f32 rate, u32 animTrackId);
	void stopAnim(LayoutActor* pLayout, u32);
	void stopPaneAnim(LayoutActor* pLayout, const char* pPaneName, u32 animTrackId);
	bool isAnimStopped(const LayoutActor* pLayout, u32);
	bool isPaneAnimStopped(const LayoutActor* pLayout, const char* pPaneName, u32 animTrackId);
	f32 getAnimFrame(const LayoutActor* pLayout, u32);
	f32 getPaneAnimFrame(const LayoutActor* pLayout, const char* pPaneName, u32 animTrackId);
	f32 getAnimFrameMax(const LayoutActor* pLayout, u32);
	f32 getPaneAnimFrameMax(const LayoutActor* pLayout, const char* pPaneName, u32 animTrackId);
	f32 getAnimFrameMax(const LayoutActor* pLayout, const char* pAnimName);
	//getAnimCtrl
	//getPaneAnimCtrl
	void emitEffect(LayoutActor*, const char*);
	void deleteEffect(LayoutActor*, const char*);
	void forceDeleteEffect(LayoutActor*, const char*);
	void deleteEffectAll(LayoutActor*);
	void forceDeleteEffectAll(LayoutActor*);
	void setEffectHostMtx(LayoutActor*, const char*, MtxPtr);
	void setEffectRate(LayoutActor*, const char*, f32);
	void setEffectDirectionalSpeed(LayoutActor*, const char*, f32);
	void pauseOffEffectAll(LayoutActor*);
	bool isRegisteredEffect(const LayoutActor*, const char*);

	void setFollowPos(const TVec2f*, const LayoutActor*, const char*);
	void setFollowTypeReplace(const LayoutActor* pLayout, const char* pStr);
	void setFollowTypeAdd(const LayoutActor* pLayout, const char* pStr);
	void copyPaneTrans(TVec2f*, const LayoutActor*, const char*);

	bool isStep(const LayoutActor* pLayout, s32 step);
	bool isFirstStep(const LayoutActor* pLayout);
	bool isLessStep(const LayoutActor* pLayout, s32 step);
	bool isGreaterStep(const LayoutActor* pLayout, s32 step);
	bool isGreaterEqualStep(const LayoutActor* pLayout, s32 step);
	bool isIntervalStep(const LayoutActor* pLayout, s32 step);
	bool isNewNerve(const LayoutActor* pLayout);
	f32 calcNerveEaseInRate(const LayoutActor* pLayout, s32);
	f32 calcNerveEaseInValue(const LayoutActor* pLayout, s32, s32, f32, f32);
	f32 calcNerveEaseOutValue(const LayoutActor* pLayout, s32, f32, f32);

	void setNerveAtStep(LayoutActor* pLayout, const Nerve* pNerve, s32 step);
	void setNerveAtAnimStopped(LayoutActor* pLayout, const Nerve* pNerve, u32);
	void setNerveAtPaneAnimStopped(LayoutActor* pLayout, const char* pPaneName, const Nerve* pNerve, u32);
	void killAtAnimStopped(LayoutActor* pLayout, u32);

	bool isDead(const LayoutActor* pLayout);
	bool isHiddenLayout(const LayoutActor* pLayout);
	void showLayout(LayoutActor* pLayout);
	void hideLayout(LayoutActor* pLayout);

	bool isStopAnimFrame(const LayoutActor* pLayout);
	void stopAnimFrame(LayoutActor* pLayout);
	void releaseAnimFrame(LayoutActor* pLayout);
	void onCalcAnim(LayoutActor* pLayout);
	void offCalcAnim(LayoutActor* pLayout);
	bool isExecuteCalcAnimLayout(const LayoutActor* pLayout);
	bool isExecuteDrawLayout(const LayoutActor* pLayout);

	SimpleLayout* createSimpleLayout(const char*, const char*, u32);
	SimpleLayout* createSimpleLayoutTalkParts(const char*, const char*, u32);
	IconAButton* createAndSetupIconAButton(LayoutActor* pLayout, bool, bool);

	// getPane
	// getRootPane

	// calcTextBoxRectRecursive
	u32 getTextLineNumMaxRecursive(const LayoutActor* pLayout, const char*);
	void invalidateParentAnim(LayoutActor* pLayout);
};
