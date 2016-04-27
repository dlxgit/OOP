#include "Ccomplex.h"
#include <math.h>
#include <float.h>

/*
// ������������� ������������ ����� ���������� �������������� � ������ ������
CComplex::CComplex(double real = 0, double image = 0);
{

}
*/

// ���������� �������������� ����� ������������ �����
double CComplex::Re() const
{
	return m_realPart;
}

// ���������� ������ ����� ������������ �����
double CComplex::Im() const
{
	return m_imaginaryPart;
}

// ���������� ������ ������������ �����
double CComplex::GetMagnitude() const
{
	return sqrt(m_realPart * m_realPart + m_imaginaryPart * m_imaginaryPart);
}

// ���������� �������� ������������ �����
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