#pragma once
#include "ISolidShape.h"
#include "CPoint.h"
#include "CLineSegment.h"
#include <array>

class CTriangle : public ISolidShape
{
public:
	CTriangle(const CPoint & firstPoint, const CPoint & secondPoint, const CPoint & thirdPoint, const std::string & fillColor, const std::string & outlineColor);
	std::array<CPoint, 3> GetPoints() const;
	std::array<CLineSegment, 3> GetLines() const;
	std::string ToString() const override;
	double GetArea() const override;
	double GetPerimeter() const override;

private:
	CPoint m_firstPoint;
	CPoint m_secondPoint;
	CPoint m_thirdPoint;
	std::string m_fillColor;
	std::string m_outlineColor;
};