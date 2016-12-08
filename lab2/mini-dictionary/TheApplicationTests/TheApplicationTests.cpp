#include "stdafx.h"
#include "../Dictionary.h"
#include <fstream>

typedef std::pair<std::string, std::string> DictElement;

struct empty_dict_
{
	Dictionary dict = {};
};


BOOST_FIXTURE_TEST_SUITE(Empty_dictionary, empty_dict_)

	BOOST_AUTO_TEST_CASE(is_empty_after_reading_from_incorrect_file)
	{
		auto dictionary = ReadDataFromFile("incorrectFile");
		BOOST_CHECK(dictionary == Dictionary());
	}

	BOOST_AUTO_TEST_CASE(can_be_read_from_correct_file)
	{
		std::ofstream outputFile("dictionary.txt");
		std::string line = "cat/кошка";
		outputFile << line;
		outputFile.flush();

		auto dictionary = ReadDataFromFile("dictionary.txt");
		BOOST_CHECK_EQUAL(dictionary.size(), 1);
		BOOST_CHECK(HasWord(dictionary, "cat"));
		std::string translation = GetTranslation(dictionary, "cat");
		BOOST_CHECK_EQUAL(translation, "кошка ");
	}

	BOOST_AUTO_TEST_CASE(can_add_element_in_dict)
	{
		AddElement(dict, DictElement("car", "машина"));
		BOOST_CHECK(HasWord(dict, "car"));
		BOOST_CHECK(!HasWord(dict, "машина"));
	}

	BOOST_AUTO_TEST_CASE(cant_find_any_element)
	{
		BOOST_CHECK(!HasWord(dict, "any_word"));
	}

BOOST_AUTO_TEST_SUITE_END();


struct filled_dictionary_
{
	Dictionary dict = { {"cat", "кошка"}, {"dog", "собака"}, {"bird", "птица"} };
};

BOOST_FIXTURE_TEST_SUITE(Filled_Dictionary, filled_dictionary_)

	BOOST_AUTO_TEST_CASE(can_save_dictionary)
	{
		AddElement(dict, { "monkey", "обезьяна" });
		SaveDictionaryInFile(dict);
		Dictionary newDict = ReadDataFromFile();
		Dictionary expected = { { "cat", "кошка" },{ "dog", "собака" },{ "bird", "птица" },{ "monkey", "обезьяна" } };
		BOOST_CHECK(newDict == expected);
	}

	BOOST_AUTO_TEST_CASE(can_find_existing_word_in_dict)
	{
		BOOST_CHECK(HasWord(dict, "cat"));
		BOOST_CHECK(!HasWord(dict, "bear"));
	}

	BOOST_AUTO_TEST_CASE(can_get_translation_of_)
	{
		AddElement(dict, { "cat", "кот" });

		BOOST_CHECK(GetTranslation(dict, "cat") == std::string("кошка кот "));
	}

BOOST_AUTO_TEST_SUITE_END();

struct filled_dictionary_with_two_translations_of_one_word_
{
	Dictionary dict = { { "bird", "птица" } , {"bird", "ptica"} };
};

BOOST_FIXTURE_TEST_SUITE(filled_dictionary_with_two_translations_of_one_word, filled_dictionary_with_two_translations_of_one_word_)

	BOOST_AUTO_TEST_CASE(gets_all_translations_when_need_to_translate)
	{
		BOOST_CHECK_EQUAL(GetTranslation(dict, "bird"), "птица ptica ");
	}

BOOST_AUTO_TEST_SUITE_END()