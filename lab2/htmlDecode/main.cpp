#include "stdafx.h"
#include "Decode.h"

int main()
{	
	std::string html;
	std::getline(std::cin, html);
	std::string resultString = HtmlDecode(html);
	std::cout << "Result:\n" << resultString << std::endl;
    return 0;
};