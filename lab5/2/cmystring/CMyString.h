#pragma once
#include <string>



class CMyString
{
public:

	// ����������� �� ���������
	CMyString();

	CMyString(const char * pString);

	// �����������, ���������������� ������ ������� �� 
	// ����������� ������� �������� �����
	CMyString(const char * pString, size_t length);

	// ����������������������
	CMyString(CMyString const & other);

	// ������������ ����������� (��� ������������, ����������� � C++11)
	//  ����������� ��������� � ������������ ���������� ������������ 
	CMyString(CMyString && other);

	// �����������, ���������������� ������ ������� �� 
	// ��������������������������� C++
	CMyString(std::string const & stlString);

	// ���������� ������ - ����������� ������, ���������� ��������� ������
	~CMyString();

	// ���������� ����� ������ (��� ����� ������������ �������� �������)
	size_t GetLength() const;

	// ���������� ��������� �� ������ �������� ������.
	// � ����� ������� ����������� ������ ���� ����������� ������� ������
	// ��������������������
	const char * GetStringData() const;

	// ���������� ��������� � �������� ������� ������ �� ������ length ��������
	

	CMyString & CMyString::operator+(const CMyString & right);

	CMyString & CMyString::operator+(const std::string & right);

	CMyString & CMyString::operator+(const char * right);

	CMyString & CMyString::operator+=(const CMyString & right);

	const bool & CMyString::operator==(const CMyString & right)const;

	const bool & CMyString::operator!=(const CMyString & right)const;


private:
	char * m_pStr;
	size_t m_size;
};