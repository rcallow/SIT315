#include "pch.h"
#include "Matrix.h"
#include <vector>
#include <iomanip>

using namespace std;


class Matrix
{
private:
	int size = 0;
	vector<vector<int>> matrix;
	

public:
	Matrix();
	Matrix(int);
	~Matrix();
	void fillMatrix();
	int getValue(int row, int column);
};


Matrix::Matrix(int matrixSize)
{
	size = matrixSize;
	matrix.resize(size, vector<int>(size));
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

int Matrix::getValue(int row, int column)
{
	return matrix[row][column];
}