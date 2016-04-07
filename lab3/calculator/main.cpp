// calculator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <iostream>
#include <sstream>

#include "calculator.h"

using namespace std;



int main()
{
	ifstream inputFile("input.txt");
	if (!inputFile.is_open())
	{
		cout << "input file is incorrect" << endl;
	}
	
	Calculator calculator;
	string line;
	while (std::getline(inputFile, line))
	{
		calculator.ReadCommand(line);
		if (calculator.IsCommandCorrect())
		{
			calculator.ProcessCommand();
		}
		else cout << "error: command is incorrect" << endl;
	}

	return 0;
}