#include "stdafx.h"
#include "CUrlParsingError.h"



CUrlParsingError::CUrlParsingError(const std::string & error) :
	std::invalid_argument(error)
{

}