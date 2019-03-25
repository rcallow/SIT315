#include "pch.h"
#include "Matrix.h"


class Matrix
{
private:
	int** matrix = 0;

public:
	Matrix();
	Matrix(int);
	~Matrix();
};


Matrix::Matrix(int matrixSize)
{
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
