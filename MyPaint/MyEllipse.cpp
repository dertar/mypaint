#include "stdafx.h"
#include "MyEllipse.h"


MyEllipse::MyEllipse(const POINT & down, const POINT & up) : Shape(down, up)
{
}

MyEllipse::MyEllipse(const ShapeEntity * shapeEntity) : Shape(shapeEntity)
{
}

MyEllipse::MyEllipse()
{
}


MyEllipse::~MyEllipse()
{
}

void MyEllipse::draw(const HDC & hdc) const
{
	HBRUSH hBrush = CreateSolidBrush(this->rgb);
	HPEN hPen = CreatePen(PS_SOLID, this->thickness, RGB(0, 0, 0));

	SelectObject(hdc, hBrush);
	SelectObject(hdc, hPen);

	Ellipse(hdc, this->points->first.x, this->points->first.y,
		this->points->second.x, this->points->second.y);

	DeleteObject(hPen);
	DeleteObject(hBrush);

}
