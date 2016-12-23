#include "stdafx.h"
#include "CRectangle.h"


CRectangle::CRectangle(const CPoint & position, double width, double height, const std::string & outlineColor, const std::string & fillColor)
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
	std::pair<double, double> position = m_position.GetPosition();
	ss << std::fixed << std::setprecision(2) << "rectangle <" << 
		position.first << ", " << 
		position.second << "> " << "width = " << 
		m_width << ", height = " << 
		m_height << ", S = " << 
		GetArea() << ", P = " << 
		GetPerimeter() << ", " << 
		m_outlineColor << ", " << 
		m_fillColor;
	return ss.str();
}

double CRectangle::GetArea() const
{
	return m_width * m_height;
}

double CRectangle::GetPerimeter() const
{
	return (m_width + m_height) * 2;
}

CPoint CRectangle::GetPosition() const
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
