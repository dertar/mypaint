#pragma once

/*
	Stores color and thickness of brush
*/

class BrushEntity
{
protected:
	int thickness;
	COLORREF rgb;

public:
	static int MIN;
	static int MAX;

	BrushEntity();
	BrushEntity(COLORREF rgb, int thickness);

	virtual ~BrushEntity();

	virtual void setColor(const COLORREF rgb);
	virtual COLORREF getColor() const;

	virtual void setThickness(const int thickness);
	virtual int getThickness() const;
};


