#include "CCircle.h"
#include "stdafx.h"

CCircle::CCircle(CPoint & point, const double & radius, const std::string & outlineColor, const std::string & fillColor)
{
	m_center = point;
	m_radius = radius;
	m_outlineColor = outlineColor;
	m_fillColor = fillColor;
}


std::string CCircle::ToString() const
{
	//Circle<10, 10>, R = 10, S = 314.15927, P = 62, 831853
	return std::string("circle" + boost::lexical_cast<std::string>(GetCenter().GetPosition().first) + boost::lexical_cast<std::string>(GetCenter().GetPosition().second)
		+ " R = " + boost::lexical_cast<std::string>(GetRadius()) + ", S = " + boost::lexical_cast<std::string>(GetArea()) + ", P = " +
		boost::lexical_cast<std::string>(GetPerimeter()) + ", " + boost::lexical_cast<std::string>(GetOutlineColor()) + ", " + GetFillColor());
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
