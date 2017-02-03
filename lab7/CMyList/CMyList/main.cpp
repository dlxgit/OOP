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

	CMyList<int>::CIterator rend = lst.Rend();
	
	int step = -2;
	int last = *(rend + step);

	size_t index = 2;
	for (auto iter = lst.Rbegin(); iter != lst.Rend(); ++iter)
	{
		if (*iter == *(lst.begin() + index))
		{
			--index;
		}
		else
		{
			int b = 3;
		}
	}

	return;
}