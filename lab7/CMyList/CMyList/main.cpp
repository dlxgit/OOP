#include "CMyList.h"
//"$(TargetPath)" --log_level=test_suite


// 			bool prev = std::addressof(this->m_node->prev) == std::addressof(other.m_node->prev);
// 			bool next = this->m_node->next == other.m_node->next;
// 			bool bol = this->m_isReverse == other.m_isReverse;

void main()
{
	CMyList<int> lst;
	lst.PushBack(1);
	lst.PushBack(2);
	lst.PushBack(3);



	auto iter = lst.end();
	auto iterlast = --lst.end();
	auto iter2 = ++iterlast;
	for (auto el = lst.begin(); el != lst.end(); ++el)
	{
		int a = 3;
	}


	CMyList<int>::CIterator rend = lst.Rend();
	
	int step = -2;
	int last = *(rend + step);


	auto itr = --lst.Cend();
	auto itr2 = lst.Cend() + (-1);
	size_t index = 0;
	for (auto iter = lst.Cbegin(); iter != lst.Cend(); ++iter)
	{
		if (*iter == *(lst.Cbegin() + index))
		{
			++index;
		}
		else
		{
			int b = 3;
		}
	}

	return;
}