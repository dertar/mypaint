#pragma once

#include "MyPaint.h"
#include "Canvas.h"
#include "MainDialog.h"
#include "ToolbarPanel.h"
#include "ColorPickerDialog.h"

/*
	Creates a window that handles HWNDs, HINSTANCE, Canvas.
*/

class MyWindow :
	public IHandleDialog
{
private:
	HINSTANCE hInst;
	int nCmdShow;

	PAINTSTRUCT ps;
	HDC hdc;

	MainDialog *window;
	ToolbarPanel *panel;
	ColorPickerDialog *colorPicker;

	Canvas *canvas;
	 
	ATOM myRegisterClass();

	// get current point from current position of mouse 
	void getCurrentPoint(POINT &point, LPARAM lParam);

	LRESULT CALLBACK    MyWndProc(HWND, UINT, WPARAM, LPARAM);
	// lazy init for WNDPROC (WinApi requires)
	static MyWindow *instance;
public:
	MyWindow(HINSTANCE hInstance, int nCmdShow);
	~MyWindow();
	static LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
	
	virtual BOOL show() override;
	virtual BOOL init() override;
};
