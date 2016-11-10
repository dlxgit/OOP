#include "CStringList.h"
#include <vector>

void main()
{
	CStringList list;
	list.push_front("3");
	list.push_front("2");
	list.push_front("1");
	size_t i = list.size();
	list.insert(list.begin() + (list.size() - 1), "asd");
}