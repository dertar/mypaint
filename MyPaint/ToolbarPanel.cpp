#include "stdafx.h"
#include "ToolbarPanel.h"


ToolbarPanel::ToolbarPanel(HINSTANCE hInst, HWND parent, const int nCmdShow)
	: HWNDHandler(hInst, parent, nCmdShow)
{
	//loading the icons from resource
	this->g_hImageList = ImageList_Create(ICON_SIZE, ICON_SIZE, ILC_COLOR32 | ILC_MASK, 8, 0);

	ImageList_AddIcon(this->g_hImageList, LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1)));
	ImageList_AddIcon(this->g_hImageList, LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON2)));
	ImageList_AddIcon(this->g_hImageList, LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON3)));
	ImageList_AddIcon(this->g_hImageList, LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON4)));

	ImageList_AddIcon(this->g_hImageList, LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON5)));
	ImageList_AddIcon(this->g_hImageList, LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON6)));
	ImageList_AddIcon(this->g_hImageList, LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON7)));
	ImageList_AddIcon(this->g_hImageList, LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON8)));
}


ToolbarPanel::~ToolbarPanel()
{
	ImageList_Destroy(this->g_hImageList);
}

BOOL ToolbarPanel::init()
{
	this->hWnd = CreateWindowEx(
		0,
		TOOLBARCLASSNAME,
		0,
		WS_CHILD | WS_VISIBLE | CCS_VERT | WS_BORDER,
		0,
		0,
		0,
		0,
		this->parent,
		0,
		this->hInst,
		NULL);

	SendMessage(this->hWnd, TB_BUTTONSTRUCTSIZE, (WPARAM)sizeof(TBBUTTON), 0);
	SendMessage(this->hWnd, TB_SETIMAGELIST, (WPARAM)0, (LPARAM)this->g_hImageList);

	// adjusting the correct icos for buttons
	this->buttons[0].iBitmap = 0;
	this->buttons[1].iBitmap = 1;
	this->buttons[2].iBitmap = 2;

	this->buttons[4].iBitmap = 3;

	this->buttons[6].iBitmap = 4;
	this->buttons[7].iBitmap = 5;

	this->buttons[9].iBitmap = 6;
	this->buttons[10].iBitmap = 7;


	if (!this->hWnd)
	{
		return FALSE;
	}


	SendMessage(this->hWnd, TB_ADDBUTTONS, BUTTONS, (LPARAM)&(this->buttons) );
	SendMessage(this->hWnd, TB_SETBITMAPSIZE, (WPARAM)0, (LPARAM)MAKELONG(ICON_SIZE, ICON_SIZE));
}

BOOL ToolbarPanel::show()
{
	return ShowWindow(this->hWnd, SW_SHOW);
}
