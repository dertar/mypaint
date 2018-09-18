#include "stdafx.h"
#include "MyRectangle.h"


MyRectangle::MyRectangle(const POINT & down, const POINT & up) : Shape(down, up)
{
}

MyRectangle::MyRectangle(const ShapeEntity * shapeEntity) : Shape(shapeEntity)
{
}

MyRectangle::MyRectangle()
{
}


MyRectangle::~MyRectangle()
{
}

void MyRectangle::draw(const HDC & hdc) const
{
	HBRUSH hBrush = CreateSolidBrush(this->rgb);
	HPEN hPen = CreatePen(PS_SOLID, this->thickness, RGB(0,0,0));

	SelectObject(hdc, hBrush);
	SelectObject(hdc, hPen);

	Rectangle(hdc, this->points->first.x, this->points->first.y,
		this->points->second.x, this->points->second.y );

	DeleteObject(hPen);
	DeleteObject(hBrush);
}
