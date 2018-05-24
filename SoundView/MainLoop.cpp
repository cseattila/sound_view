#include "stdafx.h"
#include "MainLoop.h"
#include "resource.h"

MainLoop& MainLoop::setHInstace(HINSTANCE hInstance) {
	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_SOUNDVIEW));
	return *this;
}

