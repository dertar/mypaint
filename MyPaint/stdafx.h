// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files
#include <windows.h>
#include <windowsx.h>
#include <commctrl.h>
#include <commdlg.h>
#pragma comment(lib, "comctl32.lib")

// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

// C++
#include <queue>
#include <vector>
#include <memory>
#include <exception>
#include <cmath>

//MACROSES
#define CLAMP(X, UPPER, LOWER) (min(UPPER, max(X, LOWER)))


// reference additional headers your program requires here
