#pragma once
#include "CPersonImpl.h"

 template <typename Base>
class CStudentImpl : public CPersonImpl<Base>
{
public:
	CStudentImpl(const std::string & name,
		const std::string & surname,
		const std::string & fatherName,
		const std::string & address,
		const std::string & university,
		unsigned id)
		:
		CPersonImpl(name, surname, fatherName, address),
		m_university(university),
		m_id(id)
	{};

	virtual std::string GetUniversity() const
	{
		return m_university;
	}
	virtual unsigned GetId() const
	{
		return m_id;
	}

private:
	std::string m_university;
	unsigned m_id;
};