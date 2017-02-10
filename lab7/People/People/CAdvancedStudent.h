#pragma once
#include "IAdvancedStudent.h"
#include "CStudentImpl.h"


class CAdvancedStudent : public CStudentImpl<IAdvancedStudent>
{
public:
	CAdvancedStudent(
		const std::string & name,
		const std::string & surname,
		const std::string & fatherName,
		const std::string & address,
		const std::string & university,
		unsigned id,
		const std::string & dissertationTopic)
		:
		CStudentImpl(name, surname, fatherName, address, university, id),
		m_dissertationTopic(dissertationTopic)
	{
	}
	virtual std::string GetDissertationTopic() const
	{
		return m_dissertationTopic;
	}
	virtual void SetDissertationTopic(const std::string & topic)
	{
		m_dissertationTopic = topic;
	}
private:
	std::string m_dissertationTopic;
};
