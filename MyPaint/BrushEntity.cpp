#include "stdafx.h"
#include "BrushEntity.h"

// Clamp for thickness
int BrushEntity::MIN = 1;
int BrushEntity::MAX = 20;


BrushEntity::BrushEntity() : BrushEntity(RGB(0,0,0), 1)
{
}

BrushEntity::BrushEntity(COLORREF rgb, int thickness)
{
	this->rgb = rgb;
	this->thickness = thickness;
}


BrushEntity::~BrushEntity()
{
}

void BrushEntity::setColor(const COLORREF rgb)
{
	this->rgb = rgb;
}

COLORREF BrushEntity::getColor() const
{
	return this->rgb;
}

void BrushEntity::setThickness(const int thickness)
{
	this->thickness = CLAMP(thickness, MAX, MIN);
}

int BrushEntity::getThickness() const
{
	return this->thickness;
}
