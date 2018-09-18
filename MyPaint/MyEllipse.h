#pragma once
#include "Shape.h"
/*
	The entity of ellipse
*/

class MyEllipse :
	public Shape
{
public:

	MyEllipse(const POINT &down, const POINT &up);
	MyEllipse(const ShapeEntity* shapeEntity);

	MyEllipse();
	~MyEllipse();

	// Inherited via Shape
	virtual void draw(const HDC & hdc) const override;
};

