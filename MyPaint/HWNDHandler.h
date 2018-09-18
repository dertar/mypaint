#pragma once
#include "IHandleDialog.h"

/*
	Wrapper for WinApi HWND
*/

class HWNDHandler :
	public IHandleDialog
{
protected:
	HINSTANCE hInst;
	HWND hWnd;
	HWND parent;
	int nCmdShow;

public:
	HWNDHandler(HINSTANCE hInst, HWND parent = NULL, const int nCmdShow = SW_SHOW);

	HWND getHWND();
	virtual ~HWNDHandler();
};

