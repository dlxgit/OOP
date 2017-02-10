#pragma once
#include "IPupil.h"
#include "CPersonImpl.h"

class CPupil : public CPersonImpl<IPupil>
{
public:
	CPupil(const std::string & name,
		const std::string & surname,
		const std::string & fatherName,
		const std::string & address,
		const std::string & school,
		const std::string & newClass)
		:
		CPersonImpl(name, surname, fatherName, address),
		m_school(school),
		m_class(newClass)
	{}
	std::string GetSchool() const override
	{
		return m_school;
	}
	virtual std::string GetClass() const override
	{
		return m_class;
	}
private:
	std::string m_school;
	std::string m_class;
};