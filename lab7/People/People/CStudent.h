#pragma once
#include "CStudentImpl.h"
#include "IStudent.h"
 
class CStudent : public CStudentImpl<IStudent>
{
public:
	CStudent(
		const std::string & name,
		const std::string & surname,
		const std::string & fatherName,
		const std::string & address,
		const std::string & university, 
		unsigned id)
		:
		CStudentImpl<IStudent>(name,surname,fatherName,address, university, id)
	{}
};
