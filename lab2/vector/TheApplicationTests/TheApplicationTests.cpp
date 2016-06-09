// TheApplicationTests.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "../MultiplyElements.h"



BOOST_AUTO_TEST_SUITE(VectorTests)

BOOST_AUTO_TEST_CASE(CheckMultiplyElements_Empty_Vector)
{
	std::vector<double> emptyVec;
	std::vector<double> result = ComputeMultipiedVector(emptyVec);
	BOOST_CHECK(result == emptyVec);
}

BOOST_AUTO_TEST_CASE(CheckMultiplyElements_By_2)
{
	std::vector<double> result = ComputeMultipiedVector({ 5.1,3.0, 2, 4 });
	std::vector<double> expected = { 10.2, 6, 4, 8};
	BOOST_CHECK(result == expected);
}

BOOST_AUTO_TEST_CASE(CheckMultiplyElements_By_Negative)
{
	std::vector<double> result = ComputeMultipiedVector({ -5,1,0,3.0,2.2 });
	std::vector<double> expected = { 25, -5, 0, -15, -11 };
	BOOST_CHECK(result == expected);
}

BOOST_AUTO_TEST_CASE(CheckMultiplyElements_By_0)
{
	std::vector<double> result = ComputeMultipiedVector({ 1,2,5,6,4,0,10.5 });
	std::vector<double> expected = { 0, 0, 0, 0, 0, 0, 0 };
	BOOST_CHECK(result == expected);
}

BOOST_AUTO_TEST_SUITE_END()