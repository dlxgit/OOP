#include "stdafx.h"
#include "../CMyList/CMyList.h"
#include <vector>
#include <iostream>



struct empty_string_list_
{
	empty_string_list_() 
	{
		list = CMyList<std::string>();
	}
	CMyList<std::string> list;
};





BOOST_FIXTURE_TEST_SUITE(empty_string_list, empty_string_list_)
	
	BOOST_AUTO_TEST_CASE(is_empty_after_creating)
	{
		BOOST_CHECK_EQUAL(list.Size(), 0);
		BOOST_CHECK(list.Empty());
	}
		

	BOOST_AUTO_TEST_SUITE(changes_size_after)

		BOOST_AUTO_TEST_CASE(push_back)
		{
			list.PushBack("first_elem");
			BOOST_CHECK_EQUAL(list.Size(), 1);
			list.PushBack("second_elem");
			BOOST_CHECK_EQUAL(list.Size(), 2);
			BOOST_CHECK(!list.Empty());
		}

		BOOST_AUTO_TEST_CASE(push_front)
		{
			list.PushFront("second");
			BOOST_CHECK_EQUAL(list.Size(), 1);
			list.PushFront("first");
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
	
		BOOST_AUTO_TEST_CASE(by_begin_iterator)
		{
			BOOST_REQUIRE_THROW(list.Erase(list.begin()), std::out_of_range);
		}
	
	BOOST_AUTO_TEST_SUITE_END()

	
	BOOST_AUTO_TEST_CASE(allows_changing_item_value_using_iterator)
	{
		list.PushBack("hello");
		BOOST_CHECK_EQUAL(*list.begin(), "hello");
		*list.begin() = "goodbye";
		BOOST_CHECK_EQUAL(*list.begin(), "goodbye"); // проверка не пройдет (Исправлено!)
	}

BOOST_AUTO_TEST_SUITE_END()



struct filled_string_list_ : public empty_string_list_
{
	std::vector<std::string> values = { "1", "2", "3" };
	filled_string_list_()
	{
		for (auto el : values)
		{
			list.PushBack(el);
		}
	}

};


BOOST_FIXTURE_TEST_SUITE(filled_string_list, filled_string_list_)

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



		BOOST_AUTO_TEST_CASE(can_loop_through_range_based_for)
		{
 			size_t index = 0;
 			for (auto str : list)
 			{
 				BOOST_CHECK(str == values[index]);
				++index;
			}
		}

		BOOST_AUTO_TEST_CASE(can_change_elements_by_using_iterator)
		{
			std::string newValue = "newValue";
			*list.begin() = std::string("newValue");
			BOOST_CHECK_EQUAL(*list.begin(), newValue);
		}


	BOOST_AUTO_TEST_CASE(should_not_cause_stack_oveflow_on_destruction)
	{
		{
			CMyList<std::string> lst1;
			for (int i = 0; i < 100000; ++i)
			{
				lst1.PushBack("123");
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


	BOOST_AUTO_TEST_SUITE(can_erase_element_at_iterator_pos)
		BOOST_AUTO_TEST_CASE(middle)
		{
			CMyList<std::string>::CIterator it = ++list.begin();
			list.Erase(it);
			BOOST_CHECK_EQUAL(*list.begin(), "1");
			BOOST_CHECK_EQUAL(*++list.begin(), "3");
		}
		BOOST_AUTO_TEST_CASE(head)
		{
			CMyList<std::string>::CIterator it = list.begin();
			list.Erase(it);
			BOOST_CHECK_EQUAL(*list.begin(), "2");
		}
		BOOST_AUTO_TEST_CASE(tail)
		{
			CMyList<std::string>::CIterator it = list.begin() + (list.Size() - 1);
			list.Erase(it);
			BOOST_CHECK_EQUAL(*(list.begin() + (list.Size() - 1)), "2");
		}
	BOOST_AUTO_TEST_SUITE_END()

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
			size_t size = list.Size();
			list.Insert(it, "element next to head");
			BOOST_CHECK_EQUAL(list.Size(), size + 1);
			BOOST_CHECK_EQUAL(*(list.begin() + 1), "element next to head");
			BOOST_CHECK_EQUAL(*(++list.begin()), "element next to head");
			BOOST_CHECK_EQUAL(*(list.begin()), "1");
			BOOST_CHECK_EQUAL(*(list.begin() + 2), "2");
			BOOST_CHECK_EQUAL(*(list.begin() + 3), "3");
			BOOST_REQUIRE_THROW(*(list.begin() + 4), std::out_of_range);
		}

		BOOST_AUTO_TEST_CASE(beginning)
		{
			size_t size = list.Size();
			list.Insert(list.begin(), "0");
			BOOST_CHECK_EQUAL(list.Size(), size + 1);
			BOOST_CHECK_EQUAL(*list.begin(), "0");
			BOOST_CHECK_EQUAL(*(list.begin() + 1), "1");
		}

		BOOST_AUTO_TEST_CASE(last_iterator_pos)
		{
			size_t size = list.Size();
			list.Insert(list.begin() + (list.Size() - 1), "asd");
			BOOST_CHECK_EQUAL(list.Size(), size + 1);
			BOOST_CHECK_EQUAL(*(list.begin() + (list.Size() - 1)), "3");
			BOOST_CHECK_EQUAL(*(list.begin() + (list.Size() - 2)), "asd");
			BOOST_CHECK_EQUAL(*(list.begin() + (list.Size() - 3)), "2");
		}

	BOOST_AUTO_TEST_SUITE_END()
		
	
BOOST_AUTO_TEST_SUITE_END()




struct empty_integer_list_
	{
		CMyList<int> list;
	};


BOOST_FIXTURE_TEST_SUITE(empty_integer_list, empty_integer_list_)

	BOOST_AUTO_TEST_CASE(is_empty_after_creating)
	{
		BOOST_CHECK_EQUAL(list.Size(), 0);
		BOOST_CHECK(list.Empty());
	}

	BOOST_AUTO_TEST_SUITE(changes_size_after)

		BOOST_AUTO_TEST_CASE(push_back)
		{
			list.PushBack(111);
			BOOST_CHECK_EQUAL(list.Size(), 1);
			list.PushBack(222);
			BOOST_CHECK_EQUAL(list.Size(), 2);
			BOOST_CHECK(!list.Empty());
		}

		BOOST_AUTO_TEST_CASE(push_front)
		{
			list.PushFront(222);
			BOOST_CHECK_EQUAL(list.Size(), 1);
			list.PushFront(111);
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

		BOOST_AUTO_TEST_CASE(by_begin_iterator)
		{
			BOOST_REQUIRE_THROW(list.Erase(list.begin()), std::out_of_range);
		}

		BOOST_AUTO_TEST_SUITE_END()


		BOOST_AUTO_TEST_CASE(allows_changing_item_value_using_iterator)
		{
			list.PushBack(777);
			BOOST_CHECK_EQUAL(*list.begin(), 777);
			*list.begin() = 888;
			BOOST_CHECK_EQUAL(*list.begin(), 888); // проверка не пройдет
		}

BOOST_AUTO_TEST_SUITE_END()


struct filled_integer_list_ : public empty_integer_list_
{
	std::vector<int> values = { 1, 2, 3 };
	filled_integer_list_()
	{
		for (auto el : values)
		{
			list.PushBack(el);
		}
	}
};


BOOST_FIXTURE_TEST_SUITE(filled_integer_list, filled_integer_list_)

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




		BOOST_AUTO_TEST_CASE(can_loop_through_range_based_for)
		{
			size_t index = 0;
			for (auto str : list)
			{
				BOOST_CHECK(str == values[index]);
				++index;
			}
		}

		BOOST_AUTO_TEST_CASE(can_change_elements_by_using_iterator)
		{
			int newValue = 444;
			*list.begin() = 444;
			BOOST_CHECK_EQUAL(*list.begin(), newValue);
		}



		BOOST_AUTO_TEST_CASE(should_not_cause_stack_oveflow_on_destruction)
		{
			{
				CMyList<int> lst1;
				for (int i = 0; i < 100000; ++i)
				{
					lst1.PushBack(123);
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

			BOOST_AUTO_TEST_CASE(star_works_correctly)
			{
				auto it = list.begin();
				BOOST_CHECK_EQUAL(*it, values[0]);
			}

		BOOST_AUTO_TEST_SUITE_END()


		BOOST_AUTO_TEST_CASE(can_erase_element_at_iterator_pos)
		{
			CMyList<int>::CIterator it = ++list.begin();
			list.Erase(it);
			BOOST_CHECK_EQUAL(*++list.begin(), 3);

			list.Erase(list.begin());
			BOOST_CHECK_EQUAL(*list.begin(), 3);

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
				size_t size = list.Size();
				list.Insert(it, 245);
				BOOST_CHECK_EQUAL(list.Size(), size + 1);
				BOOST_CHECK_EQUAL(*(list.begin() + 1), 245);
				BOOST_CHECK_EQUAL(*(++list.begin()), 245);
				BOOST_CHECK_EQUAL(*(list.begin()), 1);
				BOOST_CHECK_EQUAL(*(list.begin() + 2), 2);
				BOOST_CHECK_EQUAL(*(list.begin() + 3), 3);
				BOOST_REQUIRE_THROW(*(list.begin() + 4), std::out_of_range);
			}

			BOOST_AUTO_TEST_CASE(beginning)
			{
				size_t size = list.Size();		
				list.Insert(list.begin(), 0);
				BOOST_CHECK_EQUAL(list.Size(), size + 1);
				BOOST_CHECK_EQUAL(*list.begin(), 0);
				BOOST_CHECK_EQUAL(*(list.begin() + 1), 1);
			}

			BOOST_AUTO_TEST_CASE(last_iterator_pos)
			{
				size_t size = list.Size();
				list.Insert(list.begin() + (list.Size() - 1), 245);
				BOOST_CHECK_EQUAL(list.Size(), size + 1); 
				BOOST_CHECK_EQUAL(*(list.begin() + (list.Size() - 1)), 3);
				BOOST_CHECK_EQUAL(*(list.begin() + (list.Size() - 2)), 245);
				BOOST_CHECK_EQUAL(*(list.begin() + (list.Size() - 3)), 2);
			}

	BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE_END()