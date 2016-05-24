#include "stdafx.h"
#include "Ccomplex.h"




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
	double real = Re();
	double image = Im();

	if (image == 0)
	{
		if (real < 0)
		{
			return M_PI;
		}
		if (real > 0)
		{
			return 0;
		}
		return 0;
	}

	if (real > 0)
	{
		return atan(m_imaginaryPart / m_realPart);
	}
	if (real < 0 && image >= 0)
	{
		return M_PI + atan(m_imaginaryPart / m_realPart);
	}
	if (real < 0 && image < 0)
	{
		return -M_PI + atan(m_imaginaryPart / m_realPart);
	}
	if (real == 0)
	{
		if (image > 0)
		{
			return M_PI / 2;
		}
		if (image < 0)
		{
			return -M_PI / 2;
		}
	}
	return 0;
}

CComplex const operator+(const CComplex& left, const CComplex& right)
{
	return CComplex(left.Re() + right.Re(), left.Im() + right.Im());
}

CComplex const operator-(const CComplex& left, const CComplex& right)
{
	return CComplex(left.Re() - right.Re(), left.Im() - right.Im());
}

CComplex const operator*(const CComplex& left, const CComplex& right)
{
	return CComplex(left.Re() * right.Re() - left.Im() * right.Im(),
		left.Re() * right.Im() + left.Im() * right.Re());
}

CComplex const operator/(const CComplex& left, const CComplex& right)
{
	if (right.Re() == 0 && right.Im() == 0)
	{
		return CComplex(std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity());
	}

	return CComplex((left.Re() * right.Re() + left.Im() * right.Im()) / (right.Re() * right.Re() + right.Im() * right.Im()), 
		(right.Re() * left.Im() - right.Im() * left.Re()) / (right.Re() * right.Re() + right.Im() * right.Im()));
}

CComplex const CComplex::operator+()const
{
	return *this;
}

CComplex const CComplex::operator-()const
{
	return CComplex(-this->Re(), -this->Im());
}

CComplex & CComplex::operator+=(const CComplex& right)
{
	m_realPart += right.m_realPart;
	m_imaginaryPart += right.m_imaginaryPart;
	return *this;
}


CComplex & CComplex::operator-=(const CComplex & right)
{
	m_realPart -= right.m_realPart;
	m_imaginaryPart -= right.m_imaginaryPart;
	return *this;
}

CComplex & CComplex::operator*=(const CComplex & right)
{
	double real = m_realPart * right.m_realPart - m_imaginaryPart * right.m_imaginaryPart;
	double image = m_realPart * right.m_imaginaryPart + m_imaginaryPart * right.m_realPart;
	m_realPart = real;
	m_imaginaryPart = image;
	return *this;
}

CComplex & CComplex::operator/=(const CComplex & right)
{
	if (right.Re() == 0 && right.Im() == 0)
	{
		m_realPart = std::numeric_limits<double>::infinity();
		m_imaginaryPart = std::numeric_limits<double>::infinity();
	}
	else
	{
		double realPart = (m_realPart * right.m_realPart + m_imaginaryPart * right.m_imaginaryPart) / (right.m_realPart * right.m_realPart + right.m_imaginaryPart * right.m_imaginaryPart);
		double imaginaryPart = (right.m_realPart * m_imaginaryPart - right.m_imaginaryPart * m_realPart) / (right.m_realPart * right.m_realPart + right.m_imaginaryPart * right.m_imaginaryPart);
		m_realPart = realPart;
		m_imaginaryPart = imaginaryPart;
	}
	return *this;
}

bool const operator==(const CComplex& left, const CComplex& right)
{
	bool numbersAreEqual = fabs(left.Re() - right.Re()) < DBL_MIN && fabs(left.Im() - right.Im()) < DBL_MIN;
	return numbersAreEqual;
}

bool const operator!=(const CComplex& left, const CComplex& right)
{
	return !(left == right);
}
