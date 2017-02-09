#include <iostream>
#include <memory>
#include <vector>
#include "Header.h"


int main()
{
	std::vector<std::unique_ptr<IPerson>> people;
	people.push_back(std::make_unique<CAdvancedStudent>());

	
	return 0;
}