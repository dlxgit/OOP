#pragma once
#include <string>
#include <boost/lexical_cast.hpp>

class IShape
{
public:
	IShape() = default;
	double virtual GetArea() const = 0;
	double virtual GetPerimeter() const = 0;
	std::string virtual ToString() const = 0;
	virtual ~IShape() = default;
};