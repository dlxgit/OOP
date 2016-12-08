#include "stdafx.h"
#include "HandleShapes.h"

sf::Color ConvertHexToRgb(const std::string & hex)
{
	std::string hexCode = hex;
	if (hexCode.size() != 7 || hexCode[0] != '#')
	{
		return sf::Color::Black;
	}

	hexCode.erase(0, 1);
	int number = std::stoi(hexCode, 0, 16);
	return sf::Color(number / 0x10000, (number / 0x100) % 0x100, number % 0x100);
}

std::vector<std::string> ReadShapes()
{
	std::string inputFileName;
	std::vector<std::string> commands;
	std::string command;
	std::cout << "If you want to load shapes from file, input fileName or <Enter> to input commands." << std::endl;
	std::getline(std::cin, inputFileName);

	if (inputFileName.length())
	{
		std::cout << "Loading shapes from file..." << std::endl;
		std::ifstream inputFile(inputFileName);
		if (!inputFile.is_open())
		{
			throw std::ios_base::failure("Error: inputFile is not found");
		}
		while (std::getline(inputFile, command))
		{
			commands.push_back(command);
		}
	}
	else
	{
		std::cout << "Starting to input commands, type exit to finish." << std::endl;
		while (std::getline(std::cin, command))
		{
			if (command.compare(std::string("exit")) != 0)
			{
				commands.push_back(command);
			}
			else break;
		}
	}
	return commands;
}

void BubbleSort(std::vector<std::shared_ptr<CShape>> & shapes, bool isSortByArea)
{
	std::shared_ptr<CShape> temp;
	for (size_t i = 0; (i < shapes.size()); i++)
	{
		bool isChange = false;
		for (size_t j = 0; j < (shapes.size() - 1); j++)
		{
			if (isSortByArea && shapes[j + 1]->GetArea() > shapes[j]->GetArea() ||
				!isSortByArea && shapes[j + 1]->GetPerimeter() < shapes[j]->GetPerimeter())
			{
				temp = shapes[j];
				shapes[j] = shapes[j + 1];
				shapes[j + 1] = temp;
				isChange = true;
			}
		}
		if (!isChange)
		{
			break;
		}
	}
}

void OutputShapes(const std::vector<std::shared_ptr<CShape>> & figures)
{
	for (auto elem : figures)
	{
		std::cout << elem->ToString() << std::endl;
	}
}

void OutputShapesInCorrectOrder(std::vector<std::shared_ptr<CShape>> & figures)
{
	BubbleSort(figures, true);
	std::cout << std::endl << "Shapes sorted by area:" << std::endl << std::endl;
	OutputShapes(figures);
	BubbleSort(figures, false);
	std::cout << std::endl << "Shapes sorted by perimeter:" << std::endl << std::endl;
	OutputShapes(figures);

}

void AddPoint(const std::vector<std::string> & inputParts, std::vector<std::shared_ptr<CShape>> & figures, std::vector<std::shared_ptr<sf::Shape>> & shapes)
{
	double x = std::stod(inputParts[1]);
	double y = std::stod(inputParts[2]);
	std::string outlineColor = inputParts[3];
	CPoint point = CPoint(x, y, outlineColor);
	sf::RectangleShape drawingPoint(sf::Vector2f(1, 1));
	drawingPoint.setPosition((float)x, (float)y);
	drawingPoint.setFillColor(ConvertHexToRgb(outlineColor));
	figures.push_back(std::make_shared<CPoint>(point));
	shapes.push_back(std::make_shared<sf::RectangleShape>(drawingPoint));
}

void AddLine(const std::vector<std::string> & inputParts, std::vector<std::shared_ptr<CShape>> & figures, std::vector<std::shared_ptr<sf::Shape>> & shapes)
{
	CPoint p1 = CPoint(std::stod(inputParts[1]), std::stod(inputParts[2]));
	CPoint p2 = CPoint(std::stod(inputParts[3]), std::stod(inputParts[4]));
	std::string outlineColor = inputParts[5];
	CLineSegment line = CLineSegment(p1, p2, outlineColor);

	sf::RectangleShape drawingLine(sf::Vector2f((float)line.GetPerimeter(), (float)2));
	sf::RectangleShape(sf::Vector2f((float)line.GetPerimeter(), 3.f));

	p2.GetPosition().first < p1.GetPosition().first ? drawingLine.setPosition(float(p2.GetPosition().first), float(p2.GetPosition().second)) : drawingLine.setPosition(float(p1.GetPosition().first), float(p1.GetPosition().second));
	drawingLine.setRotation(float(std::atan((p2.GetPosition().second - p1.GetPosition().second) / (p2.GetPosition().first - p1.GetPosition().first)) * 180 / boost::math::constants::pi<double>()));

	drawingLine.setFillColor(ConvertHexToRgb(inputParts[5]));
	drawingLine.setOutlineThickness(3.f);
	figures.push_back(std::make_shared<CLineSegment>(line));
	shapes.push_back(std::make_shared<sf::RectangleShape>(drawingLine));

}

void AddTriangle(const std::vector<std::string> & inputParts, std::vector<std::shared_ptr<CShape>> & figures, std::vector<std::shared_ptr<sf::Shape>> & shapes)
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
	drawingTriangle.setPoint(0, sf::Vector2f((float)p1.GetPosition().first, (float)p1.GetPosition().second));
	drawingTriangle.setPoint(1, sf::Vector2f((float)p2.GetPosition().first, (float)p2.GetPosition().second));
	drawingTriangle.setPoint(2, sf::Vector2f((float)p3.GetPosition().first, (float)p3.GetPosition().second));
	drawingTriangle.setOutlineThickness(3.f);
	figures.push_back(std::make_shared<CTriangle>(triangle));
	shapes.push_back(std::make_shared<sf::ConvexShape>(drawingTriangle));
}

void AddRectangle(const std::vector<std::string> & inputParts, std::vector<std::shared_ptr<CShape>> & figures, std::vector<std::shared_ptr<sf::Shape>> & shapes)
{
	double x = std::stod(inputParts[1]);
	double y = std::stod(inputParts[2]);
	double width = std::stod(inputParts[3]);
	double height = std::stod(inputParts[4]);

	if (width <= 0 || height <= 0)
	{
		throw std::invalid_argument("Error: width and height of rectangle must be positive");
	}

	std::string outlineColor = inputParts[5];
	std::string fillColor = inputParts[6];
	CRectangle rectangle = CRectangle(CPoint(x, y), width, height, outlineColor, fillColor);
	sf::RectangleShape drawingRectangle(sf::Vector2f((float)width, (float)height));
	drawingRectangle.setPosition((float)x, (float)y);
	drawingRectangle.setFillColor(ConvertHexToRgb(fillColor));
	drawingRectangle.setOutlineColor(ConvertHexToRgb(outlineColor));
	drawingRectangle.setOutlineThickness(3.f);
	figures.push_back(std::make_shared<CRectangle>(rectangle));
	shapes.push_back(std::make_shared<sf::RectangleShape>(drawingRectangle));
}

void AddCircle(const std::vector<std::string> & inputParts, std::vector<std::shared_ptr<CShape>> & figures, std::vector<std::shared_ptr<sf::Shape>> & shapes)
{
	CPoint pos = CPoint(std::stod(inputParts[1]), std::stod(inputParts[2]));
	double radius = std::stod(inputParts[3]);
	std::string outlineColor = inputParts[4];
	std::string fillColor = inputParts[5];

	CCircle circle = CCircle(pos, radius, fillColor, outlineColor);
	sf::CircleShape drawCircle;
	drawCircle.setPosition((float)pos.GetPosition().first, (float)pos.GetPosition().second);
	drawCircle.setRadius((float)radius);
	drawCircle.setFillColor(ConvertHexToRgb(fillColor));
	drawCircle.setOutlineThickness(3.f);
	drawCircle.setOutlineColor(ConvertHexToRgb(outlineColor));
	figures.push_back(std::make_shared<CCircle>(circle));
	shapes.push_back(std::make_shared<sf::CircleShape>(drawCircle));
}

void AddNewShape(const std::vector<std::string> & inputParts, std::vector<std::shared_ptr<CShape>> & figures, std::vector<std::shared_ptr<sf::Shape>> & shapes)
{
	if (inputParts.size() == 4 && inputParts[0].compare(std::string("point")) == 0)
	{
		AddPoint(inputParts, figures, shapes);
	}
	else if (inputParts.size() == 6 && inputParts[0].compare(std::string("line")) == 0)
	{
		AddLine(inputParts, figures, shapes);
	}
	else if (inputParts.size() == 9 && inputParts[0].compare(std::string("triangle")) == 0)
	{
		AddTriangle(inputParts, figures, shapes);
	}
	else if (inputParts.size() == 7 && inputParts[0].compare(std::string("rectangle")) == 0)
	{
		AddRectangle(inputParts, figures, shapes);
	}
	else if (inputParts.size() == 6 && inputParts[0].compare(std::string("circle")) == 0 && std::stod(inputParts[3]) >= 0)
	{
		AddCircle(inputParts, figures, shapes);
	}
	else
	{
		throw std::invalid_argument("Incorrect command");
	}
}

void InputShapes(std::vector<std::string> & commands, std::vector<std::shared_ptr<CShape>> & figures, std::vector<std::shared_ptr<sf::Shape>> & shapes)
{
	try
	{
		for (auto line : commands)
		{
			std::vector<std::string> commandParts;
			boost::split(commandParts, line, boost::is_any_of(" "));
			AddNewShape(commandParts, figures, shapes);
		}
	}
	catch (std::invalid_argument)
	{
		throw std::invalid_argument("Error: incorrect shape command");
	}
}

