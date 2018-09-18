#pragma once
/*
	Wrapper interface for WinApi Dialogs
*/
class IHandleDialog
{
	virtual BOOL init() = 0;
	virtual BOOL show() = 0;
};