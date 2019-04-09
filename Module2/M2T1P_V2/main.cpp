// M2T1P.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include <sys/time.h>
#include <fstream>

using namespace std;


const int MATRIX_SIZE = 10;

int matrixA[MATRIX_SIZE][MATRIX_SIZE];
int matrixB[MATRIX_SIZE][MATRIX_SIZE];
int matrixC[MATRIX_SIZE][MATRIX_SIZE];
ofstream matrixFile;



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

    matrixFile.open ("matrix.txt");

    matrixFile << endl << endl << "Matrix A: " << endl;
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            matrixFile << matrixA[i][j];
        }
        matrixFile << endl;
    }
       
    matrixFile << endl << endl << "Matrix B: " << endl;
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            matrixFile << matrixB[i][j];
        }
        matrixFile << endl;
    }
               
    matrixFile << endl <<  endl;
    
    
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
   
    matrixFile << endl << endl << "Matrix C: " << endl;
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            matrixFile << matrixC[i][j];
        }
        matrixFile << endl;
    }
    
    matrixFile.close();
}