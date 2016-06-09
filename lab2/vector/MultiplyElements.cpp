#include "stdafx.h"
#include "MultiplyElements.h"


vector<double> ReadNumbers()
{
	std::vector<double> vec((std::istream_iterator<double>(std::cin)), std::istream_iterator<double>());
	return vec;
}

vector<double> ComputeMultipiedVector(const vector<double> & numbers) //multiply all elements of vector by the minimal element
{
	if (numbers.empty())
	{
		return numbers;
	}
	double minElement = *std::min_element(numbers.begin(), numbers.end());
	vector<double> resultVector;
	for (auto  element : numbers)
	{
		resultVector.push_back(element * minElement);
	}
	return resultVector;
}

void SortVector(vector<double> & numbers)
{
	std::sort(numbers.begin(), numbers.end());
}

void PrintVector(const vector<double> & resultVector)
{
	std::copy(resultVector.begin(), resultVector.end(), std::ostream_iterator<double>(std::cout << std::fixed << std::setprecision(3), " "));
}