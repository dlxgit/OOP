#include "CMyList.h"


//"$(TargetPath)" --log_level=test_suite

void main()
{
	CMyList<int> lst;
	lst.PushBack(1);
	lst.PushBack(2);
	CMyList<int>::CIterator end = lst.end();
	
	
	return;
}