#pragma once
#include "stdafx.h"
#include "CCar.h"
#include <string>
#include <iostream>

#include <vector>

#include <boost/algorithm/algorithm.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>


class CCarController
{
public:
	CCarController() = default;
	void PrintInfo() const;
	bool HandleCommand();
private:
	CCar m_car;
};