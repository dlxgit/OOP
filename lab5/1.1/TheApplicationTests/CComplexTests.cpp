#include "stdafx.h"
#include "../Ccomplex/Ccomplex.h"

void CheckEqualComplexNumbers(const CComplex & first, double  secondReal, double secondImage)
{
	BOOST_CHECK_EQUAL(first.Re(), secondReal);
	BOOST_CHECK_EQUAL(first.Im(), secondImage);
}


BOOST_AUTO_TEST_SUITE(CComplexTests)


BOOST_AUTO_TEST_CASE(CalculateMagnitude)
{
	BOOST_CHECK_CLOSE(CComplex(2, 4).GetMagnitude(), 4.4721, 0.1);
	BOOST_CHECK_CLOSE(CComplex(6, -2).GetMagnitude(), 6.3245, 0.1);
}

BOOST_AUTO_TEST_CASE(CalculateArgumentIn1stPart)
{
	BOOST_CHECK_CLOSE(CComplex(1, 4).GetArgument(), 1.3258, 0.01);
	BOOST_CHECK_CLOSE(CComplex(2, 3).GetArgument(), 0.982, 0.1);
}

BOOST_AUTO_TEST_CASE(CalculateArgumentIn3rdPart)
{
	BOOST_CHECK_CLOSE(CComplex(-1, -4).GetArgument(), -M_PI + 1.3258, 0.1);
	BOOST_CHECK_CLOSE(CComplex(-2, -3).GetArgument(), -M_PI + 0.982, 0.1);
}

BOOST_AUTO_TEST_CASE(CalculateArgumentIn2ndPart)
{
	BOOST_CHECK_CLOSE(CComplex(-3, 5).GetArgument(), M_PI + (-1.0303), 0.1);
	BOOST_CHECK_CLOSE(CComplex(-4, 1).GetArgument(), M_PI + (-0.244), 0.1);
}

BOOST_AUTO_TEST_CASE(CalculateArgumentIn4thPart)
{
	BOOST_CHECK_CLOSE(CComplex(3, -5).GetArgument(), -1.0303, 0.01);
	BOOST_CHECK_CLOSE(CComplex(4, -1).GetArgument(), -0.2449, 0.1);
}

BOOST_AUTO_TEST_CASE(CalculateArgumentZero)
{
	BOOST_CHECK(CComplex(0).GetArgument() == 0);
}

BOOST_AUTO_TEST_CASE(CalculateArgumentZeroImage)
{
	BOOST_CHECK(CComplex(1,0).GetArgument() == 0);
}

BOOST_AUTO_TEST_CASE(CalculateArgumentZeroReal)
{
	BOOST_CHECK_CLOSE(CComplex(0, 1).GetArgument(), 1.5707, 0.01);
}

BOOST_AUTO_TEST_CASE(binaryPlus)
{
	CheckEqualComplexNumbers(CComplex(1, 1) + CComplex(1, 1), 2, 2);
	CheckEqualComplexNumbers(3 + CComplex(1, 1), 4, 1);
}


BOOST_AUTO_TEST_CASE(binaryMinus)
{
	CheckEqualComplexNumbers(CComplex(1,1) - CComplex(2,2), -1, -1);
	CheckEqualComplexNumbers(10.5 - CComplex(-5, -7), 15.5, 7);
}


BOOST_AUTO_TEST_CASE(binaryMul)
{
	CheckEqualComplexNumbers(CComplex(5,1) * CComplex(-10,2), -52, 0);
	CheckEqualComplexNumbers(3 * CComplex(3,4), 9, 12);
}


BOOST_AUTO_TEST_CASE(binaryDiv)
{
	CheckEqualComplexNumbers(CComplex(2,1) / CComplex(1,-2), 0, 1);
	CheckEqualComplexNumbers(CComplex(10, 7) / 0, std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity());
	CheckEqualComplexNumbers(CComplex(3,0) / CComplex(3,0), 1,0);
}


BOOST_AUTO_TEST_CASE(unaryPlus)
{
	CheckEqualComplexNumbers(+CComplex(2,3), 2, 3);
}


BOOST_AUTO_TEST_CASE(unaryMinus)
{
	CheckEqualComplexNumbers(-CComplex(5,10), -5, -10);
}

BOOST_AUTO_TEST_CASE(binaryPlusRebind)
{
	CheckEqualComplexNumbers(CComplex(1,1) += CComplex(1,1), 2,2 );
	CheckEqualComplexNumbers(4 + CComplex(2, 2), 6, 2);
}


BOOST_AUTO_TEST_CASE(binaryMinusRebind)
{
	CheckEqualComplexNumbers(CComplex(10,10) -= CComplex(5,5), 5, 5);
	CheckEqualComplexNumbers(7.3 - CComplex(5, 7), 2.3, -7);
}

BOOST_AUTO_TEST_CASE(binaryMulRebind)
{
	CheckEqualComplexNumbers(CComplex(-3,3) *= CComplex(5,-5), 0, 30);
	CheckEqualComplexNumbers(CComplex(-3, 3) *= 2, -6, 6);
}

BOOST_AUTO_TEST_CASE(binaryDivRebind)
{
	CheckEqualComplexNumbers(CComplex(4,1) /= CComplex(1,2), 1.2, -1.4);
	CheckEqualComplexNumbers(CComplex(4, 1) /= 2, 2, 0.5);
	CheckEqualComplexNumbers(CComplex(4, 1) / 0, std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity());
}

BOOST_AUTO_TEST_CASE(binaryIsEqual)
{
	BOOST_CHECK_EQUAL(CComplex(5.1, 3.3) == CComplex(5.1, 3.3), true);
	BOOST_CHECK_EQUAL(7 == CComplex(7, 9.9), false);
	BOOST_CHECK_EQUAL(3 == CComplex(3, 0), true);
}

BOOST_AUTO_TEST_CASE(binaryIsNotEqual)
{
	BOOST_CHECK_EQUAL(CComplex(5.2, 0) != CComplex(5.21, 0), true);
}

BOOST_AUTO_TEST_SUITE_END()
