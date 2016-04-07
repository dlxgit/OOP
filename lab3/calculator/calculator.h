#pragma once

#include "stdafx.h"
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <iostream>
#include <sstream>
#include <set>
#include <cmath>
#include <iomanip>


using namespace std;


const static set<string> OPERATION_SYMBOLS = { "+", "-", "*", "/" };

class Calculator
{
public:

	map<string, double> varMap;
	map<string, vector<string>> funcMap;
	vector<string> operationParts;

	void ReadCommand(const string & line);

	bool IsCommandCorrect();

	void ProcessCommand();

	bool IsNumber(const std::string & str);


	double ComputeFuncValue(const string & funcName);

	void Var();
	void Let(const bool & isNumber);
	void Fn();
	void Print();
	void PrintVars();
	void PrintFns();
};