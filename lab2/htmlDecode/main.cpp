#include "stdafx.h"
#include "Decode.h"

int main()
{	
	std::string html = ReadString();
	std::string resultString = HtmlDecode(html);
	PrintResult(resultString);
    return 0;
};