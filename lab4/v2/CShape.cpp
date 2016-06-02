#include "CShape.h"

std::string CShape::GetOutlineColor() const
{
	return m_outlineColor;
}

/*std::string CShape::ToString() const
{
	return std::string("shape");
}*/

// double CShape::GetArea() const
// {
// 	return 0;
// }
// 
// double CShape::GetPerimeter() const
// {
// 	return 0;
// }

void CShape::SetOutlineColor(const std::string & outlineColor)
{
	m_outlineColor = outlineColor;
}