#pragma once
#include "IHandleDialog.h"

/*
	Wrapper for WinApi HWND
*/

class HWNDHandler :
	public IHandleDialog
{
protected:
	HINSTANCE hInst = NULL;
	HWND hWnd = NULL;
	HWND parent = NULL;
	int nCmdShow = SW_SHOW;

public:
	HWNDHandler(HINSTANCE hInst, HWND parent = NULL, const int nCmdShow = SW_SHOW);

	HWND getHWND();
	virtual ~HWNDHandler();
};

