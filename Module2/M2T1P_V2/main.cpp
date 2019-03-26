// M2T1P.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include "Matrix.h"

using namespace std;

const int N = 2;

int main()
{
	Matrix A = Matrix(N);
	Matrix B = Matrix(N);
	Matrix C = Matrix(N);

	//Start timing here


	for (int rowOfA = 0; rowOfA < N; rowOfA++)
	{
		for (int columnOfA = 0; columnOfA < N; columnOfA++)
		{
			for (int columnOfB = 0; columnOfB < N; columnOfB++)
			{
				for (int rowOfB = 0; rowOfB < N; rowOfB++)
				{
					int result = A.getValue(rowOfA, columnOfA) * B.getValue(rowOfB, columnOfB);
					C.setValue(rowOfA, columnOfB, result);
				}
			}
		}
	}

	cout << "Matrix A:" << endl << endl;
	A.printMatrix();
	cout << endl << endl << "Matrix B:" << endl << endl;
	B.printMatrix();
	cout << endl << endl << "Matrix C:" << endl << endl;
	C.printMatrix();
}
//Output time here
//Write output to file
//Format output into columns
//Add comments, error checking, exception handling