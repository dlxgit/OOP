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
	������� � stdout ����� � �������� ���� ����� ����������� ����������, ��������������� �� ��������, �� ������ � ������ ������ � ��������� �������:
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