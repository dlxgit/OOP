#pragma once
#include "CShape.h"

class CPoint: public CShape
{
public:
	CPoint(const double & x = 0, const double & y = 0, const std::string & color = "#000000");
	std::pair<double, double> GetPosition() const;
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	std::string GetOutlineColor() const override;
private:
	std::pair<double, double> m_position;
	std::string m_color;
};