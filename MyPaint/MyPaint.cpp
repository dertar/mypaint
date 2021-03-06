// MyPaint.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "MyPaint.h"

#include "MyWindow.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	MyWindow window(hInstance, nCmdShow);

	if (!window.init())
	{
		MessageBox(NULL, L"Window init failed", L"Error", MB_OK | MB_ICONERROR);
		return -1;
	}

	return window.show();
	
}
