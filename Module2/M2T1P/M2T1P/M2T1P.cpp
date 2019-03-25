// M2T1P.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <iomanip>
#include "Matrix.h"

using namespace std;

const int N = 10;

int main()
{
	Matrix *A = new Matrix(N);
	Matrix *B = new Matrix(N);
	Matrix *C = new Matrix(N);
	//Start timing here


	for (int rowOfA = 0; rowOfA < N; rowOfA++)
	{
		for (int columnOfA = 0; columnOfA < N; columnOfA++)
		{
			for (int columnOfB = 0; columnOfB < N; columnOfB++)
			{
				for (int rowOfB = 0; rowOfB < N; rowOfB++)
				{
					int result = (*A).getValue(rowOfA, columnOfA) * (*B).getValue(rowOfB, columnOfB);
					(*C).setValue(rowOfA, columnOfB, result);
				}
			}
		}
	}

	cout << "Matrix A:" << endl << endl;
	(*A).printMatrix();
	cout << endl << endl << "Matrix B:" << endl << endl;
	(*B).printMatrix();
	cout << endl << endl << "Matrix C:" << endl << endl;
	(*C).printMatrix();


//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			cout << C[i][j];
//		}
//		cout << endl;
//	}

}
//For each value in row i of A, multiply by each value in column j of B, sum the results per column/row pair
//First row in A, combined with column 1, 2, 3, etc in B makes the values for the first row of C. Second row makes second row of C, etc
//Output time here
//Write output to file

//Write function to initialize arrays
//Add comments, error checking, exception handling