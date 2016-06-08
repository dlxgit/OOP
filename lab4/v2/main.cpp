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

//TODO: CRectangle constructor setOutlineColor();

/*
std::shared_ptr<CShape> AddNewShape(const std::vector<std::string> & inputParts)
{
	if (inputParts[0].compare(std::string("point")) && inputParts.size() == 4)
	{
		return std::make_shared<CPoint>(std::stod(inputParts[1]), std::stod(inputParts[2]), inputParts[3]);
	}
	else if (inputParts[0].compare(std::string("line")) && inputParts.size() == 6)
	{
		return std::make_shared<CLineSegment>(CPoint(std::stod(inputParts[1]), std::stod(inputParts[2])), CPoint(std::stod(inputParts[3]), std::stod(inputParts[4])), inputParts[5]);
	}
	else if (inputParts[0].compare(std::string("triangle")) && inputParts.size() == 9)
	{
		return std::make_shared<CShape>(CTriangle(CPoint(std::stod(inputParts[1]), std::stod(inputParts[2])), CPoint(std::stod(inputParts[3]), std::stod(inputParts[4])), CPoint(std::stod(inputParts[5]), std::stod(inputParts[6])), inputParts[7], inputParts[8]));
	}
	/*
	else if (inputParts[0].compare(std::string("rectangle")) && inputParts.size() == 7)
	{
		return std::make_shared<CRectangle>(CPoint(std::stod(inputParts[1]), std::stod(inputParts[2])), std::stod(inputParts[3]), std::stod(inputParts[4]), inputParts[5], inputParts[6]);
	}
	else if (inputParts[0].compare(std::string("circle")) && inputParts.size() == 6 && std::stod(inputParts[3]) <= 0)
	{
		return std::make_shared<CCircle>(CPoint(std::stod(inputParts[1]), std::stod(inputParts[2])), std::stod(inputParts[3]), inputParts[4], inputParts[5]);
	}
	
	else
	{
		throw;
	}
	return nullptr;
}
*/
std::vector<std::shared_ptr<CShape>> InputShapes()
{
	std::vector<std::shared_ptr<CShape>> result;
	std::vector<std::string> inputParts;
	std::string line = "0";
	while (std::getline(std::cin, line) && !line.empty())
	{
		boost::split(inputParts, line, boost::is_any_of(","));
		//AddNewShape(inputParts);
	}
	
	return result;
}


int main()
{
	CLineSegment asds();
	CRectangle asd();
	//std::vector<std::shared_ptr<CShape>> shapes;
	try
	{
		//shapes = InputShapes();
	}
	catch(...)
	{
		std::cout << "wat" << std::endl;
	}
	return 0;
}