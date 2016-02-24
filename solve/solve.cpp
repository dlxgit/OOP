#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>
#include <math.h>


const size_t CALC_PRECISION = 4;

bool IsInputCorrect(const double & a)
{
	if (a == 0)
	{
		std::cout << "Error. Impossible to calculate quadratic roots (a = 0)" << std::endl;
		return false;
	}
	return true;
}

void CalculateAndPrintRoots(const double & a, const double & b, const double & c)
{
	const float D = float(b * b - (4 * a * c));

	if (D < 0)
	{
		std::cout << "There is no real root (D < 0)" << std::endl;
	}
	else if (D == 0)
	{
		std::cout << "One root: " << 
		std::fixed << std::setprecision(CALC_PRECISION) << 
		(-b) / (2 * a) << std::endl;
	}
	else
	{
		std::cout << "Two roots: " << 
		std::fixed << std::setprecision(CALC_PRECISION) << (-b + sqrt(D)) / (2 * a) << " , " << 
		std::fixed << std::setprecision(CALC_PRECISION) << (-b - sqrt(D)) / (2 * a) << std::endl;
	}
}

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "incorrect program execution.\nUsage: solve.exe <A> <B> <C>" << std::endl;
		return 1;
	}
	const double a = atof(argv[1]);
	const double b = atof(argv[2]);
	const double c = atof(argv[3]);
	if (!IsInputCorrect(a))
		return 1;
	CalculateAndPrintRoots(a, b, c);
	return 0;
}