#pragma once
#include "Shape.h"

class MyRectangle :
	public Shape
{
public:
	MyRectangle(const POINT &down, const POINT &up);
	MyRectangle(const ShapeEntity* shapeEntity);

	MyRectangle();
	~MyRectangle();

	// Inherited via Shape
	virtual void draw(const HDC & hdc) const override;
};

