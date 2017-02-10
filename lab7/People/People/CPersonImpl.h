#pragma once
#include "IPerson.h"

template <typename Base>
class CPersonImpl : public Base
{
public:
	CPersonImpl(
		const std::string & name,
		const std::string & surname,
		const std::string & fatherName,
		const std::string & address
	) :
		m_name(name),
		m_surname(surname),
		m_fatherName(fatherName),
		m_address(address)
	{

	}
	virtual std::string GetName()const
	{
		return m_name;
	}
	virtual std::string GetSurName()const
	{
		return m_surname;
	}
	virtual std::string GetFatherName()const
	{
		return m_fatherName;
	}
	virtual std::string GetAddress()const
	{
		return m_address;
	}


private:
	std::string m_name;
	std::string m_surname;
	std::string m_fatherName;
	std::string m_address;
};