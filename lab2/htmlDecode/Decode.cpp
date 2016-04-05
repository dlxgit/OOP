#include "stdafx.h"
#include "Decode.h"

std::string HtmlDecode(std::string const & html)
{
	std::string resultStr = html;

	boost::replace_all(resultStr, "&quot;", "\"");
	boost::replace_all(resultStr, "&apos;", "`");
	boost::replace_all(resultStr, "&lt;", "<");
	boost::replace_all(resultStr, "&gt;", ">");
	boost::replace_all(resultStr, "&amp;", "&");

	return resultStr;
}

std::string ReadString()
{
	std::string line;
	std::getline(std::cin, line);
	return line;
}

void PrintResult(std::string const & resultStr)
{
	std::cout << "Result:\n" << resultStr << std::endl;
}