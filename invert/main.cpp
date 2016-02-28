#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <sstream>
#include <iomanip>


struct Cofactor
{
	double matrix[2][2];
};

void PrintMatrix(const double(&matrix)[3][3])
{
	std::cout << "Inverted Matrix: " << std::endl;
	
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			std::cout << std::fixed << std::setprecision(3) << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

double ComputeDeterminant(double matrix[][3])
{
	return (
		matrix[0][0] * matrix[1][1] * matrix[2][2] +
		matrix[2][0] * matrix[0][1] * matrix[1][2] +
		matrix[1][0] * matrix[2][1] * matrix[0][2] -
		matrix[2][0] * matrix[1][1] * matrix[0][2] -
		matrix[0][0] * matrix[2][1] * matrix[1][2] -
		matrix[1][0] * matrix[0][1] * matrix[2][2]
		);
}

Cofactor ComputeCofactor(const double(&matrix)[3][3], const size_t & i, const size_t & j)
{
	Cofactor cofactor;
	size_t xPos = 0; //x and y - indexes of Cofactor (for filling)
	size_t yPos = 0;
	for (size_t p = 0; p < 3; p++)
	{
		xPos = 0;
		for (size_t q = 0; q < 3; q++)
		{
			if (p != i && q != j)
			{
				cofactor.matrix[yPos][xPos] = matrix[p][q];
				if (xPos == 1)
				{
					yPos = 1;
				}
				xPos = 1;
			}
		}
	}
	return cofactor;
}

double ComputeCellOfInvertedMatrix(const double(&matrix)[3][3], const double & det, const size_t & i, const size_t & j)  //value of [i][j] element of inverted matrix
{
	Cofactor cofactor = ComputeCofactor(matrix, i, j);
	double cofValue = (cofactor.matrix[0][0] * cofactor.matrix[1][1] - cofactor.matrix[0][1] * cofactor.matrix[1][0]);
	return pow(-1, i + j) * cofValue / det;
}

bool ComputeInvertedMatrix(const std::string & fileName)
{
	std::ifstream inputFile(fileName);
	if (!inputFile.is_open())
	{
		return false;
	}
	
	//reading matrix from inputFile and checking for incorrect dimension
	double matrix[3][3];
	std::string line;
	size_t lineCount = 0;
	while (std::getline(inputFile, line))
	{
		size_t numCount = 0;
		double number;
		std::istringstream iss(line);
		while (iss >> number && lineCount < 3)
		{
			matrix[lineCount][numCount] = number;
			if (++numCount > 3)
			{
				std::cout << "Error: incorrect number of elements in matrix" << std::endl;
				return false;
			}
		}
		if (numCount < 3)
		{
			std::cout << "Error: incorrect number of elements in matrix" << std::endl;
			return false;
		}
		lineCount++;
	}

	//in case of empty file
	if (lineCount == 0)
	{
		return false;
	}

	//computing Det
	double det = ComputeDeterminant(matrix);
	if (det == 0)
	{
		std::cout << "Impossible to calculate inverted matrix (det = 0)." << std::endl;
		return false;
	}
	
	//computing InvertedMatrix
	double invertedMatrix[3][3];
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			invertedMatrix[j][i] = ComputeCellOfInvertedMatrix(matrix, det, i, j);
		}
	}

	PrintMatrix(invertedMatrix);
	return true;
}

int main(int argc, char * argv[])
{
	if (argc != 2)
	{
		std::cout << "incorrect program execution.\nUsage: invert.exe <fileName>" << std::endl;
		return 1;
	}
	if (!ComputeInvertedMatrix(argv[1]))
	{
		return 1;
	}
	return 0;
}