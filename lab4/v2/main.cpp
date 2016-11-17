#include "stdafx.h"
#include <iostream>
#include "Draw.h"

int main()
{
	std::cout << "Usage:" << std::endl <<
		"point x y outlineColor" << std::endl <<
		"line p1.x p1.y p2.x p2.y outlineColor" << std::endl <<
		"rectangle pos.x pos.y width height outlineColor fillColor" << std::endl <<
		"triangle p1.x p1.y p2.x p2.y p3.x p3.y outlineColor fillColor" << std::endl <<
		"circle pos.x pos.y radius outlineColor fillColor" << std::endl << std::endl;

	std::vector<std::shared_ptr<CShape>> figures;
	std::vector<std::shared_ptr<sf::Shape>> shapes;
	try
	{
		InputShapes(ReadShapes(), figures, shapes);
	}
	catch (std::invalid_argument)
	{
		std::cout << "Error: incorrect shape command" << std::endl;
		return 2;
	}
	catch (std::ios_base::failure)
	{
		std::cout << "Error: incorrect file name" << std::endl;
		return 3;
	}

	OutputShapesInCorrectOrder(figures);
	DrawShapes(shapes);

	return 0;
}