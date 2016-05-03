#pragma once
#include <fstream>
#include <iomanip>
#include "Calculate.h"

const static size_t CALC_PRECISION = 4;  //number of digits after "."


struct QuadraticEquationSolutionPrinter : public boost::static_visitor<void>
{
	QuadraticEquationSolutionPrinter(std::ofstream & strm)
		:m_strm(strm)
	{}

	void operator() (double x)
	{
		m_strm << std::fixed << std::setprecision(CALC_PRECISION) << x << std::endl;

	}

	void operator() (TwoRoos roots)
	{
		m_strm << std::fixed << std::setprecision(CALC_PRECISION) << roots.first << "; " << roots.second << std::endl;
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
};