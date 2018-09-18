#include "stdafx.h"
#include "Line.h"

Line::Line(const POINT &down, const POINT &up) : Shape(down, up)
{

}

Line::Line(const ShapeEntity * shapeEntity) : Shape(shapeEntity)
{
}

Line::Line() : Shape()
{

}

Line::~Line()
{
}

void Line::draw(const HDC &hdc) const
{
	HPEN hPen = CreatePen(PS_SOLID, thickness, rgb);
	
	SelectObject(hdc, hPen);

	MoveToEx(hdc, points->first.x, points->first.y, NULL);
	LineTo(hdc, points->second.x, points->second.y);

	DeleteObject(hPen);
}
