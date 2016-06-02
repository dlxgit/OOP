#include "CCircle.h"

CCircle::CCircle(CPoint & point, const double & radius, const std::string & outlineColor, const std::string & fillColor)
{
	m_center = point;
	m_radius = radius;
	m_outlineColor = outlineColor;
	m_fillColor = fillColor;
}


std::string CCircle::ToString() const
{
	return std::string("CCircle");
}

double CCircle::GetArea() const
{
	return M_PI * GetRadius() * GetRadius();
}

double CCircle::GetPerimeter() const
{
	return 2 * M_PI * GetRadius();
}

CPoint CCircle::GetCenter() const
{
	return m_center;
}

double CCircle::GetRadius() const
{
	return m_radius;
}
