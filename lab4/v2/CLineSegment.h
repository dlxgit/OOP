
#pragma once
#include "IShape.h"
#include "CPoint.h"

class CLineSegment : public CShape
{
public:
	CLineSegment(const CPoint & first, const CPoint & second, const std::string & color = "#000000");

	std::pair<CPoint, CPoint> GetPoints() const;
	double GetLength() const;
	double GetArea() const override;
	double GetPerimeter() const override;

	std::string ToString() const override;

private:
	CPoint m_firstPoint;
	CPoint m_secondPoint;
};