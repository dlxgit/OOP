#pragma once
#include "IShape.h"


class ISolidShape : public IShape
{
public:
	ISolidShape() = default;
	std::string GetFillColor() const;
};