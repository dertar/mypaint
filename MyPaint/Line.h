#pragma once
#include "Shape.h"

class Line :
	public Shape
{
public:
	Line(const POINT &down, const POINT &up);
	Line(const ShapeEntity* shapeEntity);
	Line();
	~Line();

	void draw(const HDC &hdc) const;
};

