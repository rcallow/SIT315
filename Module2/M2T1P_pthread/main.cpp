// M2T1P.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include "Matrix.h"
#include "time.h"
#include <stdio.h>
#include <pthread.h>

using namespace std;

const int NUMBER_OF_THREADS = 2;

int N = 2;
int rowsPerThread = 0;
Matrix A = Matrix(N);
Matrix B = Matrix(N);
Matrix C = Matrix(N);
pthread_mutex_t threadMutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t coutMutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t matrixWriteMutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t testMutex = PTHREAD_MUTEX_INITIALIZER;


void *MultiplyPartMatrices(void *id)
{
    int threadId = (long)id;
    for (int rowOfA = rowsPerThread * threadId; rowOfA < (rowsPerThread * threadId + rowsPerThread); ++rowOfA)
    {
        for (int columnOfB = 0; columnOfB < N; ++columnOfB)
        {
            int result = 0;
            for (int i = 0; i < N; ++i)
            {
                pthread_mutex_lock(&testMutex);
                cout << "thread ID: " << threadId << endl;
                cout << "row of a: " << rowOfA << "column of b: " << columnOfB << "result: " << result << endl;
                result = result + A.getValue(rowOfA, i) * B.getValue(i, columnOfB);
                pthread_mutex_unlock(&testMutex);
            }
            pthread_mutex_lock(&threadMutex);
            C.setValue(rowOfA, columnOfB, result);	
            pthread_mutex_unlock(&threadMutex);
            
	}
    }
    pthread_mutex_lock(&coutMutex);
    cout << "thread finished: " << threadId << endl << endl;
    pthread_mutex_unlock(&coutMutex);
   pthread_exit(NULL);
}



int main()
{
    pthread_t threads[NUMBER_OF_THREADS];
    
    int remainder = 0;
    double time_elapsed = 0.0;
    pthread_mutex_lock(&matrixWriteMutex);
    A.fillMatrix();
    B.fillMatrix();
    pthread_mutex_unlock(&matrixWriteMutex);

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
             pthread_mutex_lock(&coutMutex);
            cout << "Thread creation failed. Error code: " << errorCheck << endl;
            pthread_mutex_unlock(&coutMutex);
        }
    }
    
    for (long int i = 0; i < NUMBER_OF_THREADS; ++i)
    {
        int errorCheck = pthread_join (threads[i], NULL);
                 if (errorCheck != 0)
        {
                     pthread_mutex_lock(&coutMutex);
            cout << "Thread join failed. Error code: " << errorCheck << endl;
            pthread_mutex_unlock(&coutMutex);
        }
    }
    
    long clock_end = clock();
    time_elapsed = (clock_end - clock_start) / CLOCKS_PER_SEC;

    printf("Time elapsed: %.2f\n", time_elapsed);
    cout << "Matrix A:" << endl << endl;
    A.printMatrix();
    
    cout << endl << endl << "Matrix B:" << endl << endl;
    B.printMatrix();
    cout << endl << endl << "Matrix C:" << endl << endl;
    C.printMatrix();
    
    pthread_mutex_destroy(&threadMutex);
    pthread_mutex_destroy(&coutMutex);
    pthread_mutex_destroy(&matrixWriteMutex);
    pthread_mutex_destroy(&testMutex);
    pthread_exit(NULL);

}