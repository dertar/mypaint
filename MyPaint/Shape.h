#pragma once
#include "IDrawable.h"
#include "IData.h"
#include "ShapeEntity.h"
#include "BrushEntity.h"

/*
	The enity of shape that stores:
		how to draw the shape,
		how to save the shape,
		POINTS,
		color and thickness of brush
*/
class Shape :
	public IDrawable,
	public IData,
	public ShapeEntity,
	public BrushEntity
{ 

public:
	Shape(const POINT &down, const POINT &up);
	Shape(const ShapeEntity *shapeEntity);

	Shape();
	~Shape();

	// Inherited via IData
	virtual std::string getData() const override;
	virtual void setData(const std::string & data) override;
};

