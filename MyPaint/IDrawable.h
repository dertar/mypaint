#pragma once
#include "stdafx.h"

/*
	The interface for drawing
*/

class IDrawable
{
public:
	virtual void draw(const HDC &hdc) const = 0;
};