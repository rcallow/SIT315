#include "pch.h"
#include "Matrix.h"
#include <iomanip>


class Matrix
{
private:
	int size = 0;
	int** matrix = 0;

public:
	Matrix();
	Matrix(int);
	~Matrix();
	void fillMatrix();
};


Matrix::Matrix(int matrixSize)
{
	size = matrixSize;
	matrix = new int*[matrixSize];
	for (int i = 0; i < matrixSize; i++)
		matrix[i] = new int[matrixSize];
}

Matrix::Matrix()
{
}

Matrix::~Matrix()
{
}

void Matrix::fillMatrix()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			matrix[i][j] = rand() % 100;
		}
	}
}