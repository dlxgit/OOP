#include "Dictionary.h"
#include <clocale>

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	
	Dictionary dictionary = ReadDataFromFile();
	ProcessInputData(dictionary);
	return 0;
}