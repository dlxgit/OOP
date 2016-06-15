#include "CTriangle.h"
#include "stdafx.h"

CTriangle::CTriangle(const CPoint & firstPoint, const CPoint & secondPoint, const CPoint & thirdPoint, const std::string & fillColor, const std::string & outlineColor)
{
	m_firstPoint = firstPoint;
	m_secondPoint = secondPoint;
	m_thirdPoint = thirdPoint;
	m_fillColor = fillColor;
	m_outlineColor = outlineColor;
}


std::string CTriangle::ToString() const
{
	//Circle<10, 10>, R = 10, S = 314.15927, P = 62, 831853
	std::array<CPoint,3> points = GetPoints();
	return std::string("triangle <" + boost::lexical_cast<std::string>(points[0].GetPosition().first) + ", " + boost::lexical_cast<std::string>(points[0].GetPosition().second) + "><" + 
		boost::lexical_cast<std::string>(points[1].GetPosition().first) + ", " + boost::lexical_cast<std::string>(points[1].GetPosition().second) + "><" +
		boost::lexical_cast<std::string>(points[2].GetPosition().first) + boost::lexical_cast<std::string>(points[2].GetPosition().second) + "> " + ", S = " + 
		boost::lexical_cast<std::string>(GetArea()) + ", P = " + boost::lexical_cast<std::string>(GetPerimeter()) + ", " +
		boost::lexical_cast<std::string>(GetOutlineColor()) + ", " + boost::lexical_cast<std::string>(GetFillColor()));
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
// 	array<CPoint, 3> points;
// 	points[0] = m_firstPoint;
	return{ m_firstPoint, m_secondPoint, m_thirdPoint };
}

std::array<CLineSegment, 3> CTriangle::GetLines() const
{
	return{ CLineSegment(m_firstPoint,m_secondPoint), CLineSegment(m_secondPoint, m_thirdPoint), CLineSegment(m_firstPoint, m_thirdPoint)};
}