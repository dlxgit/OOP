#pragma once
#include "CSolidShape.h"
#include "CPoint.h"
#include "CLineSegment.h"
#include <array>

class CTriangle : public CSolidShape
{
public:
	CTriangle(const CPoint & firstPoint, const CPoint & secondPoint, const CPoint & thirdPoint, const std::string & outlineColor, const std::string & fillColor);
	std::array<CPoint, 3> GetPoints() const;
	std::array<CLineSegment, 3> GetLines() const;
	std::string ToString() const override;
	double GetArea() const override;
	double GetPerimeter() const override;

private:
	CPoint m_firstPoint;
	CPoint m_secondPoint;
	CPoint m_thirdPoint;
};