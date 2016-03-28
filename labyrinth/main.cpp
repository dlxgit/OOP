#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>
#include <set>

using namespace std;

struct Vector2
{
	size_t x;
	size_t y;
};

bool IsFileNameCorrect(const std::ifstream & inputFile)
{
	if (inputFile.is_open())
	{
		return true;
	}
	std::cout << "inputFile name is incorrect" << std::endl;
	return false;
}

vector<string> ReadFieldFromFile(const string & inputFileName)
{
	vector<string> field;

	ifstream inputFile(inputFileName);
	std::string line;
	while (std::getline(inputFile, line))
	{
		field.push_back(line);
	}


	return field;
}

bool IsLabyrinthCorrect(const vector<string> & field) //checks if labyrinth has not only one begin/end
{
	bool isLabBegin = false;
	bool isLabEnd = false;

	for (string line : field)
	{
		for (size_t i = 0; i < line.size(); i++)
		{
			if (line[i] == 'A')
			{
				if (isLabBegin == true)
				{
					return {};
				}
				isLabBegin = true;
			}
			if (line[i] == 'B')
			{
				if (isLabEnd == true)
				{
					return {};
				}
				isLabEnd = true;
			}
		}
	}
	if (isLabBegin == false || isLabEnd == false)
	{
		return false;
	}
	return true;
}

Vector2 GetLetterPosition(const vector<string> & field, const char & letter)  //get x-y index of searching symbol(for defining begin/end)
{
	for (size_t i = 0; i < field.size(); i++)
	{
		for (size_t j = 0; j < field.size(); j++)
		{
			if (field[i][j] == letter)
			{
				return{j,i};
			}
		}
	}
}

//////////////////////////////////////////////////////////////

vector<Vector2> GetAdjacentCells(const vector<string> & field, vector<Vector2> adjacent, )
{
	vector<Vector2> adjacent;
	
	for (size_t i = 0; i < field.size(); i++)
	{
		for (size_t j = 0; j < field.size(); j++)
		{
			if ((abs(int(i) - int(j)) < 1) && abs(int(i) - int(j)) < 1)
			{
				return { j,i };
			}
		}
	}

	return adjacent;
}

//void IterateNextWave(vector<string> & field, vector<Vector2> adjacent, const size_t & distance, const Vector2 & beginPos, const Vector2 & endPos)
{
	

}

void IterateNextWave(const vector<string> & field, vector<Vector2> adjacent, vector<vector<int>> & distance, const size_t & distance, const Vector2 & endPos)
{
	adjacent = GetAdjacentCells();


}

bool ComputeWay(const string & inputFileName)
{
	vector<string> field = ReadFieldFromFile(inputFileName);

	if (field.size() == 0)
	{
		return false;
	}
	if (!IsLabyrinthCorrect(field))
	{
		return false;
	}
	
	Vector2 beginPos = GetLetterPosition(field, 'A');
	Vector2 endPos = GetLetterPosition(field, 'B');
	
	vector<bool> visited = 


	return true;
}

int main(int argc, char *argv[])
{
	argc = 3;
	argv[1] = "input.txt";
	argv[2] = "output.txt";

	if (argc != 3)
	{
		std::cout << "incorrect program execution.\nUsage: labyrinth.exe <inputFile> <outputFile>" << std::endl;
		return 1;
	}



	if (!ComputeWay(argv[1]))
	{
		return 1;
	}
	return 0;

}