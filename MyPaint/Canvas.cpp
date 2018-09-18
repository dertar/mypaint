#include "stdafx.h"
#include "Canvas.h"


void Canvas::reconstructShape()
{
	this->pending = this->fabric->createShared(this->type);	
	this->pending->setColor(this->rgb);
	this->pending->setThickness(this->thickness);
}

Canvas::Canvas()
{
	this->fabric = ShapeFabric::getIntance();

	this->isPending = false;
	this->type = EShape::LINE;

	this->reconstructShape();
}

Canvas::~Canvas()
{
	this->shapes.clear();
}

void Canvas::setTool(const EShape type)
{
	this->type = type;
	this->reconstructShape();
}

POINT & Canvas::getDownMousePos()
{
	return this->pending->getFirst();
}

POINT & Canvas::getUpMousePos()
{
	return this->pending->getSecond();
}

void Canvas::setPending(const BOOL b)
{
	this->isPending = b;
}

BOOL Canvas::getPending() const
{
	return this->isPending;
}

void Canvas::approve()
{
	if (this->it != this->shapes.end())
	{
		this->shapes.erase(this->it, this->shapes.end());
	}

	this->shapes.push_back(
		std::move(this->pending)
	);

	this->it = this->shapes.end();

	this->reconstructShape();
}

void Canvas::undo()
{
	if(this->it != this->shapes.begin())
		this->it--;
}

void Canvas::redo()
{
	if (this->it != this->shapes.end())
		this->it++;
}

void Canvas::draw(const HDC & hdc) const
{
	/*for (auto &x : this->shapes){
		x->draw(hdc);
	}*/

	for (auto shape = this->shapes.begin(); shape != this->it; shape++)
		(*shape)->draw(hdc);

	if (this->isPending)
		this->pending->draw(hdc);
	
	
}

void Canvas::setColor(const COLORREF rgb)
{
	BrushEntity::setColor(rgb);
	this->pending->setColor(rgb);
}

void Canvas::setThickness(const int thickness)
{
	BrushEntity::setThickness(thickness);
	this->pending->setThickness(thickness);
}
