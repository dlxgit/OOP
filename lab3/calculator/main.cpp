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


/*	
	printvars
	Выводит в stdout имена и значения всех ранее объявленных переменных, отсортированных по алфавиту, по одному в каждой строке в следующем формате:
*/



int main()
{
	//Calculator calc();
	Calculator calculator;
	ifstream inputFile("input.txt");
	if (!inputFile.is_open())
	{
		cout << "input file is incorrect" << endl;
	}
	
	string line;
	while (std::getline(inputFile, line))
	{
		calculator.ReadCommand(line);
		if (calculator.IsCommandCorrect())
		{
			calculator.ProcessCommand();
		}
		else cout << "err: " << //word << 
		endl;
	}
	

	return 0;
}