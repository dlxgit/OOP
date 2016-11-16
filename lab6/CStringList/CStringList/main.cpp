#include "CStringList.h"
#include <vector>



void main()
{
	CStringList list;
	/*list.push_back("first_elem");
	if (list.size() == 1)
	{
		list.push_back("second_elem");
		if (list.size() == 2)
		{
			size_t i = list.size();
			list.insert(list.begin() + (list.size() - 1), "asd");
		}
	}
	*/

	
	list.Push_back("1");
	list.Push_back("2");
	list.Push_back("3");
	
	std::vector<std::string> values = { "1", "2", "3" };

	{
		CStringList list2;
		list2.Push_back("1");
		//CStringList::CIterator it2 = list2.begin();
	}

	size_t index = 0;
	auto iter = list.begin();
	for (; iter != list.end(); iter++)
	{
		*iter == values[index];
		++index;
	}

	std::vector<std::string>::iterator iterBad = values.begin() + 3;

	CStringList::CConstIterator it = list.Cbegin();
}