#pragma once
#include "IPerson.h"

class IPupil : public IPerson
{
public:
	virtual std::string GetSchool() const = 0;
	virtual std::string GetClass() const = 0;
	virtual void SetSchool(const std::string & school) = 0;
	virtual void SetClass(const std::string & newClass) = 0;
};