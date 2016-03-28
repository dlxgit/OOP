
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

//TODO: mb do without vector, just with map

vector<string> GetWords(string & line)
{
	vector<string> result;

	boost::split(result, line, boost::is_any_of("/"));
	
	return result;
}

void ReadDataFromFile(map<string, vector<string>> & dictionary)
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
			if (result.size() > 1)
			{
				for (size_t i = 1; i < result.size(); i++)
				{
					dictionary[result[0]].push_back(result[i]);
				}
			}
		}
	}
}

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

void SaveDictionaryInFile(map<string, vector<string>> & dictionary)
{
	ofstream outputFile("Program_data.txt");
	
	for (std::map<string, vector<string>>::iterator it = dictionary.begin(); it != dictionary.end(); ++it)
	{
		outputFile << it->first << '/';
		for (string & val : it->second)
		{
			outputFile << val << '/';
		}
	}
}

void main()
{
	map<string, vector<string>> oldDictionary;
	ReadDataFromFile(oldDictionary);
	map<string, vector<string>> dictionary = oldDictionary;

	bool isSomethingChanged = false;
	string searchingWord;
	cin >> searchingWord;
	while (searchingWord != "...")
	{
		cout << "\n<start>\n";
		if (dictionary.count(searchingWord) == 0)
		{
			cout << "Unknown word " << searchingWord << ". ¬ведите перевод или пустую строку дл€ отказа." << endl;
			string translation;
			cin >> translation;
			if (translation.empty() == true)
			{
				cout << "\n<empty_str -> ignore_word>\n";
				continue;
			}
			else
			{
				isSomethingChanged = true;
				cout << "\n<add_in_dict>\n";
				cout << "Word " << searchingWord << " saved as " << translation << endl;
				dictionary[searchingWord].push_back(translation);
			}
		}
		else
		{
			cout << "\n<print_existing_translate: >\n";
			PrintWords(dictionary[searchingWord]);
			cin >> searchingWord;
		}
		cin >> searchingWord;
	}

	if (isSomethingChanged)
	{
		cout << "\nSomething has changed, save changes?(y/n)\n";
		cin >> searchingWord;
		if (searchingWord == "Y" || searchingWord == "y")
		{
			SaveDictionaryInFile(dictionary);
		}
	}
}