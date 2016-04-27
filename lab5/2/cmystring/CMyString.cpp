#include "CMyString.h"



CMyString::CMyString(const char * pString)
{
	for (size_t i = 0; pString[i] != '\n'; i++)
	{
		m_pStr[i] = pString[i];
	}
}

CMyString::CMyString()
{
	m_pStr[0] = '\n';
}

CMyString::CMyString(const char * pString, size_t length)
{
	for (size_t i = 0; pString[i] != '\n' && i < length	; i++)
	{
		m_pStr[i] = pString[i];
	}
}

CMyString::CMyString(CMyString const & other)
{
	for (size_t i = 0; i < other.m_size; i++)
	{
		m_pStr[i] = other.m_pStr[i];
	}
	m_size = other.m_size;
}



size_t CMyString::GetLength()const
{
	return sizeof(m_pStr);
}


CMyString::~CMyString()
{
	delete[]m_pStr;
}


CMyString & CMyString::operator+(const CMyString & right)
{
	for (size_t i = 0; i < right.m_size; i++)
	{
		this->m_pStr[this->m_size + i] = right.m_pStr[i];
	}
	this->m_size = this->m_size + right.m_size;
	this->m_pStr[this->m_size] = '\n';

	return *this;
}

CMyString & CMyString::operator+(const std::string & right)
{
	for (size_t i = 0; i < right.size(); i++)
	{
		this->m_pStr[this->m_size + i] = right[i];
	}
	this->m_size = this->m_size + right.size();
	this->m_pStr[this->m_size] = '\n';
	return *this;
}

CMyString & CMyString::operator+(const char * right)
{
	size_t rightSize = 0;
	for (size_t i = 0; right[i] != NULL && right[i] != '\n' ; i++)
	{
		rightSize++;
	}

	for (size_t i = 0; i < rightSize; i++)
	{
		this->m_pStr[this->m_size + i] = right[i];
	}
	this->m_size = this->m_size + rightSize;
	this->m_pStr[this->m_size] = '\n';
	return *this;
}

CMyString & CMyString::operator+=(const CMyString & right)
{
	for (size_t i = 0; i < right.m_size; i++)
	{
		this->m_pStr[this->m_size + i] = right.m_pStr[i];
	}
	this->m_size = this->m_size + right.m_size;
	this->m_pStr[this->m_size] = '\n';

	return *this;
}

const bool & CMyString::operator==(const CMyString & right)const
{
	if ((this->m_size != right.m_size) || (this->GetLength() != right.GetLength()))
	{
		return false;
	}

	for (size_t i = 0; i < this->m_size && i < this->GetLength(); i++)
	{
		if (this->m_pStr[i] != right.m_pStr[i])
		{
			return false;
		}
	}
	return true;
}

const bool & CMyString::operator!=(const CMyString & right)const
{
	if (*this == right)
	{
		return false;
	}
	return true;
}