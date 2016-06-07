#include "stdafx.h"
#include "CCar.h"

CCar::CCar()
{
	m_isEngineTurnedOn = false;
	m_speed = 0;
	m_gear = 0;
}

bool CCar::TurnOnEngine()
{
	if (IsEngineOn())
	{
		return false;
	}
	m_isEngineTurnedOn = true;
	return true;
}

bool CCar::IsEngineOn() const
{
	return m_isEngineTurnedOn;
}

bool CCar::TurnOffEngine()
{
	if (IsEngineOn() == true && m_gear == 0 && m_speed == 0)
	{
		m_isEngineTurnedOn = false;
		return true;
	}
	return false;
}

std::pair<int, int> CCar::GetSpeedRange(int gear) const
{
	switch (gear)
	{
	case -1:
		return std::make_pair<int, int>(0, 20);
		break;
	case 0:
		return std::make_pair<int, int>(-200, 200);
	case 1:
		return std::make_pair<int, int>(0, 30);
	case 2:
		return std::make_pair<int, int>(20, 50);
	case 3:
		return std::make_pair<int, int>(30, 60);
	case 4:
		return std::make_pair<int, int>(40, 90);
	case 5:
		return std::make_pair<int, int>(50, 150);
	default:
		break;
	}
	return std::make_pair<int, int>(-1, -1);
}

CCar::Direction CCar::GetDirection() const
{
	if (m_speed == 0)
	{
		return STAY;
	}
	if (GetGear() == -1)
	{
		return MOVE_BACK;
	}
	return MOVE_FRONT;
}


bool CCar::SetGear(int gear)
{
	int currentGear = GetGear();
	if (gear == currentGear)
	{
		return true;
	}
	if (!IsEngineOn())
	{
		std::cout << "Couldn't change gear(Engine is off)." << std::endl;
		return false;
	}

	if (currentGear == -1 && gear == 1 && GetSpeed() != 0)
	{
		std::cout << "Couldn't change gear(from -1 to 1 on speed)." << std::endl;
		return false;
	}
	if (gear == -1 && ((currentGear == 0 || currentGear == 1) && GetSpeed() != 0))
	{
		std::cout << "Couldn't change gear(from -1 to 1 on speed)." << std::endl;
		return false;
	}


	int currentSpeed = GetSpeed();
	std::pair<int, int> speedRange = GetSpeedRange(gear);
	if (currentSpeed >= speedRange.first && currentSpeed <= speedRange.second)
	{
		m_gear = gear;
		return true;
	}
	std::cout << "Couldn't change gear(Incorrect speed interval)." << std::endl;
	return false;
}

bool CCar::SetSpeed(int speed)
{
	if (!IsEngineOn())
	{
		std::cout << "Couldn't change speed(Engine is off)." << std::endl;
		return false;
	}
	if (GetGear() == 0 && speed > GetSpeed())
	{
		std::cout << "Couldn't change speed(can't increase speed on 0-gear)." << std::endl;
		return false;
	}
	std::pair<int, int> speedRange = GetSpeedRange(GetGear());
	if (speed >= speedRange.first && speed <= speedRange.second)
	{
		m_speed = speed;
		return true;
	}
	std::cout << "Couldn't change speed(Your gear does not support this speed)." << std::endl;
	return false;
}

int CCar::GetGear() const
{
	return m_gear;
}

int CCar::GetSpeed() const
{
	return m_speed;
}