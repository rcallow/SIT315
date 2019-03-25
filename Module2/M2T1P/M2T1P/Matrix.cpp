#include "pch.h"
#include "Matrix.h"
#include <vector>
#include <iomanip>
#include <iostream>

using namespace std;


//class Matrix
//{
//public:
//	Matrix();
//	Matrix(int);
//	~Matrix();
//	void fillMatrix();
//	int getValue(int row, int column);
//	void setValue(int row, int column, int value);
//	void printMatrix();
//	int size = 0;
//	vector<vector<int>> matrix;
//};
int matrixSize = 0;
vector<vector<int>> matrix;


Matrix::Matrix(int newSize)
{
	matrixSize = newSize;
	matrix.resize(matrixSize, vector<int>(matrixSize));
	fillMatrix();
}

Matrix::Matrix()
{
}

Matrix::~Matrix()
{
}

void Matrix::fillMatrix()
{
	for (int i = 0; i < matrixSize; i++)
	{
		for (int j = 0; j < matrixSize; j++)
		{
			matrix[i].push_back(rand() % 100);
			//matrix[0][0] = rand() % 100;
		}
	}
}

int Matrix::getValue(int row, int column)
{
	return matrix[row][column];
}

void Matrix::setValue(int row, int column, int value)
{
	//matrix.insert()
	matrix[row][column] = value;
}

void Matrix::printMatrix()
{
	for (int i = 0; i < matrixSize; i++)
	{
		for (int j = 0; j < matrixSize; j++)
		{
			cout << matrix[i][j];
		}
		cout << endl;
	}
}