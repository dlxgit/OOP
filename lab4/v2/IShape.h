#pragma once
#include <string>


class IShape
{
public:
	double virtual GetArea() const = 0;
	double virtual GetPerimeter() const = 0;
	std::string virtual ToString() const = 0;
	std::string virtual GetOutlineColor() const = 0;
	virtual ~IShape() = default;
};