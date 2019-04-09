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
        else
    {
    for (int rowOfA = ROWSPERTHREAD * threadId; rowOfA < (ROWSPERTHREAD * threadId + ROWSPERTHREAD); ++rowOfA)
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
    cout << "thread finished: " << threadId;
   pthread_exit(NULL);
}



int twoDConvertGet(int row, int column, vector<int> matrix)
{
    return matrix[MATRIX_SIZE_TWO_D * row + column];
}



int main()
{
       double time_elapsed = 0.0;
        double time_elapsed_sys = 0.0;
       
         struct timeval timecheck;
        gettimeofday(&timecheck, NULL);
        long timeofday_start = (long)timecheck.tv_sec * 1000 + (long)timecheck.tv_usec / 1000;


       
        srand (time (0));
 //       cout << pow(MATRIX_SIZE_TWO_D, 2);
    for (int i = 0; i < pow(MATRIX_SIZE_TWO_D, 2); ++i)
        {
            vectorA[i] = rand() % 4;
            vectorB[i] = rand() % 4;
    }
    
         cout << endl << endl << "Before loop A: " << endl;
        for (int i = 0; i < pow(MATRIX_SIZE_TWO_D, 2); i++)
        {
            if(i%MATRIX_SIZE_TWO_D == 0)
            {
                cout << endl;
            }
            cout << vectorA[i];
        }
       
                cout << endl << endl << "Before loop B: " << endl;
        for (int i = 0; i < pow(MATRIX_SIZE_TWO_D, 2); i++)
        {
            if(i%MATRIX_SIZE_TWO_D == 0)
            {
                cout << endl;
            }
            cout << vectorB[i];
       }
               
                cout << endl <<  endl;
       
                    long clock_start = clock();
                    
                    

}