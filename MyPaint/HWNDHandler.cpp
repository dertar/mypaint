#include "stdafx.h"
#include "HWNDHandler.h"

HWNDHandler::HWNDHandler(HINSTANCE hInst, HWND parent, const int nCmdShow)
{
	this->hInst = hInst;
	this->parent = parent;
	this->nCmdShow = nCmdShow;
}

HWND HWNDHandler::getHWND()
{
	return this->hWnd;
}

HWNDHandler::~HWNDHandler()
{

}
