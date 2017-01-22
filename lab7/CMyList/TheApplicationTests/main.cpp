#include "CMyList.h"


void main()
{
	CMyList<int> lst;
	lst.PushBack(1);
	lst.PushBack(2);

	CMyList<int> lst2(lst);

	int a = 3;
}