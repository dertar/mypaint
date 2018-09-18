#pragma once
#include "IHandleDialog.h"
#include "Canvas.h"

/*
	Wrapper for WinApi ColorDialog
*/
class ColorPickerDialog :
	public IHandleDialog
{
private:
	COLORREF acrCustClr[16];
	CHOOSECOLOR color;
	HIMAGELIST g_hImageList = NULL;
	HWND owner;
	Canvas *canvas;

public:
	ColorPickerDialog(HWND owner, Canvas *canvas, COLORREF def = RGB(0,0,0));
	~ColorPickerDialog();

	COLORREF getColor();


	virtual BOOL init() override;
	// if user picked a Color,
	// that Color will be changed in Canvas entity also
	virtual BOOL show() override;
};

