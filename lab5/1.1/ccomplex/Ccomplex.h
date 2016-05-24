#pragma once
#include <string>
#include <iostream>
#define _USE_MATH_DEFINES 
#include <math.h>
#include <float.h>


using namespace std;


class CComplex
{
public:
	// ������������� ������������ ����� ���������� �������������� � ������ ������
	CComplex(double real = 0, double image = 0)
	{
		m_imaginaryPart = image;
		m_realPart = real;
	}

	// ���������� �������������� ����� ������������ �����
	double Re()const;
	// ���������� ������ ����� ������������ �����
	double Im()const;
	// ���������� ������ ������������ �����
	double GetMagnitude()const;
	// ���������� �������� ������������ �����
	double GetArgument()const;

	CComplex & operator+=(const CComplex& right);
	CComplex & operator-=(const CComplex& right);
	CComplex & operator*=(const CComplex& right);
	CComplex & operator/=(const CComplex& right);
	CComplex const operator+()const;
	CComplex const operator-()const;

private:

	double m_realPart;
	double m_imaginaryPart;
};

CComplex const operator+(const CComplex& left, const CComplex& right);
CComplex const operator-(const CComplex& left, const CComplex& right);
CComplex const operator*(const CComplex& left, const CComplex& right);
CComplex const operator/(const CComplex& left, const CComplex& right);
bool const operator==(const CComplex& left, const CComplex& right);
bool const operator!=(const CComplex& left, const CComplex& right);