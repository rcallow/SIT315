// M2T1P.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include "Matrix.h"
#include <time.h>
#include <stdio.h>
#include <pthread.h>
#include <vector>


using namespace std;

const int NUMBER_OF_THREADS = 2;

int N = 10;
int rowsPerThread = 0;
const int MATRIX_SIZE_TWO_D = 5;
vector<int> vectorA(pow(MATRIX_SIZE_TWO_D, 2));
vector<int> vectorB(pow(MATRIX_SIZE_TWO_D, 2));
vector<int> vectorC(pow(MATRIX_SIZE_TWO_D, 2));
const int ROWSPERTHREAD = int(MATRIX_SIZE_TWO_D/NUMBER_OF_THREADS);



void *MultiplyPartMatrices(void *id)
{
    int threadId = (long)id;
   
    if(threadId == NUMBER_OF_THREADS - 1)
    {
            for (int rowOfA = ROWSPERTHREAD * threadId; rowOfA < (ROWSPERTHREAD * threadId + ROWSPERTHREAD + extraRows); ++rowOfA)
    {
        for (int columnOfB = 0; columnOfB < MATRIX_SIZE_TWO_D; ++columnOfB)
        {
            int result = 0;
            for (int i = 0; i < MATRIX_SIZE_TWO_D; ++i)
            {
                result = result + twoDConvertGet(rowOfA, i, vectorA) * twoDConvertGet(i, columnOfB, vectorB);
            }
            pthread_mutex_lock(&writeMutex);
            vectorC[MATRIX_SIZE_TWO_D * rowOfA + columnOfB] = result;
            pthread_mutex_unlock(&writeMutex);
           
    }
    }
    }
}



int main()
{
    pthread_t threads[NUMBER_OF_THREADS];
    A = Matrix(N);
    B = Matrix(N);
    
    int remainder = 0;
    double time_elapsed = 0.0;

    //Start timing here
    //measuring time -- using clock
    long clock_start = clock();

    remainder = N % NUMBER_OF_THREADS;
    N -= remainder;
    rowsPerThread = N / NUMBER_OF_THREADS;
    
    for (long int i = 0; i < NUMBER_OF_THREADS; ++i)
    {
        int errorCheck = pthread_create(&threads[i], NULL, MultiplyPartMatrices, (void*)i);
         if (errorCheck != 0)
        {
            cout << "Thread creation failed. Error code: " << errorCheck << endl;
        }
    }
    
    for (long int i = 0; i < NUMBER_OF_THREADS; ++i)
    {
        int errorCheck = pthread_join (threads[i], NULL);
                 if (errorCheck != 0)
        {
            cout << "Thread join failed. Error code: " << errorCheck << endl;
        }
    }
    
    long clock_end = clock();
    time_elapsed = (clock_end - clock_start) / CLOCKS_PER_SEC;

    printf("Time elapsed: %.2f\n", time_elapsed);
    cout << "Matrix A:" << endl << endl;
    A.printMatrix();
//    cout << endl << endl << "Matrix B:" << endl << endl;
//    B.printMatrix();
//    cout << endl << endl << "Matrix C:" << endl << endl;
//    C.printMatrix();

}