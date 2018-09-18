#include "stdafx.h"
#include "Shape.h"


Shape::Shape(const POINT & down, const POINT & up) : ShapeEntity(down, up)
{
}

Shape::Shape(const ShapeEntity * shapeEntity) : ShapeEntity(shapeEntity)
{

}

Shape::Shape()
{
}


Shape::~Shape()
{
}

std::string Shape::getData() const
{
	throw std::exception("Not Implemented");
}

void Shape::setData(const std::string & data)
{
	throw std::exception("Not Implemented");
}
