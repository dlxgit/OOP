#include "stdafx.h"
#include "../Decode.h"

BOOST_AUTO_TEST_SUITE(HtmlDecodeSuite)

BOOST_AUTO_TEST_CASE(CheckConvertFromHTML_EmptyString)
{
	BOOST_CHECK(HtmlDecode("") == "");
}

BOOST_AUTO_TEST_CASE(CheckConvertFromHTML_CorrectExpression1)
{
	BOOST_CHECK(HtmlDecode("Cat &lt;says&gt; &quot;Meow&quot;.M&amp;M&apos;s") == "Cat <says> \"Meow\".M&M\'s");
}

BOOST_AUTO_TEST_CASE(CheckConvertFromHTML_CorrectExpression2)
{
	BOOST_CHECK(HtmlDecode("&quot; &apos; &lt; &llt; &gt; &amp;") == "\" ' < &llt; > &");
}

BOOST_AUTO_TEST_SUITE_END()