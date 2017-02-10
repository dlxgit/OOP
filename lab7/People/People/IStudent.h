#pragma once
#include "IPerson.h"


class IStudent : public IPerson
{
public:
	virtual ~IStudent() {};
	virtual std::string GetUniversity()const = 0;
	virtual unsigned GetId()const = 0;
};
