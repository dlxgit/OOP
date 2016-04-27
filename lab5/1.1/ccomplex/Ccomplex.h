#pragma once
#include <string>
#include <iostream>

using namespace std;

class CComplex
{
public:
	// инициализация комплексного числа значениями действительной и мнимой частей
	CComplex(double real = 0, double image = 0)
	{
		m_realPart = real;
		m_imaginaryPart = image;
	}

	// возвращает действительную часть комплексного числа
	double Re()const;

	// возвращает мнимую часть комплексного числа
	double Im()const;

	// возвращает модуль комплексного числа
	double GetMagnitude()const;

	// возвращает аргумент комплексного числа
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
