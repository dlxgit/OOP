#pragma once
#include "ISolidShape.h"
#include "CPoint.h"
#define _USE_MATH_DEFINES 
#include <math.h>

class CCircle : public ISolidShape
{
public:
	CCircle(CPoint & point, const double & radius, const std::string & outlineColor, const std::string & fillColor);
	CPoint GetCenter() const;
	double GetRadius() const;

	std::string ToString() const override;
	double GetArea() const override;
	double GetPerimeter() const override;

private:
	CPoint m_center;
	double m_radius;
	std::string m_outlineColor;
	std::string m_fillColor;
};