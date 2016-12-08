#pragma once
#include "CSolidShape.h"
#include "CPoint.h"

class CRectangle : public CSolidShape
{
public:
	CRectangle(const CPoint & position, double width, double height, const std::string & outlineColor, const std::string & fillColor);
	CPoint GetPosition() const;
	double GetWidth() const;
	double GetHeight() const;

	std::string ToString() const override;
	double GetArea() const override;
	double GetPerimeter() const override;
private:
	CPoint m_position;
	double m_width;
	double m_height;
};