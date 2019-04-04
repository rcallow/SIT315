// M2T1P.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include "Matrix.h"
#include "time.h"
#include <stdio.h>
#include <pthread.h>

using namespace std;

const int N = 470;
const int NUMBER_OF_THREADS = 2;
int rowsPerThread = 0;
Matrix A;
Matrix B;
Matrix C;


void *MultiplyPartMatrices(void *id)
{
    int threadId = (int)id;
    for (int rowOfA = rowsPerThread * threadId; rowOfA < (rowsPerThread * threadId + rowsPerThread); ++rowOfA)
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
   pthread_exit(NULL);
}



int main()
{
    pthread_t threads[NUMBER_OF_THREADS];
    A = Matrix(N);
    B = Matrix(N);
    C = Matrix(N);
    
    int remainder = 0;
    double time_elapsed = 0.0;

    //Start timing here
    //measuring time -- using clock
    long clock_start = clock();

    remainder = N % NUMBER_OF_THREADS;
    N -= remainder;
    rowsPerThread = N / NUMBER_OF_THREADS;
    
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
    
    long clock_end = clock();
    time_elapsed = (clock_end - clock_start) / CLOCKS_PER_SEC;

    printf("Time elapsed: %.2f\n", time_elapsed);
//    cout << "Matrix A:" << endl << endl;
//    A.printMatrix();
//    cout << endl << endl << "Matrix B:" << endl << endl;
//    B.printMatrix();
//    cout << endl << endl << "Matrix C:" << endl << endl;
//    C.printMatrix();

}