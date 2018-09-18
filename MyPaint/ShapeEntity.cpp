#include "stdafx.h"
#include "ShapeEntity.h"


void ShapeEntity::set(POINT &point, const POINT &set)
{
	point.x = set.x;
	point.y = set.y;
}

ShapeEntity::ShapeEntity(const POINT &down, const POINT &up) : ShapeEntity()
{
	this->setFirst(down);
	this->setSecond(up);
}

ShapeEntity::ShapeEntity(const ShapeEntity *entity) : ShapeEntity()
{
	if (entity != NULL)
	{
		this->set(entity->getFirst(), entity->getSecond());
	}
}

ShapeEntity::ShapeEntity()
{
	this->points = new std::pair<POINT, POINT>();
}

ShapeEntity::~ShapeEntity()
{
	delete this->points;
}

void ShapeEntity::setFirst(const POINT & point)
{
	this->set(this->points->first, point);
}

void ShapeEntity::setSecond(const POINT & point)
{
	this->set(this->points->second, point);
}

POINT & ShapeEntity::getFirst() const
{
	return this->points->first;
}

POINT & ShapeEntity::getSecond() const
{
	return this->points->second;
}
