#include <iostream>
#include "SolutionPrinter.h"


int main(int argc, char * argv[])
{
	if (argc != 4)
	{
		std::cout << "incorrect program execution.\nUsage: solve.exe <A> <B> <C>" << std::endl;
		return 1;
	}

	double a;
	double b;
	double c;

	try
	{
		a = std::stod(argv[1]);
		b = std::stod(argv[2]);
		c = std::stod(argv[3]);
	}
	catch(...)
	{
		std::cout << "There is non-number argument" << std::endl;
		return 1;
	}

	auto result = ComputeRoots(a, b, c);
	
	std::ofstream outputFile("output.txt");
	QuadraticEquationSolutionPrinter printer(outputFile);
	result.apply_visitor(printer);
	if (!outputFile.flush())
	{
		std::cout << "Error closing output.txt" << std::endl;
	}
	return 0;
}