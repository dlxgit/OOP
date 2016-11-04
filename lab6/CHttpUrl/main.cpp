#include "CHttpUrl.h"

int main()
{
	CHttpUrl url("http://google.ru/docs/sdj/");
	CHttpUrl url2("google.ru", "/docs/sdj/", HTTP, 80);
	
	std::string str1 = url.GetURL();
	std::string str2 = url2.GetURL();

	return 0;
}