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
	// инициализация комплексного числа значениями действительной и мнимой частей
	CComplex(double real = 0, double image = 0)
	{
		m_imaginaryPart = image;
		m_realPart = real;
	}

	// возвращает действительную часть комплексного числа
	double Re()const;
	// возвращает мнимую часть комплексного числа
	double Im()const;
	// возвращает модуль комплексного числа
	double GetMagnitude()const;
	// возвращает аргумент комплексного числа
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