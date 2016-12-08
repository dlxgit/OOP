#include "stdafx.h"
#include "CPoint.h"


CPoint::CPoint(double x, double y, const std::string & color)
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
	std::stringstream ss;
	ss << std::fixed << std::setprecision(2) << "point <" << 
		m_position.first << ", " << 
		m_position.second << ">, " << 
		m_outlineColor;
	return ss.str();
}