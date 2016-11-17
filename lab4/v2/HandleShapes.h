#pragma once
#include <vector>
#include <fstream>
#include <memory>
#include <math.h>
#include <iostream>
#include <boost/algorithm/algorithm.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <boost/math/constants/constants.hpp>
#include "CShape.h"
#include "CPoint.h"
#include "CLineSegment.h"
#include "CTriangle.h"
#include "CRectangle.h"
#include "CCircle.h"

typedef std::pair<std::shared_ptr<CShape>, std::shared_ptr<sf::Shape>> PointersToShapes;

sf::Color ConvertHexToRgb(const std::string & hex);

std::vector<std::string> ReadShapes();

void BubbleSort(std::vector<std::shared_ptr<CShape>> & shapes, bool isSortByArea);

void OutputShapes(const std::vector<std::shared_ptr<CShape>> & figures);

void OutputShapesInCorrectOrder(std::vector<std::shared_ptr<CShape>> & figures);

void AddPoint(const std::vector<std::string> & inputParts, std::vector<std::shared_ptr<CShape>> & figures, std::vector<std::shared_ptr<sf::Shape>> & shapes);

void AddLine(const std::vector<std::string> & inputParts, std::vector<std::shared_ptr<CShape>> & figures, std::vector<std::shared_ptr<sf::Shape>> & shapes);

void AddTriangle(const std::vector<std::string> & inputParts, std::vector<std::shared_ptr<CShape>> & figures, std::vector<std::shared_ptr<sf::Shape>> & shapes);

void AddRectangle(const std::vector<std::string> & inputParts, std::vector<std::shared_ptr<CShape>> & figures, std::vector<std::shared_ptr<sf::Shape>> & shapes);

void AddCircle(const std::vector<std::string> & inputParts, std::vector<std::shared_ptr<CShape>> & figures, std::vector<std::shared_ptr<sf::Shape>> & shapes);

void AddNewShape(const std::vector<std::string> & inputParts, std::vector<std::shared_ptr<CShape>> & figures, std::vector<std::shared_ptr<sf::Shape>> & shapes);

void InputShapes(std::vector<std::string> & commands, std::vector<std::shared_ptr<CShape>> & figures, std::vector<std::shared_ptr<sf::Shape>> & shapes);

void DrawShapes(const std::vector<std::shared_ptr<sf::Shape>> & shapes);