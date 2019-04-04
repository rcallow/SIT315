// M2T1P.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include "Matrix.h"

using namespace std;

const int N = 10;

int main()
{
    Matrix A = Matrix(N);
    Matrix B = Matrix(N);
    Matrix C = Matrix(N);

    //Start timing here


    for (int rowOfA = 0; rowOfA < N; ++rowOfA)
    {
        for (int columnOfB = 0; columnOfB < N; ++columnOfB)
        {
            int result = 0;
            for (int i = 0; i < N; ++i)
            {
                result = result + A.getValue(rowOfA, i) * B.getValue(i, columnOfB);		
            }
            C.setValue(rowOfA, columnOfB, result);	
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