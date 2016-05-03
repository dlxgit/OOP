#include "Calculate.h"

double ComputeDiscriminant(const double & a, const double & b, const double & c)
{
	return b * b - (4 * a * c);
}

QuadraticEquationSolution ComputeRoots(const double & a, const double & b, const double & c)
{
	if (a == 0)
	{
		return NotAQuadraticEquation();
	}

	const double discriminant = ComputeDiscriminant(a, b, c);

	if (discriminant < 0)
	{
		return NoRealRoots();
	}

	if (discriminant == 0)
	{
		return -b / 2 * a; // one root
	}

	return std::make_pair((-b + sqrt(discriminant)) / (2 * a), 
						  (-b - sqrt(discriminant)) / (2 * a)); // Two roots
}