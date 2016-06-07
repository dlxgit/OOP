#pragma once
#include "stdafx.h"
#include <string>
#include <iostream>

class CCar
{
public:
	enum Direction
	{
		STAY,
		MOVE_FRONT,
		MOVE_BACK
	};

	CCar();
	bool TurnOnEngine();
	bool TurnOffEngine();
	bool SetGear(int gear);
	bool SetSpeed(int speed);
	int GetGear() const;
	int GetSpeed() const;
	bool IsEngineOn() const;
	Direction GetDirection() const;

private:
	std::pair<int, int> GetSpeedRange(int gear) const;

	bool m_isEngineTurnedOn;
	int m_speed;
	int m_gear;
};