#pragma once
#include "CSolidShape.h"
#include "CPoint.h"

class CRectangle : public CSolidShape
{
public:
	CRectangle(const CPoint & position, const double & width, const double & height, const std::string & fillColor, const std::string & outlineColor);
	CPoint GetTopLeftPoint() const;
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