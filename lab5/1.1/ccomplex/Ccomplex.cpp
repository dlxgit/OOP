#include "Ccomplex.h"
#include <math.h>
#include <float.h>

/*
// инициализация комплексного числа значениями действительной и мнимой частей
CComplex::CComplex(double real = 0, double image = 0);
{

}
*/

// возвращает действительную часть комплексного числа
double CComplex::Re() const
{
	return m_realPart;
}

// возвращает мнимую часть комплексного числа
double CComplex::Im() const
{
	return m_imaginaryPart;
}

// возвращает модуль комплексного числа
double CComplex::GetMagnitude() const
{
	return sqrt(m_realPart * m_realPart + m_imaginaryPart * m_imaginaryPart);
}

// возвращает аргумент комплексного числа
double CComplex::GetArgument() const
{
	return atan(m_imaginaryPart / m_realPart);
}


const CComplex& CComplex::operator+(const CComplex& right)
{
	return CComplex(this->m_realPart + right.m_realPart, this->m_imaginaryPart + right.m_imaginaryPart);
}


const CComplex& CComplex::operator-(const CComplex& right)
{
	return CComplex(this->m_realPart - right.m_realPart, this->m_imaginaryPart - right.m_imaginaryPart);
}


const CComplex& CComplex::operator*(const CComplex& right)
{
	return CComplex(this->m_realPart - right.m_realPart, this->m_imaginaryPart - right.m_imaginaryPart);
}


const CComplex& CComplex::operator/(const CComplex& right)
{
	return CComplex((this->m_realPart * right.m_realPart + this->m_imaginaryPart * right.m_imaginaryPart) / (right.m_realPart + right.m_imaginaryPart),
		(right.m_realPart * this->m_imaginaryPart) / (this->m_imaginaryPart * this->m_imaginaryPart + right.m_imaginaryPart * right.m_imaginaryPart));
}


const CComplex& CComplex::operator+()
{
	return *this;
}


const CComplex& CComplex::operator-()
{
	return CComplex(-this->m_realPart, -this->m_imaginaryPart);
}


CComplex& CComplex::operator+=(const CComplex& right)
{
	return CComplex(this->m_realPart + right.m_realPart, this->m_imaginaryPart + this->m_imaginaryPart);
}


CComplex& CComplex::operator-=(const CComplex& right)
{
	this->m_realPart = this->m_realPart - right.m_realPart;
	this->m_imaginaryPart = this->m_imaginaryPart - this->m_imaginaryPart;
	return *this;
}


CComplex& CComplex::operator*=(const CComplex& right)
{
	this->m_realPart = this->m_realPart * right.m_realPart - this->m_imaginaryPart * right.m_imaginaryPart;
	this->m_imaginaryPart = this->m_realPart * right.m_imaginaryPart + this->m_imaginaryPart * right.m_realPart;
	return *this;
}


CComplex& CComplex::operator/=(const CComplex& right)
{
	this->m_realPart = (this->m_realPart * right.m_realPart + this->m_imaginaryPart * right.m_imaginaryPart) / (right.m_realPart + right.m_imaginaryPart);
	this->m_imaginaryPart = (right.m_realPart * this->m_imaginaryPart) / (this->m_imaginaryPart * this->m_imaginaryPart + right.m_imaginaryPart * right.m_imaginaryPart);
	return *this;
}


const bool & CComplex::operator==(const CComplex& right)
{
	bool numbersAreEqual = fabs(this->m_realPart - right.m_realPart) < DBL_MIN && fabs(this->m_imaginaryPart - right.m_imaginaryPart) < DBL_MIN;
	return numbersAreEqual;
}


const bool & CComplex::operator!=(const CComplex& right)
{
	return !((*this) == right);
}


void CComplex::operator<<(const CComplex& right)
{
	std::cout << this->m_realPart << this->m_imaginaryPart << std::endl;
}