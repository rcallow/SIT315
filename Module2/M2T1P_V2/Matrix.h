#pragma once
#include <vector>
using namespace std;

#ifndef MATRIX_H
#define MATRIX_H

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

#endif /* MATRIX_H */

