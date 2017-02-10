#pragma once
#include "ITeacher.h"
#include "CPersonImpl.h"

class CTeacher : public CPersonImpl<ITeacher>
{
public:
	CTeacher(
		const std::string & name,
		const std::string & surname,
		const std::string & fatherName,
		const std::string & address,
		const std::string & subject)
		:
		CPersonImpl(name, surname, fatherName, address),
		m_subject(subject)
	{

	}
	virtual std::string GetSubject() const
	{
		return m_subject;
	}
	virtual void SetSubject(const std::string & subject)
	{
		m_subject = subject;
	}
private:
	std::string m_subject;
};