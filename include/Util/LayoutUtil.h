#pragma once

class LayoutUtil;

namespace MR {
	void setTextBoxFormatRecursive(LayoutActor* layout, const char* paneName, const wchar_t* string ...);

	void hidePaneRecursive(LayoutActor *pLayout, const char *pPaneName);
};
