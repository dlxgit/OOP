#include "stdafx.h"
#include "../CStringList/CStringList.h"
#include <vector>

struct empty_list_
{
	CStringList list;
};


BOOST_FIXTURE_TEST_SUITE(Operations_with_empty_list, empty_list_)

	BOOST_AUTO_TEST_SUITE(is_empty_after_creating)
		BOOST_AUTO_TEST_CASE(is_empty)
		{
			BOOST_CHECK_EQUAL(list.size(), 0);
			BOOST_CHECK(list.empty());
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(push_element_into_list)

		BOOST_AUTO_TEST_CASE(push_back)
		{
			list.push_back("first_elem");
			BOOST_CHECK_EQUAL(list.size(), 1);
			list.push_back("second_elem");
			BOOST_CHECK_EQUAL(list.size(), 2);
			BOOST_CHECK(!list.empty());
		}

		BOOST_AUTO_TEST_CASE(push_front)
		{
			list.push_front("second");
			BOOST_CHECK_EQUAL(list.size(), 1);
			list.push_front("first");
			BOOST_CHECK_EQUAL(list.size(), 2);
			BOOST_CHECK(!list.empty());
		}	

	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(try_erase_element_of_empty_list)
	
		BOOST_AUTO_TEST_CASE(cannot_erase_by_nullptr)
		{
			BOOST_REQUIRE_THROW(list.erase(list.begin()), std::out_of_range);
		}
	
	BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()


struct filled_list_ : public empty_list_
{
	filled_list_()
	{
		list.push_back("1");
		list.push_back("2");
		list.push_back("3");
	}
	std::vector<std::string> values = { "1", "2", "3" };
};


BOOST_FIXTURE_TEST_SUITE(operations_with_filled_list, filled_list_)

	BOOST_AUTO_TEST_CASE(can_loop_all_iterators_of_list)
	{
		size_t index = 0;
		for (auto iter = list.begin(); iter != list.end(); ++iter)
		{
			BOOST_CHECK(*iter == values[index]);
			++index;
		}
	}

	BOOST_AUTO_TEST_CASE(can_loop_all_reversed_iterators)
	{
		size_t index = list.size() - 1;
		for (auto iter = list.rbegin(); iter != list.rend(); --iter)
		{
			BOOST_CHECK(*iter == values[index]);
			--index;
		}
	}

	BOOST_AUTO_TEST_CASE(can_get_access_to_elements_from_range_based_for)
	{
		size_t index = 0;
		for (auto str : list)
		{
			BOOST_CHECK(str == values[index]);
			++index;
		}
	}

	BOOST_AUTO_TEST_CASE(list_is_empty)
	{
		list.clear();
		BOOST_CHECK(list.empty());
		BOOST_CHECK_EQUAL(list.size(), 0);
	}

	BOOST_AUTO_TEST_CASE(iterator_operations)
	{
		auto it = list.begin();
		BOOST_CHECK(list.begin() == (list.begin() + 0));
		BOOST_CHECK(list.begin() + 1 == ++list.begin());
		BOOST_CHECK_EQUAL(*(list.begin() + 1), values[1]);
		BOOST_CHECK_EQUAL(*(list.begin() + 2), values[2]);
		BOOST_REQUIRE_THROW(list.begin() + 3, std::out_of_range);

		list.clear();
		BOOST_REQUIRE_NO_THROW(list.begin());
	}

	BOOST_AUTO_TEST_CASE(insert_element_at_middle)
	{
		auto it = ++list.begin();
		list.insert(it, "element next to head");
		BOOST_CHECK_EQUAL(*(list.begin() + 1), "element next to head");
		BOOST_CHECK_EQUAL(*(++list.begin()), "element next to head");
		BOOST_CHECK_EQUAL(*(list.begin()), "1");
		BOOST_CHECK_EQUAL(*(list.begin() + 2), "2");
		BOOST_CHECK_EQUAL(*(list.begin() + 3), "3");
		BOOST_REQUIRE_THROW(*(list.begin() + 4), std::out_of_range);
	}

	BOOST_AUTO_TEST_CASE(insert_element_at_beginning)
	{
		list.insert(list.begin(), "0");
		BOOST_CHECK_EQUAL(*list.begin(), "0");
		BOOST_CHECK_EQUAL(*(list.begin() + 1), "1");
	}

	BOOST_AUTO_TEST_CASE(insert_element_at_last_iterator_pos)
	{
		list.insert(list.begin() + (list.size() - 1), "asd");
		BOOST_CHECK_EQUAL(*(list.begin() + (list.size() - 1)), "3");
		BOOST_CHECK_EQUAL(*(list.begin() + (list.size() - 2)), "asd");
		BOOST_CHECK_EQUAL(*(list.begin() + (list.size() - 3)), "2");
	}

	BOOST_AUTO_TEST_CASE(can_erase_element_at_iterator_pos)
	{
		CStringList::CIterator it = ++list.begin();
		list.erase(it);
		BOOST_CHECK_EQUAL(*++list.begin(), "3");

		list.erase(list.begin());
		BOOST_CHECK_EQUAL(*list.begin(), "3");

		list.erase(list.begin());
		BOOST_CHECK(list.empty());
	}

BOOST_AUTO_TEST_SUITE_END()