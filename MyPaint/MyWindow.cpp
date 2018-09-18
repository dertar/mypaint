#include "stdafx.h"
#include "MyWindow.h"

// lazy init
MyWindow* MyWindow::instance = NULL;

MyWindow::MyWindow(HINSTANCE hInstance, int nCmdShow)
{
	// lazy init
	instance = this;

	this->hInst = hInstance;
	this->nCmdShow = nCmdShow;

	this->canvas = new Canvas();
}

MyWindow::~MyWindow()
{
	delete this->canvas;
	delete this->colorPicker;
	delete this->panel;
	delete this->window;
}

LRESULT MyWindow::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	return instance->MyWndProc(hWnd, message, wParam, lParam);
}

BOOL MyWindow::init()
{
	this->myRegisterClass();

	this->window = new MainDialog(this->hInst, this->nCmdShow);

	if (!this->window->init())
		return FALSE;

	this->panel = new ToolbarPanel(this->hInst, this->window->getHWND());

	if (!this->panel->init())
		return FALSE;

	this->colorPicker = new ColorPickerDialog(this->window->getHWND(), this->canvas);

	this->colorPicker->init();

	return TRUE;
}

BOOL MyWindow::show()
{
	HACCEL hAccelTable = LoadAccelerators(this->hInst, MAKEINTRESOURCE(IDC_MYPAINT));

	MSG msg;

	this->window->show();
	this->panel->show();
	

	// Main message loop:
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}


//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyWindow::myRegisterClass()
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = this->hInst;
	wcex.hIcon = LoadIcon(this->hInst, MAKEINTRESOURCE(IDI_MYPAINT));
	wcex.hCursor = LoadCursor(nullptr, IDC_CROSS);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_MYPAINT);
	wcex.lpszClassName = NAME_CLASS;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}


void MyWindow::getCurrentPoint(POINT &point, LPARAM lParam)
{
	point.x = GET_X_LPARAM(lParam);
	point.y = GET_Y_LPARAM(lParam);
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//

LRESULT CALLBACK MyWindow::MyWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case TOOL_LINE:
			this->canvas->setTool(EShape::LINE);
			break;
		case TOOL_RECT:
			this->canvas->setTool(EShape::RECT);
			break;
		case TOOL_ELLIPSE:
			this->canvas->setTool(EShape::ELLIPSE);
			break;
		case TOOL_COLORPICKER:
			this->colorPicker->show();
			break;
		case TOOL_PLUS:
			this->canvas->setThickness(this->canvas->getThickness() + 1);
			break;
		case TOOL_MINUS:
			this->canvas->setThickness(this->canvas->getThickness() - 1);
			break;
		case TOOL_UNDO:
			this->canvas->undo();
			InvalidateRect(hWnd, NULL, TRUE); // updating canvas
			break;
		case TOOL_REDO:
			this->canvas->redo();
			InvalidateRect(hWnd, NULL, TRUE); // updating canvas
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	break;
	case WM_PAINT:
	{
		this->hdc = BeginPaint(hWnd, &(this->ps) );
		this->canvas->draw(hdc);
		EndPaint(hWnd, &(this->ps));
		break;
	}
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_LBUTTONDOWN:
		// if user left the window and back again
		if (this->canvas->getPending())
		{
			this->getCurrentPoint(this->canvas->getUpMousePos(), lParam);
			InvalidateRect(hWnd, NULL, TRUE);
		}
		else {
			this->getCurrentPoint(this->canvas->getDownMousePos(), lParam);
			this->canvas->setPending(true);
		}

		break;
	case WM_LBUTTONUP:
		this->canvas->setPending(false);
		this->canvas->approve();
		break;
	case WM_MOUSEMOVE:
		if (this->canvas->getPending())
		{
			this->getCurrentPoint(this->canvas->getUpMousePos(), lParam);
			InvalidateRect(hWnd, NULL, TRUE);
		}

		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
