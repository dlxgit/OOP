#pragma once
#include "stdafx.h"
#include <string>


class CUrlParsingError : public std::invalid_argument
{
public:
	CUrlParsingError(const std::string & error);
};
