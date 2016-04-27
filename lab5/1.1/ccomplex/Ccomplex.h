#pragma once
#include <string>
#include <iostream>

using namespace std;

class CComplex
{
public:
	// ������������� ������������ ����� ���������� �������������� � ������ ������
	CComplex(double real = 0, double image = 0)
	{
		m_realPart = real;
		m_imaginaryPart = image;
	}

	// ���������� �������������� ����� ������������ �����
	double Re()const;

	// ���������� ������ ����� ������������ �����
	double Im()const;

	// ���������� ������ ������������ �����
	double GetMagnitude()const;

	// ���������� �������� ������������ �����
	double GetArgument()const;


	const CComplex& operator+(const CComplex& right);
	const CComplex& operator-(const CComplex& right);
	const CComplex& operator*(const CComplex& right);
	const CComplex& operator/(const CComplex& right);

	const CComplex& operator+();
	const CComplex& operator-();

	CComplex& operator+=(const CComplex& right);
	CComplex& operator-=(const CComplex& right);
	
	CComplex& operator*=(const CComplex& right);
	CComplex& operator/=(const CComplex& right);

	const bool & operator==(const CComplex& right);
	const bool & operator!=(const CComplex& right);

	void operator<<(const CComplex& right);


private:

	double m_realPart;
	double m_imaginaryPart;
};
