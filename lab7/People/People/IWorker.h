#pragma once
#include "IPerson.h"

class IWorker : public IPerson
{
public:
	virtual ~IWorker() {};
	virtual std::string GetSpeciality()const = 0;
};
