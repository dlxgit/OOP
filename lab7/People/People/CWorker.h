#pragma once
#include "CPersonImpl.h"
#include "IWorker.h"

class CWorker : public CPersonImpl<IWorker>
{
public:
	CWorker(
		const std::string & name,
		const std::string & surname,
		const std::string & fatherName,
		const std::string & address,
		const std::string & speciality)
		:
		CPersonImpl(name, surname, fatherName, address),
		m_speciality(speciality)
	{

	}
	virtual std::string GetSpeciality()const
	{
		return m_speciality;
	}
	virtual void SetSpeciality(const std::string & speciality)
	{
		m_speciality = speciality;
	}
private:
	std::string m_speciality;
};