#include "CPoint.h"
#include "stdafx.h"

CPoint::CPoint(const double & x, const double & y, const std::string & color)
{
	m_position = std::pair<double, double>(x, y);
	m_outlineColor = color;
}

std::pair<double, double> CPoint::GetPosition() const
{
	return m_position;
}

double CPoint::GetArea() const
{
	return 0;
}

double CPoint::GetPerimeter() const
{
	return 0;
}

std::string CPoint::ToString() const
{
	return std::string("point <" + std::to_string(GetPosition().first) + ", " + std::to_string(GetPosition().second) + GetOutlineColor());
}