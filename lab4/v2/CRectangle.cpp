#include "stdafx.h"
#include "CRectangle.h"


CRectangle::CRectangle(const CPoint & position, const double & width, const double & height, const std::string & outlineColor, const std::string & fillColor)
{
	m_position = position;
	m_width = width;
	m_height = height;
	m_fillColor = fillColor;
	m_outlineColor = outlineColor;
}

std::string CRectangle::ToString() const
{
	std::stringstream ss;
	ss << std::fixed << std::setprecision(2) << "rectangle <" << m_position.GetPosition().first << ", " << m_position.GetPosition().second << "> " << "width = " << m_width << ", height = " << m_height << ", S = " << GetArea() << ", P = " << GetPerimeter() << ", " << GetOutlineColor() << ", " << GetFillColor();
	return ss.str();
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
