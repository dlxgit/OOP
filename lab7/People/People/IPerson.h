#pragma once
#include <string>

class IPerson
{
public:
	virtual ~IPerson() {};
	virtual std::string GetName()const = 0;
	virtual std::string GetSurName()const = 0;
	virtual std::string GetFatherName()const = 0;
	virtual std::string GetAddress()const = 0;
};