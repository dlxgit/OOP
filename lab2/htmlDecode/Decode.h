#pragma once
#include <boost/algorithm/string/replace.hpp>
#include <string>
#include <iostream>

std::string HtmlDecode(std::string const & html);

std::string ReadString();

void PrintResult(std::string const & resultStr);