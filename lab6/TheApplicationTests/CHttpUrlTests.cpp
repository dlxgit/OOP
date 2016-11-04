#include "stdafx.h"
#include "../CHttpUrl/CHttpUrl.h"
#include "../CHttpUrl/CUrlParsingError.h"

void VerifyGivenUrl(const CHttpUrl & url, const std::string& domain, const std::string& document, const Protocol & protocol, const unsigned short& port)
{
	BOOST_CHECK(url.GetDocument() == document);
	BOOST_CHECK(url.GetDomain() == domain);
	BOOST_CHECK(url.GetPort() == port);
	BOOST_CHECK(url.GetProtocol() == protocol);
}



BOOST_AUTO_TEST_SUITE(CHttpUrl_tests)

BOOST_AUTO_TEST_SUITE(throws_exception)

BOOST_AUTO_TEST_CASE(if_incorrect_protocol)
{
	BOOST_REQUIRE_THROW(CHttpUrl url("httk://google.ru"), CUrlParsingError);
}

BOOST_AUTO_TEST_CASE(if_incorrect_protocol_delimeter)
{
	BOOST_REQUIRE_THROW(CHttpUrl url("http:/google.ru"), CUrlParsingError);
}

BOOST_AUTO_TEST_SUITE(if_incorrect_domain)

BOOST_AUTO_TEST_CASE(name_with_spaces)
{
	BOOST_REQUIRE_THROW(CHttpUrl url("http://g oogle.ru"), CUrlParsingError);
}
BOOST_AUTO_TEST_CASE(name_with_incorrect_symbols)
{
	BOOST_REQUIRE_THROW(CHttpUrl url("http://goo&gle.ru"), CUrlParsingError);
}
BOOST_AUTO_TEST_CASE(name_declatration_missing)
{
	BOOST_REQUIRE_THROW(CHttpUrl url("http://.ru"), CUrlParsingError);
}
BOOST_AUTO_TEST_CASE(type_declaration_is_missing)
{
	BOOST_REQUIRE_THROW(CHttpUrl url("http://google"), CUrlParsingError);
}
BOOST_AUTO_TEST_CASE(type_with_incorrect_symbols)
{
	BOOST_REQUIRE_THROW(CHttpUrl url("http://google.ru_"), CUrlParsingError);
}
BOOST_AUTO_TEST_CASE(no_throw_exeption_for_empty_document)
{
	BOOST_REQUIRE_NO_THROW(CHttpUrl url("https://github.com/"));
	BOOST_REQUIRE_NO_THROW(CHttpUrl url("https://github.com"));
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_CASE(if_missing_port)
{
	BOOST_REQUIRE_THROW(CHttpUrl url("http:/google.ru:/"), CUrlParsingError);
}
BOOST_AUTO_TEST_CASE(if_incorrect_port)
{
	BOOST_REQUIRE_THROW(CHttpUrl url("http:/google.ru:84g5/"), CUrlParsingError);
}
BOOST_AUTO_TEST_CASE(if_incorrect_port_)
{
	BOOST_REQUIRE_THROW(CHttpUrl url("http:/google.ru:d/"), CUrlParsingError);
}
BOOST_AUTO_TEST_CASE(if_incorrect_document)
{
	BOOST_REQUIRE_THROW(CHttpUrl url("http:/google.ru/ lk"), CUrlParsingError);
}
BOOST_AUTO_TEST_CASE(throw_exeption_for_incorrect_domain)
{
	BOOST_REQUIRE_THROW(CHttpUrl("https://githubcom/OOP/"), CUrlParsingError);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(correct_data_filling)

BOOST_AUTO_TEST_CASE(if_initialize_from_string)
{
	CHttpUrl url("http://google.ru/docs/sdj/");
	VerifyGivenUrl(url, "google.ru", "/docs/sdj/", HTTP, 80);
}
BOOST_AUTO_TEST_CASE(if_initialize_from_not_full_data)
{
	CHttpUrl url("google.ru", "/doc");
	VerifyGivenUrl(url, "google.ru", "/doc", HTTP, 80);
}
BOOST_AUTO_TEST_CASE(if_initialize_from_full_data)
{
	CHttpUrl url("google.ru", "doc", HTTPS, 45);
	VerifyGivenUrl(url, "google.ru", "/doc", HTTPS, 45);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(get_url_function_works_correct)

BOOST_AUTO_TEST_CASE(_if_port_is_declared_by_protocol_not_prints_port)
{
	std::string givenUrl = "https://github.com/";
	CHttpUrl url = CHttpUrl(givenUrl);
	BOOST_CHECK_EQUAL(url.GetURL(), givenUrl);

	givenUrl = "http://github.com/";
	url = CHttpUrl(givenUrl);
	BOOST_CHECK_EQUAL(url.GetURL(), givenUrl);
}
BOOST_AUTO_TEST_CASE(_if_port_declared_by_user_not_prints_port)
{
	std::string givenUrl = "http://github.com:80/hello/";
	CHttpUrl url = CHttpUrl(givenUrl);
	BOOST_CHECK_EQUAL(url.GetURL(), "http://github.com/hello/");

	givenUrl = "https://github.com:443/hello/";
	url = CHttpUrl(givenUrl);
	BOOST_CHECK_EQUAL(url.GetURL(), "https://github.com/hello/");
}
BOOST_AUTO_TEST_CASE(_if_for_http_port_443_prints_port)
{
	std::string givenUrl = "http://github.com:443/hello/";
	CHttpUrl url = CHttpUrl(givenUrl);
	BOOST_CHECK_EQUAL(url.GetURL(), "http://github.com:443/hello/");
}
BOOST_AUTO_TEST_CASE(_if_for_https_port_80_prints_port)
{
	std::string givenUrl = "https://github.com:80/hello/";
	CHttpUrl url = CHttpUrl(givenUrl);
	BOOST_CHECK_EQUAL(url.GetURL(), "https://github.com:80/hello/");
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(throwing_exception_if)

BOOST_AUTO_TEST_CASE(_spaces_in_document)
{
	BOOST_REQUIRE_THROW(CHttpUrl url("google.ru", "/docs /sdj/", HTTP, 80), CUrlParsingError);
}
BOOST_AUTO_TEST_CASE(_spaces_in_domain)
{
	BOOST_REQUIRE_THROW(CHttpUrl("goo gle.ru", "/docs", HTTP, 80), CUrlParsingError);
}
BOOST_AUTO_TEST_CASE(_empty_domain)
{
	BOOST_REQUIRE_THROW(CHttpUrl("", "/docs", HTTP, 80), CUrlParsingError);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()