#include <iostream>
#include <fstream>
#include <string>


std::string ReplaceSubstring(const std::string & line,const std::string & searchString, const std::string & replaceString)
{
	std::string newString = "";

	size_t nextEntryIndex = 0;
	size_t prevEntryIndex = 0;

	size_t searchStringSize = searchString.size();
	size_t replaceStringSize = replaceString.size();

	while ((nextEntryIndex = line.find(searchString, nextEntryIndex)) != std::string::npos)
	{
		newString.append(line, prevEntryIndex, nextEntryIndex - prevEntryIndex); //add substring between prevEntry and nextEntry to new string
		newString.append(replaceString);

		nextEntryIndex += searchStringSize;
		prevEntryIndex = nextEntryIndex;
	}

	newString.append(line,prevEntryIndex);
	return newString;
}

bool SearchAndReplaceSubstring(const std::string & inputFileName, const std::string & outputFileName, const std::string & searchString, const std::string & replaceString)
{
	std::ifstream inputFile(inputFileName);
	if (!inputFile.is_open())
	{
		std::cout << "inputFile name is incorrect" << std::endl;
		return false;
	}

	std::ofstream outputFile(outputFileName);
	if (!outputFile.is_open())
	{
		std::cout << "Error: could not open outputFile" << std::endl;
		return false;
	}

	std::string line;
	bool isFirstLine = true;

	while (std::getline(inputFile, line))
	{
		if (!isFirstLine)
		{
			outputFile << '\n';  //write new line every time, except if it's first line in file
		}
		else isFirstLine = false;

		if (searchString.empty()) //if search substring is empty, just rewrite it in outputFile
		{
			outputFile << line;
		}
		else //replace subString
		{
			std::string newString = ReplaceSubstring(line, searchString, replaceString);
			outputFile << newString;
		}
	}

	if (!outputFile.flush())
		std::cout << "Failed to write in output file";
	return true;
}

int main(int argc, char * argv[])
{
	if (argc != 5)
	{
		std::cout << "incorrect program execution.\nExample: replace.exe <inputFile> <outputFile> <searchString> <replaceString>" << std::endl;
		return 1;
	}

	if (!SearchAndReplaceSubstring(argv[1], argv[2], argv[3], argv[4]))
	{
		return 1;
	}
	return 0;
}