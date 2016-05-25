#pragma once
#include <fstream>
#include <iomanip>
#include "Calculate.h"


struct QuadraticEquationSolutionPrinter : public boost::static_visitor<void>
{
	QuadraticEquationSolutionPrinter(std::ofstream & strm, const unsigned & precision)
		:m_strm(strm)
	{
		calculatingPrecision = precision;
	}

	void operator() (double x)
	{
		m_strm << std::fixed << std::setprecision(calculatingPrecision) << x << std::endl;

	}

	void operator() (TwoRoos roots)
	{
		m_strm << std::fixed << std::setprecision(calculatingPrecision) << roots.first << "; " << roots.second << std::endl;
	}

	void operator() (NoRealRoots)
	{
		m_strm << "No real roots" << std::endl;
	}

	void operator() (NotAQuadraticEquation)
	{
		m_strm << "Not a quadratic equation" << std::endl;
	}

private:
	std::ostream & m_strm;
	unsigned calculatingPrecision;
};