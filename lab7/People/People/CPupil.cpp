#pragma once
#include "CPupil.h"

CPupil::CPupil(const std::string & name,
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
std::string CPupil::GetSchool() const
{
	return m_school;
}
std::string CPupil::GetClass() const
{
	return m_class;
}