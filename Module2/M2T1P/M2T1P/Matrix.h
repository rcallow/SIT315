#pragma once
#include <vector>
using namespace std;

class Matrix
{
public:
	int matrixSize = 0;
	vector<vector<int> > matrix;

	Matrix();
	Matrix(int);
	
	~Matrix();

	void fillMatrix();
	int getValue(int row, int column);
	void setValue(int row, int column, int value);
	void printMatrix();
};

