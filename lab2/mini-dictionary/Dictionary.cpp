#pragma once
#include "stdafx.h"
#include "Dictionary.h"

std::vector<std::string> PartLineBySymbol(const std::string & line, const std::string & delimeter)
{
	std::vector<std::string> result;
	boost::split(result, line, boost::is_any_of(delimeter));
	return result;
}

Dictionary ReadDataFromFile(const std::string & inputFileName)
{
	Dictionary dictionary;
	std::ifstream inputFile(inputFileName);
	if (!inputFile.is_open())
	{
		return dictionary;
	}
	std::string line;
	while (std::getline(inputFile, line))
	{
		if (!line.empty())
		{
			std::vector<std::string> result;
			boost::split(result, line, boost::is_any_of("/"));
			if (result.size() > 1)
			{
				for (size_t i = 1; i < result.size(); ++i)
				{
					if (!result[i].empty())
					{
						dictionary.insert(std::pair<std::string, std::string>(result[0], result[i]));
					}
				}
			}
		}
	}
	return dictionary;
}

void SaveDictionaryInFile(const Dictionary & dictionary)
{
	std::ofstream outputFile("Program_data.txt");
	for (std::pair<std::string, std::string> element : dictionary)
	{
		std::cout << element.first;
		outputFile << element.first << '/' << element.second << std::endl;
	}
	if (outputFile.flush())
	{
		std::cout << "Changes are saved in file Program_data.txt" << std::endl;
	}
	else
	{
		std::cout << "Error saving changes in file" << std::endl;
	}
}

void AskUserToSaveChanges(Dictionary & dictionary)
{
	std::cout << "Something has changed, do you want to save changes?(Y or y to save)" << std::endl;
	std::string userInput;
	std::cin >> userInput;
	if (userInput == "Y" || userInput == "y") 
	{
		SaveDictionaryInFile(dictionary);
	}
}

std::string GetTranslation(const Dictionary & dict, const std::string & key)
{
	std::string result;
	auto range = dict.equal_range(key);
	for (auto it = range.first; it != range.second; ++it)
	{
		result += it->second + " ";
	}
	return result;
}

bool HasWord(const Dictionary & dict, const std::string & word)
{
	return 0 != dict.count(word);
}

void AddElement(Dictionary & dictonary, const std::pair<std::string, std::string> & elem)
{
	dictonary.insert(elem);
}

void ProcessInputData(Dictionary & dictionary)
{
	bool isDictionaryModified = false;
	std::string searchingWord;
	std::getline(std::cin, searchingWord);
	while (searchingWord != std::string("..."))
	{
		if (HasWord(dictionary, searchingWord))
		{
			std::cout << GetTranslation(dictionary, searchingWord) << std::endl;		
		}
		else  //if there is no such word in dictionary
		{
			std::cout << "Unknown word " << searchingWord << ". Input translation, or <Enter> to cancel." << std::endl;
			std::string translation;
			std::getline(std::cin, translation);
			if (!translation.empty()) //insert new Element
			{
				isDictionaryModified = true;
				std::cout << "Word " << searchingWord << " saved as " << translation << std::endl;
				AddElement(dictionary, { searchingWord, translation });
			}
		}
		std::getline(std::cin, searchingWord);
	}
	if (isDictionaryModified)
	{
		AskUserToSaveChanges(dictionary);
	}
}