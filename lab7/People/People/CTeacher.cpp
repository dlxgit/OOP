#pragma once
#include "CTeacher.h"


CTeacher::CTeacher(
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
std::string CTeacher::GetSubject() const
{
	return m_subject;
}