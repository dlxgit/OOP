#pragma once
#include "stdafx.h"
#include <string>
#include <iostream>
#include <array>


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
	std::array<int, 2> GetSpeedRange(int gear) const;
	std::array<std::array<int, 2>, 7> m_speedRanges;

	CCar::Direction m_direction;
	bool m_isEngineTurnedOn;
	int m_speed;
	int m_gear;
};