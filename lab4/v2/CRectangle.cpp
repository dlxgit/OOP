#include "CRectangle.h"

CRectangle::CRectangle(const CPoint & position, const double & width, const double & height, const std::string & fillColor, const std::string & outlineColor)
{
	m_position = position;
	m_width = width;
	m_height = height;
	m_fillColor = fillColor;
	m_outlineColor = outlineColor;
}

std::string CRectangle::ToString() const
{
	return std::string("rectangle");
}

double CRectangle::GetArea() const
{
	return GetWidth() * GetHeight();
}

double CRectangle::GetPerimeter() const
{
	return (GetWidth() + GetHeight()) * 2;
}


CPoint CRectangle::GetTopLeftPoint() const
{
	return m_position;
}

double CRectangle::GetWidth() const
{
	return m_width;
}

double CRectangle::GetHeight() const
{
	return m_height;
}
