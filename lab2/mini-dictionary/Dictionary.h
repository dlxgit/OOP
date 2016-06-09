#pragma once
#include "stdafx.h"
#include <string>
#include <fstream>
#include <map>
#include <math.h>
#include <vector>
#include <iostream>
#include <boost/algorithm/algorithm.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <windows.h>


typedef std::multimap<std::string, std::string> Dictionary;

std::vector<std::string> PartLineBySymbol(const std::string & line, const std::string & delimeter);

Dictionary ReadDataFromFile(const std::string & inputFileName = "Program_data.txt");

void AskUserToSaveChanges(const Dictionary & dictionary);

void SaveDictionaryInFile(const Dictionary & dictionary);

std::string GetTranslation(const Dictionary & dict, const std::string & key);

void ProcessInputData(Dictionary & dictionary);

void AddElement(Dictionary & dictonary, const std::pair<std::string, std::string> & elem);

bool HasWord(const Dictionary & dict, const std::string & word);