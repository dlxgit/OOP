#pragma once
#include "ISolidShape.h"
#include "CShape.h"

class CSolidShape : public CShape , ISolidShape
{
public:
	CSolidShape() = default;
protected:
	std::string m_fillColor;
};