#pragma once
#include "IDrawable.h"
#include "ShapeEntity.h"
#include "Shape.h"
#include "ShapeFactory.h"
/*
	Handles the drawing process
*/
class Canvas :
	public IDrawable,
	public BrushEntity
{
private:
	// shapes are pendED 
	std::vector< std::shared_ptr< Shape > > shapes;
	// shape that pendING
	std::shared_ptr< Shape > pending;

	// iterator for mechanism of undo and redo.
	std::vector< std::shared_ptr< Shape > >::iterator it = shapes.end();

	BOOL isPending;
	EShape type;

	ShapeFactory *fabric;

	// recration a new pending shape, 
	// that needs because the old pending shape would stored in pended data.
	void reconstructShape();

public:
	Canvas();
	~Canvas();

	void setTool(const EShape type);

	POINT& getDownMousePos();
	POINT& getUpMousePos();

	void setPending(const BOOL b);
	BOOL getPending() const;

	// 1) the pending shape will be added in pended data.
	// 2) if redo and undo Iterator would be not the last element
	//    in pended data that would erase subsequent shapes
	// 3) afterward call reconstructShape();
	void approve();

	void undo();
	void redo();


	// Inherited via IDrawable
	virtual void draw(const HDC & hdc) const override;

	void setColor(const COLORREF rgb) override;
	void setThickness(const int thickness) override;
};

