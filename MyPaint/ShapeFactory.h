#pragma once
#include "Shape.h"
#include "Line.h"
#include "MyRectangle.h"
#include "MyEllipse.h"
/*
	Type of shape
*/
enum class EShape
{
	LINE,
	RECT,
	ELLIPSE
};
/*
	The factory class that produces Shape entities
*/
class ShapeFactory
{
private:
	ShapeFactory();
	~ShapeFactory();

	// Singleton definition
	static ShapeFactory* instance;
	ShapeFactory(ShapeFactory const&) = delete;
	ShapeFactory& operator=(ShapeFactory const&) = delete;
	//

public:
	
	static ShapeFactory* getIntance();
	
	Shape* create(ShapeEntity *entity, EShape type);
	Shape* create(EShape type);

	// get a shape that wrapped in shared_ptr
	std::shared_ptr< Shape > createShared(EShape type);
	std::shared_ptr< Shape > createShared(ShapeEntity *entity, EShape type);
};

