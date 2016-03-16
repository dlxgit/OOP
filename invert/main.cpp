#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <sstream>
#include <iomanip>
#include <array>


typedef std::array<std::array<double, 2>, 2> Matrix2x2; //for cofactor
typedef std::array<std::array<double, 3>, 3> Matrix3x3; //for rest matrixes

void PrintMatrix(const Matrix3x3 & matrix)
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

double ComputeDeterminant(const Matrix3x3 & matrix)
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

Matrix2x2 ComputeCofactor(const Matrix3x3 & matrix	, const size_t & i, const size_t & j)
{
	Matrix2x2 cofactor;
	size_t xPos = 0; //x and y - indexes of Cofactor (for filling)
	size_t yPos = 0;
	for (size_t p = 0; p < 3; p++)
	{
		xPos = 0;
		for (size_t q = 0; q < 3; q++)
		{
			if (p != i && q != j)
			{
				cofactor[yPos][xPos] = matrix[p][q];
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

double ComputeCellOfInvertedMatrix(const Matrix3x3 & matrix, const double & det, const size_t & i, const size_t & j)  //value of [i][j] element of inverted matrix
{
	Matrix2x2 cofactor = ComputeCofactor(matrix, i, j);
	double cofValue = (cofactor[0][0] * cofactor[1][1] - cofactor[0][1] * cofactor[1][0]);
	return pow(-1, i + j) * cofValue / det;
}

Matrix3x3 ReadMatrixFromFile(const std::string & fileName, bool & isError)
{
	Matrix3x3 matrix = Matrix3x3();

	//reading matrix from inputFile and checking for incorrect dimension
	std::ifstream inputFile(fileName);
	if (!inputFile.is_open())
	{
		isError = true;
		return matrix;
	}

	std::string line;
	size_t lineCount = 0;
	while (std::getline(inputFile, line))
	{
		size_t numCount = 0;
		double number;
		std::istringstream iss(line);
		while (lineCount < 3 && numCount < 3 && iss >> number)
		{
			matrix[lineCount][numCount] = number;
			numCount++;
		}
		if (numCount != 3)
		{
			std::cout << "Error: incorrect number of elements in matrix" << std::endl;
			isError = true;
			return matrix;
		}
		lineCount++;
	}

	if (lineCount != 3)
	{
		isError = true;
		return matrix;
	}

	return matrix;
}

Matrix3x3 ComputeInvertedMatrix(const std::string & fileName, bool & wasError)
{
	bool isError = false;

	//ReadMatrix
	Matrix3x3 matrix = ReadMatrixFromFile(fileName, isError);
	if (isError)
	{
		wasError = true;
		return matrix;
	}

	//computing Det
	double det = ComputeDeterminant(matrix);
	if (det == 0)
	{
		std::cout << "Impossible to calculate inverted matrix (det = 0)." << std::endl;
		wasError = true;
		return matrix;
	}
	
	//computing InvertedMatrix
	Matrix3x3 invertedMatrix;
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			invertedMatrix[j][i] = ComputeCellOfInvertedMatrix(matrix, det, i, j);
		}
	}
	return invertedMatrix;
}


bool WriteMatrixInFile(const Matrix3x3 & matrix)
{
	std::ofstream outputFile("output.txt");
	if (!outputFile.is_open())
	{
		return false;
	}

	for (size_t i = 0; i < matrix.size(); i++)
	{		
		for (size_t j = 0; j < matrix[i].size(); j++)
		{
			outputFile << std::fixed << std::setprecision(3) << matrix[i][j];
			if (j < 2)
			{
				outputFile << " ";
			}
		}
		if (i < 2)
		{
			outputFile << '\n';
		}
	}

	if (!outputFile.flush())
	{
		std::cout << "Failed to write in output file";
		return false;
	}

	return true;
}


int main(int argc, char * argv[])
{
	if (argc != 2)
	{
		std::cout << "incorrect program execution.\nUsage: invert.exe <fileName>" << std::endl;
		return 1;
	}
	
	bool isError = false;
	Matrix3x3 resultMatrix = ComputeInvertedMatrix(argv[1], isError);
	if(isError)
	{
		return 1;
	}
	PrintMatrix(resultMatrix);
	WriteMatrixInFile(resultMatrix);
	return 0;
}