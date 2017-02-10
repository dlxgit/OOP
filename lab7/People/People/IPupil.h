#pragma once
#include "IPerson.h"

class IPupil : public IPerson
{
public:
	virtual ~IPupil() {};
	virtual std::string GetSchool() const = 0;
	virtual std::string GetClass() const = 0;
};