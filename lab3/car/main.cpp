#include "stdafx.h"
#include <iostream>
#include "CCar.h"
#include "CCarController.h"

int main()
{
	CCar car;

	CCarController controller;
	car.TurnOnEngine();
	car.SetGear(-1);
	controller.HandleCommand();
	return 0;
}