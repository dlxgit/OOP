#pragma once
#include "CWorker.h"

CWorker::CWorker(
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
std::string CWorker::GetSpeciality()const
{
	return m_speciality;
}