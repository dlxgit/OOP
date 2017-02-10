#pragma once
#include <string>

class IPerson
{
public:
	virtual ~IPerson();

	virtual std::string GetName()const = 0;
	virtual std::string GetSurName()const = 0;
	virtual std::string GetFatherName()const = 0;
	virtual std::string GetAddress()const = 0;

	virtual void SetName(const std::string & name) = 0;
	virtual void SetSurName(const std::string & surname) = 0;
	virtual void SetFatherName(const std::string & fatherName) = 0;
	virtual void SetAddress(const std::string & address) = 0;
};