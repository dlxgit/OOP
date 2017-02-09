#pragma once
#include <string>


class IPerson
{
public:
	virtual std::string GetName()const;
	virtual void SetName(const std::string & name);
	virtual std::string GetSurName()const;
	virtual void SetSurName(const std::string & surname);
	virtual std::string GetFatherName()const;
	virtual std::string SetFatherName(const std::string & fatherName);
	virtual std::string GetAddress()const;
	virtual void SetAddress(const std::string & address);
};


template <typename Base>
class CPersonImpl : public Base
{
public:
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
	virtual std::string SetFatherName(const std::string & fatherName)
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

private:
	std::string m_name;
	std::string m_surname;
	std::string m_fatherName;
	std::string m_address;
};

template <typename Base>
class CStudentImpl : public CPersonImpl<Base>
{
	virtual std::string GetUniversity()const
	{
		return m_university;
	}
	virtual std::string GetUniversity(const std::string & university)
	{
		m_university = university;
	}
	virtual unsigned GetId()
	{
		return m_id;
	}
	virtual unsigned SetId(unsigned id)		
	{
		m_id = id;
	}

private:
	std::string m_university;
	unsigned m_id;
};


class IPupil: public IPerson
{
public:
	virtual std::string GetSchool() const;
	virtual std::string GetClass() const;
	virtual void SetSchool();
	virtual void SetClass();
};

class CPupil : public CPersonImpl<IPupil>
{
public:
	virtual std::string GetSchool() const
	{
		return m_school;
	}
	virtual std::string GetClass() const
	{
		return m_class;
	}
	virtual void SetSchool(const std::string & school)
	{
		m_school = school;
	}
	virtual void SetClass(const std::string & newClass)
	{
		m_class = newClass;
	}
private:
	std::string m_school;
	std::string m_class;
};

class ITeacher : public IPerson
{
public:
	virtual std::string GetSubject() const;
	virtual void SetSubject(const std::string & subject);
};

class CTeacher : public CPersonImpl<ITeacher>
{
public:
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

class IStudent : public IPerson
{
public:
	virtual std::string GetUniversity()const;
	virtual std::string GetUniversity(const std::string & university);
	virtual unsigned GetId();
	virtual unsigned SetId(unsigned id);
};

class IAdvancedStudent : public IStudent
{
public:
	virtual std::string GetDissertationTopic() const;
	virtual void SetDissertationTopic(const std::string & topic);
};


class CAdvancedStudent : public CStudentImpl<IAdvancedStudent>
{
public:
	virtual std::string GetDissertationTopic() const
	{

	}
	virtual void SetDissertationTopic(const std::string & topic)
	{

	}
private:
	std::string m_dissertationTopic;
};

class CStudent : public CStudentImpl<IStudent>
{
public:
	virtual std::string GetUniversity()const
	{
		return m_university;
	}
	virtual void SetUniversity(const std::string & university)
	{
		m_university = university;
	}
	virtual unsigned GetId()
	{
		return m_id;
	}
	virtual unsigned SetId(unsigned id)
	{
		m_id = id;
	}
private:
	std::string m_university;
	unsigned m_id;
};



class IWorker : public IPerson
{
	virtual std::string GetSpeciality()const;
	virtual void SetSpeciality(const std::string & speciality);
};

class CWorker : public CPersonImpl<IWorker>
{
public:
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