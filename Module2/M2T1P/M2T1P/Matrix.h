#pragma once
class Matrix
{
public:
	Matrix();
	Matrix(int);
	virtual ~Matrix();
	void fillMatrix();
	int getValue(int row, int column);
	void setValue(int row, int column, int value);
	void printMatrix();
};

