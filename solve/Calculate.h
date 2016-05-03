#pragma once
#include <vector>
#include <string>
#include <boost/variant.hpp>

typedef std::pair<double, double> TwoRoos;
struct NoRealRoots {};
struct NotAQuadraticEquation {};
typedef boost::variant<NoRealRoots, double, TwoRoos, NotAQuadraticEquation> QuadraticEquationSolution;

double ComputeDiscriminant(const double & a, const double & b, const double & c);

QuadraticEquationSolution ComputeRoots(const double & a, const double & b, const double & c);