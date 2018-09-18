#include "stdafx.h"
#include "ShapeFabric.h"


ShapeFabric::ShapeFabric()
{
}


ShapeFabric::~ShapeFabric()
{
	delete this->instance;
}

ShapeFabric * ShapeFabric::getIntance()
{
	if (instance == NULL)
		instance = new ShapeFabric();

	return instance;
}

Shape * ShapeFabric::create(ShapeEntity *entity, EShape type)
{
	if (type == EShape::LINE)
		return new Line(entity);
	else if (type == EShape::RECT)
		return new MyRectangle(entity);
	else if (type == EShape::ELLIPSE)
		return new MyEllipse(entity);

	return nullptr;
}

Shape * ShapeFabric::create(EShape type)
{
	return this->create(NULL, type);
}

std::shared_ptr<Shape> ShapeFabric::createShared(ShapeEntity *entity, EShape type)
{
	if (type == EShape::LINE)
		return std::make_shared<Line>(this->create(entity, type));
	else if (type == EShape::RECT)
		return std::make_shared<MyRectangle>(this->create(entity, type));
	else if (type == EShape::ELLIPSE)
		return std::make_shared<MyEllipse>(this->create(entity, type));

	return nullptr;
}
std::shared_ptr<Shape> ShapeFabric::createShared(EShape type)
{
	return this->createShared(NULL, type);
}

ShapeFabric* ShapeFabric::instance = NULL;
