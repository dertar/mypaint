#pragma once
/*
	Stores two POINTs
*/
class ShapeEntity
{
private:
	void set(POINT &point,const POINT &set);

protected:
	std::pair <POINT, POINT> *points;

public:
	ShapeEntity(const POINT &down, const POINT &up);
	ShapeEntity(const ShapeEntity*);

	ShapeEntity();

	virtual ~ShapeEntity();

	void setFirst(const POINT &point);
	void setSecond(const POINT &point);

	POINT& getFirst() const;
	POINT& getSecond() const;
};

