// M2T1P.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include "Matrix.h"
#include <time.h>
#include <stdio.h>
#include <pthread.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include<cmath>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>
#include <thread>


using namespace std;

const int NUMBER_OF_THREADS = 4;

int N = 2;
int rowsPerThread = 0;
const int MATRIX_SIZE = 2000;
int matrixA[MATRIX_SIZE][MATRIX_SIZE];
int matrixB[MATRIX_SIZE][MATRIX_SIZE];
int matrixC[MATRIX_SIZE][MATRIX_SIZE];
const int ROWS_PER_THREAD = int(MATRIX_SIZE/NUMBER_OF_THREADS);
volatile int extraRows = MATRIX_SIZE%NUMBER_OF_THREADS;
pthread_mutex_t writeMutex = PTHREAD_MUTEX_INITIALIZER;



void *MultiplyPartMatrices(void *id)
{
    int threadId = (long)id;
   
    if(threadId == NUMBER_OF_THREADS - 1)
    {
            for (int rowOfA = ROWS_PER_THREAD * threadId; rowOfA < (ROWS_PER_THREAD * threadId + ROWS_PER_THREAD + extraRows); ++rowOfA)
    {
        for (int columnOfB = 0; columnOfB < MATRIX_SIZE; ++columnOfB)
        {
            int result = 0;
            for (int i = 0; i < MATRIX_SIZE; ++i)
            {
                result = result + matrixA[rowOfA][i] * matrixB[i][columnOfB];
            }
            pthread_mutex_lock(&writeMutex);
            matrixC[rowOfA][columnOfB] = result;
            pthread_mutex_unlock(&writeMutex);
           
    }
    }
    }
        else
    {
    for (int rowOfA = ROWS_PER_THREAD * threadId; rowOfA < (ROWS_PER_THREAD * threadId + ROWS_PER_THREAD); ++rowOfA)
    {
        for (int columnOfB = 0; columnOfB < MATRIX_SIZE; ++columnOfB)
        {
            int result = 0;
            for (int i = 0; i < MATRIX_SIZE; ++i)
            {
                result = result + matrixA[rowOfA][i] * matrixB[i][columnOfB];
            }
            pthread_mutex_lock(&writeMutex);
            matrixC[rowOfA][columnOfB] = result;
            pthread_mutex_unlock(&writeMutex);
           
    }
    }

    }
    cout << "thread finished: " << threadId << endl << endl;
   pthread_exit(NULL);
}



int main()
{
      // double time_elapsed = 0.0;
        double time_elapsed_sys = 0.0;
       
         struct timeval timecheck;
        gettimeofday(&timecheck, NULL);
        long timeofday_start = (long)timecheck.tv_sec * 1000 + (long)timecheck.tv_usec / 1000;


       
        srand (time (0));
    for (int i = 0; i < MATRIX_SIZE; i++)
        {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            matrixA[i][j] = rand() % 4;
            matrixB[i][j] = rand() % 4;
        }
    }
    
         cout << endl << endl << "Before loop A: " << endl;
        for (int i = 0; i < MATRIX_SIZE; i++)
        {
            for (int j = 0; j < MATRIX_SIZE; j++)
            {
               // cout << matrixA[i][j];
            }
         //   cout << endl;
        }
       
                cout << endl << endl << "Before loop B: " << endl;
        for (int i = 0; i < MATRIX_SIZE; i++)
        {
            for (int j = 0; j < MATRIX_SIZE; j++)
            {
               // cout << matrixB[i][j];
            }
          //  cout << endl;
       }
               
                cout << endl <<  endl;
       
                    long clock_start = clock();
                    
                   pthread_t threads[NUMBER_OF_THREADS];
   
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
   
    //    long clock_end = clock();  
    //time_elapsed = (clock_end - clock_start) / CLOCKS_PER_SEC;

    //printf("Time elapsed: %.2f\n", time_elapsed);
   
        gettimeofday(&timecheck, NULL);
    long timeofday_end = (long)timecheck.tv_sec * 1000 + (long)timecheck.tv_usec / 1000;
   
    time_elapsed_sys = (timeofday_end - timeofday_start)/1000;
    printf("Sys time elapsed %.4f\n", time_elapsed_sys);
   
                    cout << endl << endl << "Matrix C: " << endl;
  for (int i = 0; i < MATRIX_SIZE; i++)
        {
            for (int j = 0; j < MATRIX_SIZE; j++)
            {
             //   cout << matrixC[i][j];
            }
          //  cout << endl;
       }
    pthread_mutex_destroy(&writeMutex);
}