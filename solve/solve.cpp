#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>
#include <math.h>


const size_t CALC_PRECISION = 4;  //number of digits after "."

double ComputeDiscriminant(const double & a, const double & b, const double & c)
{
	return b * b - (4 * a * c);
}

bool IsNumber(const std::string & str)
{
	if (str.size() == 0 || str[0] == '.' || str[str.size() - 1] == '.')  //if string is empty or it has '.' on first/last position 
	{
		return false;
	}
	if (!(str[0] < 58 && str[0] > 47) && str[0] != '-') //if first element is not correct (not between 0 and 9)
	{
		return false;
	}

	bool isPointAlready = false;  // flag if we already met '.' (to check if we meet it once again)

	for (size_t i = 1; i < str.size(); i++)
	{
		if (str[i] == '.')
		{
			if (true == isPointAlready)
			{
				return false;
			}
			isPointAlready = true;
		}
		else if (str[i] > 57 || str[i] < 48)
		{
			std::cout << "number <" << str << "> is not correct" << std::endl;
			return false;
		}
	}
	return true;
}

bool IsInputCorrect(const std::string & a, const std::string & b, const std::string & c)
{
	if (!(IsNumber(a) && IsNumber(b) && IsNumber(c)))
	{
		std::cout << "Error: there is an incorrect number" << std::endl;
		return false;
	}
	if (a == "0")
	{
		std::cout << "Error. Impossible to calculate quadratic roots (a == 0)" << std::endl;
		return false;
	}
	return true;
}

void CalculateAndPrintRoots(char * argv[])
{
	const double a = atof(argv[1]);
	const double b = atof(argv[2]);
	const double c = atof(argv[3]);
	const double discriminant = ComputeDiscriminant(a,b,c);

	if (discriminant < 0)
	{
		std::cout << "There is no real root (D < 0)" << std::endl;
	}
	else if (discriminant == 0)
	{
		std::cout << "One root: " << 
		std::fixed << std::setprecision(CALC_PRECISION) << 
		(-b) / (2 * a) << std::endl;
	}
	else
	{
		std::cout << "Two roots: " << 
		std::fixed << std::setprecision(CALC_PRECISION) << (-b + sqrt(discriminant)) / (2 * a) << " , " <<
		std::fixed << std::setprecision(CALC_PRECISION) << (-b - sqrt(discriminant)) / (2 * a) << std::endl;
	}
}

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "incorrect program execution.\nUsage: solve.exe <A> <B> <C>" << std::endl;
		return 1;
	}
	if (!IsInputCorrect(argv[1], argv[2], argv[3]))
		return 1;
	CalculateAndPrintRoots(argv);
	return 0;
}