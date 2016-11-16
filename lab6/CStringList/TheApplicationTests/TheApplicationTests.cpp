#include "stdafx.h"
#include "../CStringList/CStringList.h"
#include <vector>
#include <iostream>

struct empty_list_
{
	CStringList list;
};


BOOST_FIXTURE_TEST_SUITE(empty_list, empty_list_)

	BOOST_AUTO_TEST_CASE(is_empty_after_creating)
	{
		BOOST_CHECK_EQUAL(list.Size(), 0);
		BOOST_CHECK(list.Empty());
	}
		
	BOOST_AUTO_TEST_SUITE(changes_size_after)

		BOOST_AUTO_TEST_CASE(push_back)
		{
			list.Push_back("first_elem");
			BOOST_CHECK_EQUAL(list.Size(), 1);
			list.Push_back("second_elem");
			BOOST_CHECK_EQUAL(list.Size(), 2);
			BOOST_CHECK(!list.Empty());
		}

		BOOST_AUTO_TEST_CASE(push_front)
		{
			list.Push_front("second");
			BOOST_CHECK_EQUAL(list.Size(), 1);
			list.Push_front("first");
			BOOST_CHECK_EQUAL(list.Size(), 2);
			BOOST_CHECK(!list.Empty());
		}

	BOOST_AUTO_TEST_SUITE_END()
	

	BOOST_AUTO_TEST_SUITE(can_be)

		BOOST_AUTO_TEST_CASE(cleared)
		{
			BOOST_REQUIRE_NO_THROW(list.Clear());
		}

	BOOST_AUTO_TEST_SUITE_END()


	BOOST_AUTO_TEST_SUITE(is_not_possible_to_erase_element)
	
		BOOST_AUTO_TEST_CASE(by_nullptr)
		{
			BOOST_REQUIRE_THROW(list.Erase(list.begin()), std::out_of_range);
		}
	
	BOOST_AUTO_TEST_SUITE_END()

	
	BOOST_AUTO_TEST_CASE(allows_changing_item_value_using_iterator)
	{
		list.Push_back("hello");
		BOOST_CHECK_EQUAL(*list.begin(), "hello");
		*list.begin() = "goodbye";
		BOOST_CHECK_EQUAL(*list.begin(), "goodbye"); // проверка не пройдет
	}

BOOST_AUTO_TEST_SUITE_END()


struct filled_list_ : public empty_list_
{
	filled_list_()
	{
		list.Push_back("1");
		list.Push_back("2");
		list.Push_back("3");
	}
	std::vector<std::string> values = { "1", "2", "3" };
};


BOOST_FIXTURE_TEST_SUITE(filled_list, filled_list_)

	BOOST_AUTO_TEST_SUITE(can_iterate_through_all_elements_by_)

		BOOST_AUTO_TEST_CASE(iterator_)
		{
			size_t index = 0;
			for (auto iter = list.begin(); iter != list.end(); ++iter)
			{
				BOOST_CHECK(*iter == values[index]);
				++index;
			}
		}

		BOOST_AUTO_TEST_CASE(reversed_iterators)
		{
			size_t index = list.Size() - 1;
			for (auto iter = list.Rbegin(); iter != list.Rend(); --iter)
			{
				BOOST_CHECK(*iter == values[index]);
				--index;
			}
		}

	BOOST_AUTO_TEST_SUITE_END()


	BOOST_AUTO_TEST_SUITE(can_change_elements_from)

		BOOST_AUTO_TEST_CASE(range_based_for)
		{
 			size_t index = 0;
 			for (auto str : list)
 			{
 				BOOST_CHECK(str == values[index]);
				++index;
			}
		}

		BOOST_AUTO_TEST_CASE(iterator)
		{
			std::string newValue = "newValue";
			*list.begin() = std::string("newValue");
			BOOST_CHECK_EQUAL(*list.begin(), newValue);
		}

	BOOST_AUTO_TEST_SUITE_END()


	BOOST_AUTO_TEST_CASE(should_not_cause_stack_oveflow_on_destruction)
	{
		{
			CStringList lst1;
			for (int i = 0; i < 100000; ++i)
			{
				lst1.Push_back("123");
			}
			std::cout << "(list is filled, ";
		}
		std::cout << "and successfully destroyed)" << std::endl;
	}


	BOOST_AUTO_TEST_SUITE(iterator_operator)

		BOOST_AUTO_TEST_CASE(prefix_incremenet_and_decrement_work_correctly)
		{
			auto it = list.begin();
			BOOST_CHECK_EQUAL(*(++it), values[1]);
			BOOST_CHECK_EQUAL(*(--it), values[0]);
		}

		BOOST_AUTO_TEST_CASE(postfix_incremenet_and_decrement_work_correctly)
		{
			auto it = list.begin();
			BOOST_CHECK_EQUAL(*(it++), values[0]);
			BOOST_CHECK_EQUAL(*(it--), values[1]);
			BOOST_CHECK_EQUAL(*it, values[0]);
		}

		BOOST_AUTO_TEST_CASE(plus_number_works_correctly)
		{
			BOOST_CHECK_EQUAL(*(list.begin() + 0), values[0]);
			BOOST_CHECK_EQUAL(*(list.begin() + 1), values[1]);
			BOOST_CHECK_EQUAL(*(list.begin() + 2), values[2]);
			BOOST_REQUIRE_THROW(list.begin() + 3, std::out_of_range);
		}

		BOOST_AUTO_TEST_CASE(is_equal_works_correctly)
		{
			BOOST_CHECK(++list.begin() == (list.begin() + 1));
			BOOST_CHECK((list.begin() == (list.begin() + 1)) == false);
		}

		BOOST_AUTO_TEST_CASE(is_not_equal_works_correctly)
		{
			auto it = list.begin();
			BOOST_CHECK((++list.begin() != (list.begin() + 1)) == false);
			BOOST_CHECK(list.begin() != (list.begin() + 1));
		}

		BOOST_AUTO_TEST_CASE(arrow_works_correctly)
		{
			BOOST_CHECK_EQUAL(list.begin()->length(), values[0].length());
		}

		BOOST_AUTO_TEST_CASE(star_works_correctly)
		{
			auto it = list.begin();
			BOOST_CHECK_EQUAL(*it, values[0]);
		}

	BOOST_AUTO_TEST_SUITE_END()


	BOOST_AUTO_TEST_CASE(can_erase_element_at_iterator_pos)
	{
		CStringList::CIterator it = ++list.begin();
		list.Erase(it);
		BOOST_CHECK_EQUAL(*++list.begin(), "3");

		list.Erase(list.begin());
		BOOST_CHECK_EQUAL(*list.begin(), "3");

		list.Erase(list.begin());
		BOOST_CHECK(list.Empty());
	}

	BOOST_AUTO_TEST_SUITE(is_empty_after)

		BOOST_AUTO_TEST_CASE(clearing)
		{
			list.Clear();
			BOOST_CHECK(list.Empty());
			BOOST_CHECK_EQUAL(list.Size(), 0);
		}
		BOOST_AUTO_TEST_CASE(erasing_all_elements)
		{
			while (list.begin() != nullptr)
			{
				list.Erase(list.begin());
			}
			BOOST_CHECK(list.Empty() && list.Size() == 0);
		}

	BOOST_AUTO_TEST_SUITE_END()


	BOOST_AUTO_TEST_SUITE(can_insert_element_in)

		BOOST_AUTO_TEST_CASE(middle)
		{
			auto it = ++list.begin();
			list.Insert(it, "element next to head");
			BOOST_CHECK_EQUAL(*(list.begin() + 1), "element next to head");
			BOOST_CHECK_EQUAL(*(++list.begin()), "element next to head");
			BOOST_CHECK_EQUAL(*(list.begin()), "1");
			BOOST_CHECK_EQUAL(*(list.begin() + 2), "2");
			BOOST_CHECK_EQUAL(*(list.begin() + 3), "3");
			BOOST_REQUIRE_THROW(*(list.begin() + 4), std::out_of_range);
		}

		BOOST_AUTO_TEST_CASE(beginning)
		{
			list.Insert(list.begin(), "0");
			BOOST_CHECK_EQUAL(*list.begin(), "0");
			BOOST_CHECK_EQUAL(*(list.begin() + 1), "1");
		}

		BOOST_AUTO_TEST_CASE(last_iterator_pos)
		{
			list.Insert(list.begin() + (list.Size() - 1), "asd");
			BOOST_CHECK_EQUAL(*(list.begin() + (list.Size() - 1)), "3");
			BOOST_CHECK_EQUAL(*(list.begin() + (list.Size() - 2)), "asd");
			BOOST_CHECK_EQUAL(*(list.begin() + (list.Size() - 3)), "2");
		}

	BOOST_AUTO_TEST_SUITE_END()

	
BOOST_AUTO_TEST_SUITE_END()