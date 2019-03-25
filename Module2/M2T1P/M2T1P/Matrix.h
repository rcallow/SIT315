#pragma once
class Matrix
{
public:
	Matrix();
	Matrix(int);
	virtual ~Matrix();
	void fillMatrix();
	vector<vector<int>> getMatrix();
	int getValue(int row, int column);
};

