
#pragma warning( disable : 4996 )
#include <string>
#include <fstream>
#include <map>
#include <math.h>
#include <vector>
#include <iostream>
#include <boost/algorithm/algorithm.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>


using namespace std;


vector<string> GetWords(string & line)
{
	vector<string> result;

	boost::split(result, line, boost::is_any_of("/"));
	
	return result;
}

void ReadDataFromFile(map<string, string> & dictionary)
{
	ifstream inputFile("Program_data.txt");
	if (!inputFile.is_open())
	{
		return;
	}
	string line;
	while (getline(inputFile, line))
	{
		if (!line.empty())
		{
			vector<string> result;
			boost::split(result, line, boost::is_any_of("/"));
			if (result.size() == 2)
			{
				dictionary[result[0]] = result[1];
			}
		}
	}
}

/*
void PrintWords(const vector<string> & translation)
{
	cout << '\n';
	for (size_t i = 0; i < translation.size(); ++i)
	{
		cout << translation[i];
		if (i != translation.size() - 1)
		{
			cout << " , ";
		}
	}
	cout << '\n';
}
*/

bool SaveDictionaryInFile(map<string, string> & dictionary)
{
	ofstream outputFile("Program_data.txt");
	
	for (std::map<string, string>::iterator it = dictionary.begin(); it != dictionary.end(); ++it)
	{
		outputFile << it->first << '/' << it->second;
	}
	if (!outputFile.flush())
	{
		cout << "Error closing outputFile" << endl;
		return false;
	}
	return true;
}

void main()
{
	map<string, string> oldDictionary;
	ReadDataFromFile(oldDictionary);
	map<string, string> dictionary = oldDictionary;

	bool isSomethingChanged = false;
	string searchingWord;
	cin >> searchingWord;
	while (searchingWord != "...")
	{
		if (dictionary.count(searchingWord) == 0)
		{
			cout << "Unknown word " << searchingWord << ". Input translation or <Enter> to cancel." << endl;
			string translation;
			cin >> translation;
			if (!translation.empty())
			{
				isSomethingChanged = true;
				cout << "\n<add_in_dict>\n";
				cout << "Word " << searchingWord << " saved as " << translation << endl;
				dictionary[searchingWord] = translation;
			}
		}
		else
		{
			cout << dictionary[searchingWord] << endl;
			cin >> searchingWord;
		}
		cin >> searchingWord;
	}

	if (isSomethingChanged)
	{
		cout << "Something has changed, do you want to save changes?(Y or y to save)" << endl;
		cin >> searchingWord;
		if (searchingWord == "Y" || searchingWord == "y")
		{
			if (SaveDictionaryInFile(dictionary))
			{
				cout << "Changes are saved in file Program_data.txt" << endl;
			}
		}
	}
}