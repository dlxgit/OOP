#pragma once
#include "IShape.h"

class CShape : public IShape
{
public:
	std::string ToString() const override;
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string GetOutlineColor() const override;
private:
	std::string m_outlineColor;
};