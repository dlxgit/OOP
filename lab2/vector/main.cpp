#include "MultiplyElements.h"


int main()
{
	vector<double> numbers = ReadNumbers();
	vector<double> resultVector = ComputeMultipiedVector(numbers);
	SortVector(numbers);
	PrintVector(numbers);
	return 0;
}