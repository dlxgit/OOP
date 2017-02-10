#pragma once
#include "IPerson.h"


class IStudent : public IPerson
{
public:
	virtual std::string GetUniversity()const = 0;
	virtual unsigned GetId()const = 0;
	virtual void SetUniversity(const std::string & university) = 0;
	virtual void SetId(unsigned id) = 0;
};
