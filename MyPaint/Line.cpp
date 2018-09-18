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
	HPEN hPen = CreatePen(PS_SOLID, this->thickness, this->rgb);
	
	SelectObject(hdc, hPen);

	MoveToEx(hdc, this->points->first.x, this->points->first.y, NULL);
	LineTo(hdc, this->points->second.x, this->points->second.y);

	DeleteObject(hPen);
}
