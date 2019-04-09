// M2T1P.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include <sys/time.h>

using namespace std;


const int MATRIX_SIZE = 800;

int matrixA[MATRIX_SIZE][MATRIX_SIZE];
int matrixB[MATRIX_SIZE][MATRIX_SIZE];
int matrixC[MATRIX_SIZE][MATRIX_SIZE];



int main()
{
    double time_elapsed = 0.0;
    
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
            //    cout << matrixA[i][j];
        }
        //  cout << endl;
    }
       
    cout << endl << endl << "Before loop B: " << endl;
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            //    cout << matrixB[i][j];
        }
        //cout << endl;
    }
               
    cout << endl <<  endl;
    
    
    struct timeval timecheck;
    gettimeofday(&timecheck, NULL);
    long timeofday_start = (long)timecheck.tv_sec * 1000 + (long)timecheck.tv_usec / 1000;
       

    for (int rowOfA = 0; rowOfA < MATRIX_SIZE; ++rowOfA)
    {
        for (int columnOfB = 0; columnOfB < MATRIX_SIZE; ++columnOfB)
        {
            int result = 0;
            for (int i = 0; i < MATRIX_SIZE; ++i)
            {
                result = result + matrixA[rowOfA][i] * matrixB[i][columnOfB];		
            }
            matrixC[rowOfA][columnOfB] = result;
	}
    }
    
    gettimeofday(&timecheck, NULL);
    long timeofday_end = (long)timecheck.tv_sec * 1000 + (long)timecheck.tv_usec / 1000;
   
    time_elapsed = (timeofday_end - timeofday_start)/1000;
    printf("Time elapsed %.4f\n", time_elapsed);
   
    cout << endl << endl << "Matrix C: " << endl;
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            //   cout << matrixC[i][j];
        }
        //  cout << endl;
    }
}