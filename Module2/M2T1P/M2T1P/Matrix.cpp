#include "pch.h"
#include "Matrix.h"
#include <vector>
#include <iomanip>

using namespace std;


class Matrix
{
private:
	int size = 0;
	

public:
	vector<vector<int>> matrix;
	Matrix();
	Matrix(int);
	~Matrix();
	void fillMatrix();
	vector<vector<int>> getMatrix();
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

vector<vector<int>> Matrix::getMatrix()
{
	return matrix;
}