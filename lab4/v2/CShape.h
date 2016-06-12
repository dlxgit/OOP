#pragma once
#include "IShape.h"

class CShape : public IShape
{
public:
	CShape() = default;
// 	double virtual GetArea() const = 0;
// 	double virtual GetPerimeter() const = 0;
// 	std::string virtual ToString() const = 0;
	std::string GetOutlineColor() const;
	void SetOutlineColor(const std::string & outlineColor);
protected:
	std::string m_outlineColor;
};