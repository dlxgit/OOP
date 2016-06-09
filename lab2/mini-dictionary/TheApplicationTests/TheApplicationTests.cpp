// TheApplicationTests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../Dictionary.h"

typedef std::pair<std::string, std::string> DictElement;

struct EmptyDictFixture
{
	Dictionary dict = {};
};

BOOST_FIXTURE_TEST_SUITE(Empty_Dictionary, EmptyDictFixture)
	BOOST_AUTO_TEST_CASE(Read_Empty_Dictionary)
	{
		auto dictionary = ReadDataFromFile("incorrectFile");
		BOOST_CHECK(dictionary == Dictionary());
	}

	BOOST_AUTO_TEST_CASE(AddElementInDict)
	{
		AddElement(dict, DictElement("car", "машина"));
		BOOST_CHECK(HasWord(dict, "car"));
		BOOST_CHECK(!HasWord(dict, "машина"));
	}

BOOST_AUTO_TEST_SUITE_END();


struct DictFixture
{
	Dictionary dict = { {"cat", "кошка"}, {"dog", "собака"}, {"bird", "птица"} };
};

BOOST_FIXTURE_TEST_SUITE(Filled_Dictionary, DictFixture)

	BOOST_AUTO_TEST_CASE(Can_save_dictionary)
	{
		AddElement(dict, { "monkey", "обезьяна" });
		SaveDictionaryInFile(dict);
		Dictionary newDict = ReadDataFromFile();
		Dictionary expected = { { "cat", "кошка" },{ "dog", "собака" },{ "bird", "птица" },{ "monkey", "обезьяна" } };
		BOOST_CHECK(newDict == expected);
	}

	BOOST_AUTO_TEST_CASE(Can_find_existing_word_in_dict)
	{
		BOOST_CHECK(HasWord(dict, "cat"));
		BOOST_CHECK(!HasWord(dict, "bear"));
	}



	BOOST_AUTO_TEST_CASE(Get_translation_of_)
	{
		AddElement(dict, { "cat", "кот" });

		BOOST_CHECK(GetTranslation(dict, "cat") == std::string("кошка кот "));
	}

BOOST_AUTO_TEST_SUITE_END();