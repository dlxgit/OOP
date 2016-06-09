#include "stdafx.h"
#include <iostream>
#include "CCar.h"
#include "CCarController.h"

int main()
{
	CCar car();

	CCarController controller;
	
	controller.HandleCommand();
	return 0;
}