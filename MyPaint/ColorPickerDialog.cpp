#include "stdafx.h"
#include "ColorPickerDialog.h"


ColorPickerDialog::ColorPickerDialog(HWND owner, Canvas *canvas,COLORREF def)
{
	this->owner = owner;

	ZeroMemory(&color, sizeof(CHOOSECOLOR));

	acrCustClr[0] = def;

	this->canvas = canvas;
}


ColorPickerDialog::~ColorPickerDialog()
{
}

COLORREF ColorPickerDialog::getColor()
{
	return color.rgbResult;
}

BOOL ColorPickerDialog::init()
{
	color.lStructSize = sizeof(CHOOSECOLOR);
	color.hwndOwner = this->owner;
	color.lpCustColors = (LPDWORD)acrCustClr;
	color.rgbResult = acrCustClr[0];

	color.Flags = CC_FULLOPEN | CC_RGBINIT;
	return TRUE;
}

BOOL ColorPickerDialog::show()
{
	if (ChooseColor(&color) == TRUE)
	{
		this->canvas->setColor(color.rgbResult);
	}
	return TRUE;
}
