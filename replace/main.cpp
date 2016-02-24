#include <iostream>
#include <fstream>
#include <string>

const std::streamoff FILE_MAX_SIZE = 2147483648;

bool IsFileNameCorrect(const std::ifstream & inputFile)
{
	if (inputFile.is_open())
	{
		return true;
	}
	std::cout << "inputFile name is incorrect" << std::endl;
	return false;
}

bool IsFileSizeCorrect(std::ifstream & inputFile)
{
	inputFile.seekg(0, std::ios::end);
	std::streamoff fileSize = inputFile.tellg();

	if (FILE_MAX_SIZE < fileSize)
	{
		std::cout << "inputFile size is more than 2GB" << std::endl;
		return false;
	}

	inputFile.clear();
	inputFile.seekg(0, std::ios_base::beg);
	return true;
}

void SearchAndReplaceSubstring(std::ifstream & inputFile, std::ofstream & outputFile, const std::string & searchString, const std::string & replaceString)
{
	size_t searchStringSize = searchString.size();
	size_t replaceStringSize = replaceString.size();
	std::string line;
	bool isFirstLine = true;
	while (std::getline(inputFile, line))
	{
		if (!isFirstLine)
		{
			outputFile << '\n';  //write new line if not first entry into loop
		}
		else isFirstLine = false;

		if (searchString != "")  //if search substring is not empty, try to find it in string
		{
			size_t nextEntryIndex = 0;
			while ((nextEntryIndex = line.find(searchString, nextEntryIndex)) != std::string::npos)
			{
				line.replace(nextEntryIndex, searchStringSize, replaceString);
				nextEntryIndex += replaceStringSize;
			}
		}
		outputFile << line;
	}

	inputFile.close();
	if (!outputFile.flush())
		std::cout << "Failed to write in output file";
}

int main(int argc, char *argv[])
{
	if (argc != 5)
	{
		std::cout << "incorrect program execution.\nExample: replace.exe <inputFile> <outputFile> <searchString> <replaceString>" << std::endl;
		return 1;
	}

	std::ifstream inputFile;
	std::ofstream outputFile;
	inputFile.open(argv[1]);

	if (!(IsFileNameCorrect(inputFile) && IsFileSizeCorrect(inputFile)))
	{
		return 1;
	}

	outputFile.open(argv[2]);
	SearchAndReplaceSubstring(inputFile, outputFile, argv[3], argv[4]);
	return 0;
}