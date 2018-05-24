#pragma once
#include "stdafx.h"


struct MainLoop {

	MainLoop& setHInstace(HINSTANCE hInstance);

	MainLoop& run() {
		try { for (;;)oneStep(); }
		catch (EndLoopException e) {

		}
		return *this;
	}

	MainLoop() :hAccelTable(NULL) {
	}

	int result() {
		return (int)currentMsg.wParam;
	}

private:
	class EndLoopException {};
	void grabMsg() {
		BOOL bRet = GetMessage(&currentMsg, nullptr, 0, 0);
		if ((bRet == 0) || (bRet == -1)) throw   EndLoopException();

	}

	void oneStep() {
		grabMsg();
		handleMsg();
	}
	void handleMsg() {
		if (!TranslateAccelerator(currentMsg.hwnd, hAccelTable, &currentMsg)) {
			TranslateMessage(&currentMsg);
			DispatchMessage(&currentMsg);
		}
	}
	HACCEL hAccelTable;
	MSG currentMsg;
};