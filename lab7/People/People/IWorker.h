#pragma once
#include "IPerson.h"

class IWorker : public IPerson
{
	virtual std::string GetSpeciality()const = 0;
	virtual void SetSpeciality(const std::string & speciality) = 0;
};
