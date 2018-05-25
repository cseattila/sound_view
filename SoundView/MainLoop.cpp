#include "stdafx.h"
#include "MainLoop.h"
#include "resource.h"

MainLoop::MainLoop(LPCTSTR lpTableName) :hAccelTable(NULL), lpTableName(lpTableName){
}

MainLoop& MainLoop::setHInstace(HINSTANCE hInstance) {
	hAccelTable = LoadAccelerators(hInstance, lpTableName);
	return *this;
}

MainLoop & MainLoop::run() try {
	for (;;) oneStep();
}
catch (const EndLoopException&) {
	return *this;
}

int MainLoop::result() {
	return (int)currentMsg.wParam;
}

void MainLoop::grabMsg() {
	BOOL bRet = GetMessage(&currentMsg, nullptr, 0, 0);
	if ((bRet == 0) || (bRet == -1)) throw   EndLoopException();
}

void MainLoop::oneStep() {
	grabMsg();
	handleMsg();
}

void MainLoop::handleMsg() {
	if (!TranslateAccelerator(currentMsg.hwnd, hAccelTable, &currentMsg)) {
		TranslateMessage(&currentMsg);
		DispatchMessage(&currentMsg);
	}
}



