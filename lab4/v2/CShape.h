#pragma once
#include "IShape.h"

class CShape : public IShape
{
public:
	CShape() = default;
	std::string GetOutlineColor() const;
protected:
	std::string m_outlineColor;
};