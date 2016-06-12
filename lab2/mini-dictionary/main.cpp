#include "Dictionary.h"
#include <clocale>

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	Dictionary oldDictionary = ReadDataFromFile();
	Dictionary dictionary = oldDictionary;
	ProcessInputData(dictionary);
	return 0;
}