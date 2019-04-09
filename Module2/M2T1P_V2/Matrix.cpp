#include "Matrix.h"
#include <vector>
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


Matrix::Matrix(int newSize)
{
	matrixSize = newSize;
	matrix.resize(matrixSize, vector<int>(matrixSize));
	matrix.clear();
}

Matrix::Matrix()
{
}

Matrix::~Matrix()
{
}

void Matrix::fillMatrix()
{
    srand (time (0));
	for (int i = 0; i < matrixSize; i++)
	{
		for (int j = 0; j < matrixSize; j++)
		{
			matrix[i][j] = rand() % 4;
		}
	}
}

int Matrix::getValue(int row, int column)
{
	return matrix[row][column];
}

void Matrix::setValue(int row, int column, int value)
{
	matrix[row][column] = value;
}

void Matrix::printMatrix()
{
	for (int i = 0; i < matrixSize; i++)
	{
		for (int j = 0; j < matrixSize; j++)
		{
			cout << setw(10) << matrix[i][j];
		}
		cout << endl;
	}
}