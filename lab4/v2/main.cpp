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
#include <math.h>
#include <boost/algorithm/algorithm.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>

#include <SFML/Graphics.hpp>
#include "stdafx.h"
#include "ConvertColor.h"

typedef std::pair<std::shared_ptr<CShape>, std::shared_ptr<sf::Shape>> PointersToShapes;
//TODO: CRectangle constructor setOutlineColor();


void CreatePoint(const std::vector<std::string> & inputParts, std::vector<std::shared_ptr<CShape>> & figures, std::vector<std::shared_ptr<sf::Shape>> & shapes)
{
	double x = std::stod(inputParts[1]);
	double y = std::stod(inputParts[2]);
	std::string outlineColor = inputParts[3];
	CPoint point = CPoint(x, y, outlineColor);
	sf::RectangleShape drawingPoint(sf::Vector2f(1,1));
	drawingPoint.setPosition(x,y);
	drawingPoint.setOutlineColor(ConvertHexToRgb(outlineColor));
	
	figures.push_back(std::make_shared<CPoint>(point));
	shapes.push_back(std::make_shared<sf::RectangleShape>(drawingPoint));
}

void CreateLine(const std::vector<std::string> & inputParts, std::vector<std::shared_ptr<CShape>> & figures, std::vector<std::shared_ptr<sf::Shape>> & shapes)
{
	CPoint p1 = CPoint(std::stod(inputParts[1]), std::stod(inputParts[2]));
	CPoint p2 = CPoint(std::stod(inputParts[3]), std::stod(inputParts[4]));
	//CLineSegment line = CLineSegment(CPoint(std::stod(inputParts[1]), std::stod(inputParts[2])), CPoint(std::stod(inputParts[3]), std::stod(inputParts[4])), inputParts[5]);
	std::string outlineColor = inputParts[5];
	CLineSegment line = CLineSegment(p1, p2, outlineColor);
	
	sf::RectangleShape drawingLine(sf::Vector2f(line.GetPerimeter(), 2));
	sf::RectangleShape(sf::Vector2f(line.GetPerimeter(), 3.f));
	p1.GetPosition().first > p2.GetPosition().first ? drawingLine.setPosition(float(p2.GetPosition().first), float(p2.GetPosition().second)) : 
													  drawingLine.setPosition(float(p1.GetPosition().first), float(p1.GetPosition().second));

	figures.push_back(std::make_shared<CLineSegment>(line));
	shapes.push_back(std::make_shared<sf::RectangleShape>(drawingLine));

}

void CreateTriangle(const std::vector<std::string> & inputParts, std::vector<std::shared_ptr<CShape>> & figures, std::vector<std::shared_ptr<sf::Shape>> & shapes)
{
	CPoint p1 = CPoint(std::stod(inputParts[1]), std::stod(inputParts[2]));
	CPoint p2 = CPoint(std::stod(inputParts[3]), std::stod(inputParts[4]));
	CPoint p3 = CPoint(std::stod(inputParts[5]), std::stod(inputParts[6]));
	std::string outlineColor = inputParts[7];
	std::string fillColor = inputParts[8];
	CTriangle triangle = CTriangle(p1, p2, p3, outlineColor, fillColor);
	sf::ConvexShape drawingTriangle;
	drawingTriangle.setFillColor(ConvertHexToRgb(fillColor));
	drawingTriangle.setOutlineColor(ConvertHexToRgb(outlineColor));
	drawingTriangle.setPointCount(3);
	drawingTriangle.setPoint(0, sf::Vector2f(p1.GetPosition().first, p1.GetPosition().second));
	drawingTriangle.setPoint(1, sf::Vector2f(p2.GetPosition().first, p2.GetPosition().second));
	drawingTriangle.setPoint(2, sf::Vector2f(p3.GetPosition().first, p3.GetPosition().second));
	figures.push_back(std::make_shared<CTriangle>(triangle));
	shapes.push_back(std::make_shared<sf::ConvexShape>(drawingTriangle));
}

void CreateRectangle(const std::vector<std::string> & inputParts, std::vector<std::shared_ptr<CShape>> & figures, std::vector<std::shared_ptr<sf::Shape>> & shapes)
{
	double x = std::stod(inputParts[1]);
	double y = std::stod(inputParts[2]);
	double width = std::stod(inputParts[3]);
	double height = std::stod(inputParts[4]);
	std::string outlineColor = inputParts[5];
	std::string fillColor = inputParts[6];
	CRectangle rectangle = CRectangle(CPoint(x, y), width, height, outlineColor, fillColor);
	sf::RectangleShape drawingRectangle(sf::Vector2f(width, height));
	drawingRectangle.setPosition(x, y);
	drawingRectangle.setFillColor(ConvertHexToRgb(fillColor));
	drawingRectangle.setOutlineColor(ConvertHexToRgb(outlineColor));
	figures.push_back(std::make_shared<CRectangle>(rectangle));
	shapes.push_back(std::make_shared<sf::RectangleShape>(drawingRectangle));
}

void CreateCircle(const std::vector<std::string> & inputParts, std::vector<std::shared_ptr<CShape>> & figures, std::vector<std::shared_ptr<sf::Shape>> & shapes)
{
	CPoint pos = CPoint(std::stod(inputParts[1]), std::stod(inputParts[2]));
	double radius = std::stod(inputParts[3]);
	std::string outlineColor = inputParts[4];
	std::string fillColor = inputParts[5];
	CCircle circle = CCircle(pos, radius, outlineColor, fillColor);
	sf::CircleShape drawCircle;
	drawCircle.setOrigin(radius / 2, radius / 2);
	drawCircle.setPosition(pos.GetPosition().first, pos.GetPosition().second);
	drawCircle.setRadius(radius);
	drawCircle.setFillColor(ConvertHexToRgb(fillColor));
	drawCircle.setOutlineColor(ConvertHexToRgb(outlineColor));
	figures.push_back(std::make_shared<CCircle>(circle));
	shapes.push_back(std::make_shared<sf::CircleShape>(drawCircle));
}

/*
void AddNewShape(const std::vector<std::string> & inputParts, std::vector<std::shared_ptr<CShape>> & figures, std::vector<std::shared_ptr<sf::Shape>> & shapes)
{
	if (inputParts[0].compare(std::string("point")) == 0 && inputParts.size() == 4)
	{
		double x = std::stod(inputParts[1]);
		double y = std::stod(inputParts[2]);
		std::string outlineColor = inputParts[3];
		CPoint point = CPoint(x, y, outlineColor);
		
		return std::make_shared<CPoint>(point);
		//return std::make_shared<CShape>(CPoint(std::stod(inputParts[1]), std::stod(inputParts[2]), inputParts[3]));
	}
	else if (inputParts[0].compare(std::string("line")) == 0 && inputParts.size() == 6)
	{
		CPoint p1 = CPoint(std::stod(inputParts[1]), std::stod(inputParts[2]));
		CPoint p2 = CPoint(std::stod(inputParts[3]), std::stod(inputParts[4]));
		//CLineSegment line = CLineSegment(CPoint(std::stod(inputParts[1]), std::stod(inputParts[2])), CPoint(std::stod(inputParts[3]), std::stod(inputParts[4])), inputParts[5]);
		std::string outlineColor = inputParts[5];
		CLineSegment line = CLineSegment(p1, p2, outlineColor);
		return std::make_shared<CLineSegment>(line);
		//return std::make_shared<CShape>(CLineSegment(CPoint(std::stod(inputParts[1]), std::stod(inputParts[2])), CPoint(std::stod(inputParts[3]), std::stod(inputParts[4])), inputParts[5]));
	}
	else if (inputParts[0].compare(std::string("triangle")) == 0 && inputParts.size() == 9)
	{
		CPoint p1 = CPoint(std::stod(inputParts[1]), std::stod(inputParts[2]));
		CPoint p2 = CPoint(std::stod(inputParts[3]), std::stod(inputParts[4]));
		CPoint p3 = CPoint(std::stod(inputParts[5]), std::stod(inputParts[6]));
		std::string outlineColor = inputParts[7];
		std::string fillColor = inputParts[8];
		CTriangle triangle = CTriangle(p1, p2, p3, outlineColor, fillColor);
		return std::make_shared<CTriangle>(triangle);
	}
	else if (inputParts[0].compare(std::string("rectangle")) == 0 && inputParts.size() == 7)
	{
		double x = std::stod(inputParts[1]);
		double y = std::stod(inputParts[2]);
		double width = std::stod(inputParts[3]);
		double height = std::stod(inputParts[4]);
		std::string outlineColor = inputParts[5];
		std::string fillColor = inputParts[6];
		CRectangle rectangle = CRectangle(CPoint(x, y), width, height, outlineColor, fillColor);
		return std::make_shared<CRectangle>(rectangle);
	}
	else if (inputParts[0].compare(std::string("circle")) == 0 && inputParts.size() == 6 && std::stod(inputParts[3]) <= 0)
	{
		CPoint pos = CPoint(std::stod(inputParts[1]), std::stod(inputParts[2]));
		double radius = std::stod(inputParts[3]);
		std::string outlineColor = inputParts[4];
		std::string fillColor = inputParts[5];
		CCircle circle = CCircle(pos, radius, outlineColor, fillColor);
		return std::make_shared<CCircle>(circle);
	}
	else
	{
		throw;
	}
	//return nullptr;
}
*/

void AddNewShape(const std::vector<std::string> & inputParts, std::vector<std::shared_ptr<CShape>> & figures, std::vector<std::shared_ptr<sf::Shape>> & shapes)
{
	if (inputParts[0].compare(std::string("point")) == 0 && inputParts.size() == 4)
	{
		CreatePoint(inputParts, figures, shapes);
	}
	else if (inputParts[0].compare(std::string("line")) == 0 && inputParts.size() == 6)
	{
		CreateLine(inputParts, figures, shapes);
	}
	else if (inputParts[0].compare(std::string("triangle")) == 0 && inputParts.size() == 9)
	{
		CreateTriangle(inputParts, figures, shapes);
	}
	else if (inputParts[0].compare(std::string("rectangle")) == 0 && inputParts.size() == 7)
	{
		CreateRectangle(inputParts, figures, shapes);
	}
	else if (inputParts[0].compare(std::string("circle")) == 0 && inputParts.size() == 6 && std::stod(inputParts[3]) >= 0)
	{
		CreateCircle(inputParts, figures, shapes);
	}
	else
	{
		throw;
	}
	//return nullptr;
}

void InputShapes(std::vector<std::shared_ptr<CShape>> & figures, std::vector<std::shared_ptr<sf::Shape>> & shapes)
{
	std::vector<std::string> inputParts;
	std::string line = "0";
	while (true)//(std::getline(std::cin, line) && !line.empty())
	{
		std::vector<std::string> parts = { "triangle 570 140 570 200 620 200 #096ab1 #096ab1",
			"rectangle 390 150 60 50 #ff0000 #aa3863",
			"rectangle 370 200 280 90 #69020b #794044",
			"rectangle 480 138 90 60 #69020b #096ab1",
			"circle 420 290 30 #69675a #0c0c2a",
			"circle 590 290 30 #69675a #0c0c2a",
			"circle 420 290 10 #69675a #c0cfbc",
			"circle 590 290 10 #69675a #c0cfbc",
			"triangle 480 200 570 200 500 270 #0c0c2a #69020b",
			"triangle 625 230 650 230 650 250 #63c1ba #fcf976",
			"line 490 138 470 90 #850b18"
		};
			for (auto elem : parts)
			{
				boost::split(inputParts, elem, boost::is_any_of(" "));
				AddNewShape(inputParts, figures, shapes);
			}
		break;
	}
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
	std::vector<std::shared_ptr<CShape>> figures;
	std::vector<std::shared_ptr<sf::Shape>> shapes;// = TransformFiguresIntoShapes(pFigures);
	std::cout << "Usage:" << std::endl <<
		"point x y outlineColor" << std::endl <<
		"line p1.x p1.y p2.x p2.y outlineColor" << std::endl <<
		"rectangle pos.x pos.y width height outlineColor fillColor" << std::endl <<
		"triangle p1.x p1.y p2.x p2.y p3.x p3.y outlineColor fillColor" << std::endl <<
		"circle pos.x pos.y radius outlineColor fillColor" << std::endl;

	try
	{
		InputShapes(figures, shapes);
	}
	catch(...)
	{
		std::cout << "wat" << std::endl;
	}

	sf::RenderWindow window(sf::VideoMode(800, 600), "Shapes");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::White);
		DrawShapes(window, shapes);
		//InputShapes(figures, shapes);
		window.display();
	}

	return 0;
}