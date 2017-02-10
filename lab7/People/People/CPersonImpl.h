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
		):
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
	virtual void SetName(const std::string & name)
	{
		m_name = name;
	}
	virtual std::string GetSurName()const
	{
		return m_surname;
	}
	virtual void SetSurName(const std::string & surname)
	{
		m_surname = surname;
	}
	virtual std::string GetFatherName()const
	{
		return m_fatherName;
	}
	virtual void SetFatherName(const std::string & fatherName)
	{
		m_fatherName = fatherName;
	}
	virtual std::string GetAddress()const
	{
		return m_address;
	}
	virtual void SetAddress(const std::string & address)
	{
		m_address = address;
	}
	virtual ~CPersonImpl();

private:
	std::string m_name;
	std::string m_surname;
	std::string m_fatherName;
	std::string m_address;
};