#pragma once
#include "CShape.h"

class CPoint: public CShape
{
public:
	CPoint(double x = 0, double y = 0, const std::string & color = "#000000");
	std::pair<double, double> GetPosition() const;
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
private:
	std::pair<double, double> m_position;
};