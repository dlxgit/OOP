#include "stdafx.h"
#include "CCarController.h"


void CCarController::PrintInfo() const
{
	if (m_car.IsEngineOn())
	{
		std::cout << "Engine is ON" << std::endl;
	}
	else
	{
		std::cout << "Engine is OFF" << std::endl;
	}
	CCar::Direction dir = m_car.GetDirection();
	std::cout << "Direction: ";
	if (dir == CCar::MOVE_BACK)
	{
		std::cout << "MOVE_BACK" << std::endl;
	}
	else if (dir == CCar::MOVE_FRONT)
	{
		std::cout << "MOVE_FRONT" << std::endl;
	}
	else
	{
		std::cout << "STAY" << std::endl;
	}
	std::cout << "Speed: " << m_car.GetSpeed() << std::endl;
	std::cout << "Gear: " << m_car.GetGear() << std::endl;
}

bool CCarController::HandleCommand()
{
	std::string command;


	std::vector<std::string> inputParts;
	std::string line = "0";
	while (std::getline(std::cin, line))
	{
		try
		{
			if (line.empty())
			{
				break;
			}

			boost::split(inputParts, line, boost::is_any_of(" "));
			if (inputParts.size() == 1 && inputParts[0] == std::string("Info"))
			{
				PrintInfo();
			}
			else if (inputParts.size() == 1 && inputParts[0] == std::string("EngineOn"))
			{
				m_car.TurnOnEngine();
			}
			else if (inputParts.size() == 1 && inputParts[0] == std::string("EngineOff"))
			{
				m_car.TurnOffEngine();
			}
			else if (inputParts.size() == 2 && inputParts[0] == std::string("SetGear"))
			{
				m_car.SetGear(std::stoi(inputParts[1]));
			}
			else if (inputParts.size() == 2 && inputParts[0] == std::string("SetSpeed"))
			{
				m_car.SetSpeed(std::stoi(inputParts[1]));
			}
			else
			{
				std::cout << "Error command" << std::endl;
			}
		}
		catch (...)
		{
			std::cout << "Error: non-number element." << std::endl;
		}
		
	}
	return true;
}