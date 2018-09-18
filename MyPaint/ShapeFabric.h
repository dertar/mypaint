#pragma once
#include "Shape.h"
#include "Line.h"
#include "MyRectangle.h"
#include "MyEllipse.h"
/*
	Types of shape
*/
enum class EShape
{
	LINE,
	RECT,
	ELLIPSE
};
/*
	Fabric that produce shapes
*/
class ShapeFabric
{
private:
	ShapeFabric();
	~ShapeFabric();

	// Singleton definetion
	static ShapeFabric* instance;
	ShapeFabric(ShapeFabric const&) = delete;
	ShapeFabric& operator=(ShapeFabric const&) = delete;
	//

public:
	
	static ShapeFabric* getIntance();
	
	Shape* create(ShapeEntity *entity, EShape type);
	Shape* create(EShape type);

	// get a shape that wrapped in shared_ptr
	std::shared_ptr< Shape > createShared(EShape type);
	std::shared_ptr< Shape > createShared(ShapeEntity *entity, EShape type);
};

