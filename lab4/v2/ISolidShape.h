#pragma once
#include "IShape.h"


class ISolidShape : public IShape
{
public:
	std::string GetFillColor() const;
};