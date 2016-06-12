#pragma warning( disable : 4996 )
#include <iostream>
#include <vector>
#include <memory>
#include "IShape.h"
#include "CShape.h"
#include "CPoint.h"
#include "CLineSegment.h"
#include "CRectangle.h"
#include "CTriangle.h"
#include "CCircle.h"

#include <boost/algorithm/algorithm.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>

#include <SFML/Graphics.hpp>

//TODO: CRectangle constructor setOutlineColor();


std::shared_ptr<CShape> AddNewShape(const std::vector<std::string> & inputParts)
{
	if (inputParts[0].compare(std::string("point")) == 0 && inputParts.size() == 4)
	{
		CPoint point = CPoint(std::stod(inputParts[1]), std::stod(inputParts[2]), inputParts[3]);
		return std::make_shared<CPoint>(point);
		//return std::make_shared<CShape>(CPoint(std::stod(inputParts[1]), std::stod(inputParts[2]), inputParts[3]));
	}
	else if (inputParts[0].compare(std::string("line")) == 0 && inputParts.size() == 6)
	{
		//CLineSegment line = CLineSegment(CPoint(std::stod(inputParts[1]), std::stod(inputParts[2])), CPoint(std::stod(inputParts[3]), std::stod(inputParts[4])), inputParts[5]);
		return std::make_shared<CLineSegment>(CLineSegment(CPoint(std::stod(inputParts[1]), std::stod(inputParts[2])), CPoint(std::stod(inputParts[3]), std::stod(inputParts[4])), inputParts[5]));
		//return std::make_shared<CShape>(CLineSegment(CPoint(std::stod(inputParts[1]), std::stod(inputParts[2])), CPoint(std::stod(inputParts[3]), std::stod(inputParts[4])), inputParts[5]));
	}
	else if (inputParts[0].compare(std::string("triangle")) == 0 && inputParts.size() == 9)
	{
		return std::make_shared<CTriangle>(CTriangle(CPoint(std::stod(inputParts[1]), std::stod(inputParts[2])), CPoint(std::stod(inputParts[3]), std::stod(inputParts[4])), CPoint(std::stod(inputParts[5]), std::stod(inputParts[6])), inputParts[7], inputParts[8]));
	}
	
	else if (inputParts[0].compare(std::string("rectangle")) == 0 && inputParts.size() == 7)
	{
		return std::make_shared<CRectangle>(CRectangle(CPoint(std::stod(inputParts[1]), std::stod(inputParts[2])), std::stod(inputParts[3]), std::stod(inputParts[4]), inputParts[5], inputParts[6]));
	}
	else if (inputParts[0].compare(std::string("circle")) == 0 && inputParts.size() == 6 && std::stod(inputParts[3]) <= 0)
	{
		return std::make_shared<CCircle>(CCircle(CPoint(std::stod(inputParts[1]), std::stod(inputParts[2])), std::stod(inputParts[3]), inputParts[4], inputParts[5]));
	}
	else
	{
		throw;
	}
	//return nullptr;
}

std::vector<std::shared_ptr<CShape>> InputShapes()
{
	std::vector<std::shared_ptr<CShape>> result;
	std::vector<std::string> inputParts;
	std::string line = "0";
	while (std::getline(std::cin, line) && !line.empty())
	{
		boost::split(inputParts, line, boost::is_any_of(","));
		result.push_back(AddNewShape(inputParts));
	}
	
	return result;
}

void DrawShapes(sf::RenderWindow & window, const std::vector<std::shared_ptr<sf::Shape>> & shapes)
{
	for (const auto & elem : shapes)
	{
		window.draw(*elem);
	}
}

std::vector<std::shared_ptr<sf::Shape>> TransformFiguresIntoShapes(const std::vector<std::shared_ptr<CShape>> & pFigures)
{
	std::vector<std::shared_ptr<sf::Shape>> result;
	for (const auto & elem : pFigures)
	{
		//elem->
	}
	return result;
}

int main()
{
	CLineSegment asds();
	CRectangle asd();
	std::vector<std::shared_ptr<CShape>> pFigures;
	try
	{
		pFigures = InputShapes();
	}
	catch(...)
	{
		std::cout << "wat" << std::endl;
	}

	std::vector<std::shared_ptr<sf::Shape>> shapes = TransformFiguresIntoShapes(pFigures);

	sf::RenderWindow window(sf::VideoMode(200, 200), "Lesson 1. kychka-pc.ru");

	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	shapes.push_back(std::make_shared<sf::CircleShape>(shape));
	

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		DrawShapes(window, shapes);
		window.display();
	}

	return 0;
}