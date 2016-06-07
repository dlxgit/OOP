#include "stdafx.h"
#include <iostream>
#include "CCar.h"
#include "CCarController.h"

int main()
{
	CCar car();

	CCarController controller;
	try
	{
		controller.HandleCommand();
	}
	catch(...)
	{
		std::cout << "Error: non-number element." << std::endl;
	}
	return 0;
}