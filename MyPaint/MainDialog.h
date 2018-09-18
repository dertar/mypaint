#pragma once
#include "HWNDHandler.h"
/*
	Wrapper for WinApi HWND
*/
class MainDialog :
	public HWNDHandler
{

public:
	MainDialog(HINSTANCE hInst, const int nCmdShow);
	~MainDialog();

	virtual BOOL init() override;
	virtual BOOL show() override;
};

