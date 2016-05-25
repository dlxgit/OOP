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

Matrix2x2 ComputeCofactor(const Matrix3x3 & matrix, unsigned  i, unsigned j)
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

double ComputeCellOfInvertedMatrix(const Matrix3x3 & matrix, const double & det, unsigned i, unsigned j)  //value of [i][j] element of inverted matrix
{
	Matrix2x2 cofactor = ComputeCofactor(matrix, i, j);
	double cofactorDeterminant = (cofactor[0][0] * cofactor[1][1] - cofactor[0][1] * cofactor[1][0]);

	return ((i + j) % 2 == 0) ? (cofactorDeterminant / det) : (-cofactorDeterminant / det);
}

Matrix3x3 ReadMatrixFromFile(const std::string & fileName)
{
	Matrix3x3 matrix = Matrix3x3();

	//reading matrix from inputFile and checking for incorrect dimension
	std::ifstream inputFile(fileName);
	if (!inputFile.is_open())
	{
		throw std::ios_base::failure("Could not open inputFile");
	}
	
	std::string line;
	size_t lineCount = 0;
	while (std::getline(inputFile, line))
	{
		size_t numCount = 0;
		double number;
		std::istringstream iss(line);
		while (lineCount < 3 && numCount < 4 && iss >> number)
		{
			if (numCount < 3)
			{
				matrix[lineCount][numCount] = number;
			}
			numCount++;
		}
		if (numCount != 3)
		{
			throw std::invalid_argument("Incorrect matrix dimension");
		}
		lineCount++;
	}

	if (lineCount != 3)
	{
		throw std::invalid_argument("Incorrect matrix dimension");
	}
	return matrix;
}

Matrix3x3 ComputeInvertedMatrix(const Matrix3x3 & sourceMatrix)
{
	double det = ComputeDeterminant(sourceMatrix);
	if (det == 0)
	{
		throw std::invalid_argument("Det = 0");
	}
	Matrix3x3 invertedMatrix;
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			invertedMatrix[j][i] = ComputeCellOfInvertedMatrix(sourceMatrix, det, i, j);
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

	try
	{
		Matrix3x3 sourceMatrix = ReadMatrixFromFile(argv[1]);
		Matrix3x3 resultMatrix = ComputeInvertedMatrix(sourceMatrix);

		PrintMatrix(resultMatrix);
		WriteMatrixInFile(resultMatrix);
	}
	catch (const std::ios_base::failure & error) 
	{
		std::cout << error.what() << std::endl;
	}
	catch (const std::invalid_argument & error)
	{
		std::cout << error.what() << std::endl;
		if (strcmp(error.what(), "Det = 0") == 0)
		{
			return 2;
		}
		return 3;
	}
	return 0;
}
