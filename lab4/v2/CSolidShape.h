#pragma once
#include "ISolidShape.h"
#include "CShape.h"

class CSolidShape : public ISolidShape, CShape
{
protected:
	std::string m_fillColor;
};