//
// Created by rudri on 3/23/2022.
//

#include "matrix.h"

//Constructores
matrix::matrix(int nRows, int nCols){
    this->nRows = nRows;
    this->nCols = nCols;

    data = new int*[nRows];

    for (int i = 0; i < nRows; i++)
        data[i] = new int[nCols];
}

matrix::matrix(const matrix& m){
    this->nRows = m.nRows;
    this->nCols = m.nCols;

    //this->data 


}

matrix::matrix(matrix&& m){
    
}

matrix::~matrix(){
    for (int i = 0; i < nRows; i++)
        delete[] data[i];
    delete[] data;
}


//Metodos
int matrix::rows() const{
    return nRows;
}

int matrix::cols() const{
    return nCols;
}

//Read only
int matrix::get(int i, int j) const{
    return data[i][j];
}

//Read AND Write 
int& matrix::operator()(int i, int j){
    return data[i][j];
}

std::ostream& operator<<(std::ostream& os, const matrix& m){

    os << "Matrix: " << m.nRows << "x" << m.nCols << std::endl;

    for (int i = 0; i < m.nRows; i++)
    {
        for (int j = 0; j < m.nCols; j++)
        {
            os << m.get(i,j) << " ";
        }
        os << std::endl;
    }
    return os;
}


int** copyMat(const matrix &m)
{

    //Create buffer
    int** matBuffer = new int*[m.rows()];

    for (int i = 0; i < m.rows(); i++)
    {
        matBuffer[i] = new int[m.cols()];
    }

    //Copy copy
    for (int i = 0; i < m.rows(); i++)
    {
        for (int j = 0; j < m.rows(); j++)
        {
        }
    }

}

