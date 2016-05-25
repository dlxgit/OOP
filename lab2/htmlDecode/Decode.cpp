#include "stdafx.h"
#include "Decode.h"


std::string HtmlDecode(std::string const & html)
{
	std::string resultStr = "";

	for (size_t i = 0; i < html.size(); i++)
	{
		if (html.compare(i, 6,"&quot;") == 0)
		{
			resultStr.append("\"");
			i += 5;
		}
		else if (html.compare(i, 6, "&apos;") == 0)
		{
			resultStr.append("'");
			i += 5;
		}
		else if (html.compare(i, 4,"&lt;") == 0)
		{
			resultStr.append("<");
			i += 3;
		}
		else if (html.compare(i, 4, "&gt;") == 0)
		{
			resultStr.append(">");
			i += 3;
		}
		else if (html.compare(i, 5, "&amp;") == 0)
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