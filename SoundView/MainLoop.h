#pragma once
#include "stdafx.h"


struct MainLoop {

	MainLoop(LPCTSTR lpTableName);

	MainLoop& setHInstace(HINSTANCE hInstance);

	MainLoop& run();
		
	int result();

private:
	class EndLoopException {};
	
	void grabMsg();

	void oneStep();

	void handleMsg();

	HACCEL hAccelTable;
	MSG currentMsg;

	LPCTSTR lpTableName;
};