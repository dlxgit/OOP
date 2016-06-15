#pragma once
#include <SFML/Graphics.hpp>
#include <string>

sf::Color ConvertHexToRgb(const std::string & hex)
{
	std::string hexCode = hex;
	if (hexCode.size() != 7 || hexCode[0] != '#')
	{
		return sf::Color::Black;
	}
	hexCode.erase(0, 1);
	int number = std::stoi(hexCode, 0, 16);

	return sf::Color(number / 0x10000, (number / 0x100) % 0x100, number % 0x100);
}