#pragma once
#include "ISolidShape.h"
#include "CShape.h"

class CSolidShape : public CShape , ISolidShape
{
public:
	CSolidShape() = default;
	std::string GetFillColor() const override;
protected:
	std::string m_fillColor;
};