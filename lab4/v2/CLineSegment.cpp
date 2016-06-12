#include "CLineSegment.h"
#include <math.h>


CLineSegment::CLineSegment(const CPoint & first, const CPoint & second, const std::string & color)
{
	m_firstPoint = first;
	m_secondPoint = second;
	m_outlineColor = color;
}

std::pair<CPoint, CPoint> CLineSegment::GetPoints() const
{
	return std::pair<CPoint, CPoint>(m_firstPoint, m_secondPoint);
}

double CLineSegment::GetLength() const
{
	std::pair<double, double> firstPointPos = GetPoints().first.GetPosition();
	std::pair<double, double> secondPointPos = GetPoints().second.GetPosition();
	return sqrt(pow(firstPointPos.first - secondPointPos.first, 2) + pow(firstPointPos.second - secondPointPos.second, 2));
}

double CLineSegment::GetArea() const
{
	return 0;
}

double CLineSegment::GetPerimeter() const
{
	return GetLength();
}

std::string CLineSegment::ToString() const
{
	return std::string("LineSegment");
}
