/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: GOZDEDOGAN
 *
 * Created on January 18, 2020, 8:40 PM
 */

#include <iostream>
#include <fstream>
#include <string>

#define MAX 100

using namespace std;

double **searchedMatrix1;
int rowSearchedM1 = 4, colSearchedM1 = 3;
string searchedMatrixName1 = "book";

double **searchedMatrix2;
int rowSearchedM2 = 3, colSearchedM2 = 2;
string searchedMatrixName2 = "car";

double **searchedMatrix3;
int rowSearchedM3 = 2, colSearchedM3 = 3;
string searchedMatrixName3 = "oh";

double **matrix; 
int rowSize = 10, colSize = 11;

string filename = "FindWordList.txt";

void allocate(double **matrix, int row, int col);
void initialize();
void free2DArr(double **matrix, int rowSize);
void searchingWordsInMatrix(double **matrix, int rowSize, int colSize);
bool searchingWordsInMatrixHelper(double **matrix, int rowSize, int colSize, double **searchedMatrix, int searchedRow, int searchedCol, string searchedName, ofstream& fout);
bool findMatrixInMatrix(double **matrix, int rowSize, int colSize, double **searchedMatrix, int searchedRow, int searchedCol, int startRow, int startCol);

/*
 * 
 */
int main(int argc, char** argv) {
    initialize();
        
    searchingWordsInMatrix(matrix, rowSize, colSize);
    
    for(int i = 0; i < rowSize; i++)
        delete [] matrix[i];
    delete [] matrix;
    
    for(int i = 0; i < rowSearchedM1; i++)
        delete [] searchedMatrix1[i];
    delete [] searchedMatrix1;
    
    for(int i = 0; i < rowSearchedM2; i++)
        delete [] searchedMatrix2[i];
    delete [] searchedMatrix2;
    
    for(int i = 0; i < rowSearchedM3; i++)
        delete [] searchedMatrix3[i];
    delete [] searchedMatrix3;
    
    return 0;
}

void searchingWordsInMatrix(double **matrix, int rowSize, int colSize)
{       
    ofstream fout;
    fout.open(filename, ios::out/* | ios::app*/);
    if (!fout.is_open()) {
        cerr << "Unable to open file " << filename << endl;
        exit(1);   // call system to stop
    }   
    
    searchingWordsInMatrixHelper(matrix, rowSize, colSize, searchedMatrix1, rowSearchedM1, colSearchedM1, searchedMatrixName1, fout);    
    searchingWordsInMatrixHelper(matrix, rowSize, colSize, searchedMatrix2, rowSearchedM2, colSearchedM2, searchedMatrixName2, fout);
    searchingWordsInMatrixHelper(matrix, rowSize, colSize, searchedMatrix3, rowSearchedM3, colSearchedM3, searchedMatrixName3, fout);
        
    fout.close();
}

bool searchingWordsInMatrixHelper(double **matrix, int rowSize, int colSize, double **searchedMatrix, int searchedRow, int searchedCol, string searchedName, ofstream& fout)
{          
    for(int i = 0; i < rowSize; i++)
    {
        for(int j = 0; j < colSize; j++)
        {
            if(matrix[i][j] == searchedMatrix[0][0])
            {
                if(findMatrixInMatrix(matrix, rowSize, colSize, searchedMatrix, searchedRow, searchedCol, i, j))
                {
                    cout << "FIND: ";
                    cout << searchedName << endl;
                    fout << searchedName << endl;
                    return true;
                }
            }
        }
    }
    return false;
}

bool findMatrixInMatrix(double **matrix, int rowSize, int colSize, double **searchedMatrix, int searchedRow, int searchedCol, int startRow, int startCol)
{
    int check = 0;
    
    for(int i = startRow, searched_i = 0; (i < startRow + searchedRow) && (searched_i < searchedRow); i++, searched_i++)
    {
        for(int j = startCol, searched_j = 0; (j < startCol + searchedCol) && (searched_j < searchedCol); j++, searched_j++)
        {
            if(matrix[i][j] == searchedMatrix[searched_i][searched_j])
            {
               /* cout << "EQUAL!" << endl;
                cout << "matrix[i][j]: " << matrix[i][j] << " \t i:" << i << "\tj:" << j <<endl;
                cout << "searchedMatrix[searched_i][searched_j]: " << searchedMatrix[searched_i][searched_j] << "\tsearched_i:"; 
                cout << searched_i << "\tsearched_j:" << searched_i << endl;*/
                
                check = 1;
            }
            else
                return false;
        }
    }
    return true;
}

void allocate(double **m, int r, int c)
{
    m = new double *[r];
    for(int i=0; i<r; i++)
    {
        m[i] = new double[c];
    }
}


void initialize()
{
    matrix = new double *[rowSize];
    for(int i=0; i<rowSize; i++)
        matrix[i] = new double[colSize];
    
    matrix[0][0] = 0; //{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
    matrix[0][1] = 1;
    matrix[0][2] = 2;
    matrix[0][3] = 3;
    matrix[0][4] = 4;
    matrix[0][5] = 5;
    matrix[0][6] = 6;
    matrix[0][7] = 7;
    matrix[0][8] = 8;
    matrix[0][9] = 9;
    matrix[0][10] = 10;
    
    matrix[1][0] = 11; //{11, 12, 2, 1, 2, 0, 1, 2, 3, 4, 5}
    matrix[1][1] = 12;
    matrix[1][2] = 2;
    matrix[1][3] = 1;
    matrix[1][4] = 2;
    matrix[1][5] = 0;
    matrix[1][6] = 1;
    matrix[1][7] = 2;
    matrix[1][8] = 3;
    matrix[1][9] = 4;
    matrix[1][10] = 5;
    
    matrix[2][0] = 6; //{6, 7, 3, 5, 3, 8, 9, 10, 11, 12, 13}
    matrix[2][1] = 7;
    matrix[2][2] = 3;
    matrix[2][3] = 5;
    matrix[2][4] = 3;
    matrix[2][5] = 8;
    matrix[2][6] = 9;
    matrix[2][7] = 10;
    matrix[2][8] = 11;
    matrix[2][9] = 12;
    matrix[2][10] = 13;
    
    matrix[3][0] = 10; //{10, 9, 2, 6, 1, 8, 7, 6, 5, 4, 3}
    matrix[3][1] = 9;
    matrix[3][2] = 2;
    matrix[3][3] = 6;
    matrix[3][4] = 1;
    matrix[3][5] = 8;
    matrix[3][6] = 7;
    matrix[3][7] = 6;
    matrix[3][8] = 5;
    matrix[3][9] = 4;
    matrix[3][10] = 3;
    
    matrix[4][0] = 2; //{2, 1, 3, 3, 3, 11, 12, 0, 1, 2, 3}
    matrix[4][1] = 1;
    matrix[4][2] = 3;
    matrix[4][3] = 3;
    matrix[4][4] = 3;
    matrix[4][5] = 11;
    matrix[4][6] = 12;
    matrix[4][7] = 0;
    matrix[4][8] = 1;
    matrix[4][9] = 2;
    matrix[4][10] = 3;
    
    matrix[5][0] = 4; //{4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14}
    matrix[5][1] = 5;
    matrix[5][2] = 6;
    matrix[5][3] = 7;
    matrix[5][4] = 8;
    matrix[5][5] = 9;
    matrix[5][6] = 10;
    matrix[5][7] = 11;
    matrix[5][8] = 12;
    matrix[5][9] = 13;
    matrix[5][10] = 14;
    
    matrix[6][0] = 7; //{7, 6, 5, 4, 1, 2, 3, 3, 2, 0, 4}
    matrix[6][1] = 6;
    matrix[6][2] = 5;
    matrix[6][3] = 4;
    matrix[6][4] = 1;
    matrix[6][5] = 2;
    matrix[6][6] = 3;
    matrix[6][7] = 3;
    matrix[6][8] = 2;
    matrix[6][9] = 0;
    matrix[6][10] = 4;
    
    matrix[7][0] = 3; //{3, 5, 7, 9, 0, 2, 4, 2, 4, 6, 8}
    matrix[7][1] = 5;
    matrix[7][2] = 7;
    matrix[7][3] = 9;
    matrix[7][4] = 0;
    matrix[7][5] = 2;
    matrix[7][6] = 4;
    matrix[7][7] = 2;
    matrix[7][8] = 4;
    matrix[7][9] = 6;
    matrix[7][10] = 8;
    
    matrix[8][0] = 1; //{1, 4, 7, 10, 13, 16, 19, 7, 3, 22, 25}
    matrix[8][1] = 4;
    matrix[8][2] = 7;
    matrix[8][3] = 10;
    matrix[8][4] = 13;
    matrix[8][5] = 16;
    matrix[8][6] = 19;
    matrix[8][7] = 7;
    matrix[8][8] = 3;
    matrix[8][9] = 22;
    matrix[8][10] = 25;
    
    matrix[9][0] = 5; //{5, 10, 15, 20, 25, 0, 5, 10, 3, 2, 1}
    matrix[9][1] = 10;
    matrix[9][2] = 15;
    matrix[9][3] = 20;
    matrix[9][4] = 25;
    matrix[9][5] = 0;
    matrix[9][6] = 5;
    matrix[9][7] = 10;
    matrix[9][8] = 3;
    matrix[9][9] = 2;
    matrix[9][10] = 1; 
    
    searchedMatrix1 = new double *[rowSearchedM1];
    for(int i=0; i<rowSearchedM1; i++)
        searchedMatrix1[i] = new double[colSearchedM1];
    
    searchedMatrix1[0][0] = 2; //= {{2, 1, 2}, {3, 5, 3}, {2, 6, 1}, {3, 3, 3}};
    searchedMatrix1[0][1] = 1;
    searchedMatrix1[0][2] = 2;
    
    searchedMatrix1[1][0] = 3;
    searchedMatrix1[1][1] = 5;
    searchedMatrix1[1][2] = 3;
    
    searchedMatrix1[2][0] = 2;
    searchedMatrix1[2][1] = 6;
    searchedMatrix1[2][2] = 1;
    
    searchedMatrix1[3][0] = 3;
    searchedMatrix1[3][1] = 3;
    searchedMatrix1[3][2] = 3;
    
    searchedMatrix2 = new double *[rowSearchedM2];
    for(int i=0; i<rowSearchedM2; i++)
        searchedMatrix2[i] = new double[colSearchedM2];
    
    //{{3, 2}, {2, 4}, {7, 3}};
    searchedMatrix2[0][0] = 3; 
    searchedMatrix2[0][1] = 2;
    
    searchedMatrix2[1][0] = 2;
    searchedMatrix2[1][1] = 4;
    
    searchedMatrix2[2][0] = 7;
    searchedMatrix2[2][1] = 3;
    
    searchedMatrix3 = new double *[rowSearchedM3];
    for(int i=0; i<rowSearchedM3; i++)
        searchedMatrix3[i] = new double[colSearchedM3];
    
    //{{5, 7, 2}, {3, 6, 4}};
    searchedMatrix3[0][0] = 5; //= {{2, 1, 2}, {3, 5, 3}, {2, 6, 1}, {3, 3, 3}};
    searchedMatrix3[0][1] = 7;
    searchedMatrix3[0][2] = 2;
    
    searchedMatrix3[1][0] = 3;
    searchedMatrix3[1][1] = 6;
    searchedMatrix3[1][2] = 4;
}

void free2DArr(double **m, int r)
{
    for(int i = 0; i < r; i++)
        delete [] m[i];
    delete [] m;
}
