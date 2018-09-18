#include "stdafx.h"
#include "MainDialog.h"


MainDialog::MainDialog(HINSTANCE hInst, const int nCmdShow) :
	HWNDHandler(hInst, NULL, nCmdShow)
{

}


MainDialog::~MainDialog()
{
}

BOOL MainDialog::init()
{
	this->hWnd = CreateWindowW( NAME_CLASS,
								NAME_WINDOW,
								WS_OVERLAPPEDWINDOW,
								CW_USEDEFAULT,
								0,
								CW_USEDEFAULT,
								0,
								nullptr,
								nullptr,
								this->hInst,
								nullptr
	);


	if (!this->hWnd)
	{
		return FALSE;
	}

	return TRUE;
}

BOOL MainDialog::show()
{
	BOOL ret = ShowWindow(this->hWnd, this->nCmdShow);
	UpdateWindow(this->hWnd);

	return ret;
}
