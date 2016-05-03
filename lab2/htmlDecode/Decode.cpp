#include "stdafx.h"
#include "Decode.h"


std::string HtmlDecode(std::string const & html)
{
	std::string resultStr = "";

	for (size_t i = 0; i < html.size(); i++)
	{
		std::string aa = html.substr(i, 4);
		if (std::string(html.substr(i, 6)) == std::string("&quot;"))
		{
			resultStr.append("\"");
			i += 5;
		}
		else if (std::string(html.substr(i, 6)) == std::string("&apos;"))
		{
			resultStr.append("'");
			i += 5;
		}
		else if (std::string(html.substr(i, 4)) == std::string("&lt;"))
		{
			resultStr.append("<");
			i += 3;
		}
		else if (std::string(html.substr(i, 4)) == std::string("&gt;"))
		{
			resultStr.append(">");
			i += 3;
		}
		else if (std::string(html.substr(i, 5)) == std::string("&amp;"))
		{
			resultStr.append("&");
			i += 4;
		}
		else
		{
			resultStr += html[i];
		}
	}
	return resultStr;
}