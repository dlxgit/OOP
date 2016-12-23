#include "stdafx.h"
#include "CTriangle.h"

CTriangle::CTriangle(const CPoint & firstPoint, const CPoint & secondPoint, const CPoint & thirdPoint, const std::string & outlineColor, const std::string & fillColor)
{
	m_firstPoint = firstPoint;
	m_secondPoint = secondPoint;
	m_thirdPoint = thirdPoint;
	m_fillColor = fillColor;
	m_outlineColor = outlineColor;
}

std::string CTriangle::ToString() const
{
	std::pair<double, double> point1 = m_firstPoint.GetPosition();
	std::pair<double, double> point2 = m_secondPoint.GetPosition();
	std::pair<double, double> point3 = m_thirdPoint.GetPosition();

	std::stringstream ss;
	ss << std::fixed << std::setprecision(2) << 
		"triangle <" << 
		point1.first << ", " <<
		point1.second << ">, " << "<" <<
		point2.first << ", " <<
		point2.second << ">, <" <<
		point3.first << ", " <<
		point3.second << ">, S = " <<
		GetArea() << ", P = " << 
		GetPerimeter() << ", " << 
		m_outlineColor << ", " << 
		m_fillColor;
	return ss.str();
}

double CTriangle::GetArea() const
{
	double p = GetPerimeter() / 2;
	return sqrt(p * (p - CLineSegment(m_firstPoint, m_secondPoint).GetLength()) * (p - CLineSegment(m_secondPoint, m_thirdPoint).GetLength()) * (p - CLineSegment(m_firstPoint, m_thirdPoint).GetLength()));
}

double CTriangle::GetPerimeter() const
{
	return CLineSegment(m_firstPoint, m_secondPoint).GetLength() + CLineSegment(m_secondPoint, m_thirdPoint).GetLength() + CLineSegment(m_firstPoint, m_thirdPoint).GetLength();
}

std::array<CPoint, 3> CTriangle::GetPoints() const
{
	return{ m_firstPoint, m_secondPoint, m_thirdPoint };
}

std::array<CLineSegment, 3> CTriangle::GetLines() const
{
	return{ CLineSegment(m_firstPoint,m_secondPoint), CLineSegment(m_secondPoint, m_thirdPoint), CLineSegment(m_firstPoint, m_thirdPoint)};
}