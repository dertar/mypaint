#include "stdafx.h"
#include "ShapeFactory.h"


ShapeFactory::ShapeFactory()
{
}


ShapeFactory::~ShapeFactory()
{
	delete this->instance;
}

ShapeFactory * ShapeFactory::getIntance()
{
	if (instance == NULL)
		instance = new ShapeFactory();

	return instance;
}

Shape * ShapeFactory::create(ShapeEntity *entity, EShape type)
{
	if (type == EShape::LINE)
		return new Line(entity);
	else if (type == EShape::RECT)
		return new MyRectangle(entity);
	else if (type == EShape::ELLIPSE)
		return new MyEllipse(entity);

	return nullptr;
}

Shape * ShapeFactory::create(EShape type)
{
	return this->create(NULL, type);
}

std::shared_ptr<Shape> ShapeFactory::createShared(ShapeEntity *entity, EShape type)
{
	if (type == EShape::LINE)
		return std::make_shared<Line>(this->create(entity, type));
	else if (type == EShape::RECT)
		return std::make_shared<MyRectangle>(this->create(entity, type));
	else if (type == EShape::ELLIPSE)
		return std::make_shared<MyEllipse>(this->create(entity, type));

	return nullptr;
}
std::shared_ptr<Shape> ShapeFactory::createShared(EShape type)
{
	return this->createShared(NULL, type);
}

ShapeFactory* ShapeFactory::instance = NULL;
