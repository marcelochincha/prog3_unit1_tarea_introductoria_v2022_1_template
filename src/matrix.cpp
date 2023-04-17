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

    if(this == &m)
        return;

    this->nRows = m.nRows;
    this->nCols = m.nCols;

    this->data = new int*[m.rows()];

    for (int i = 0; i < m.rows(); i++){
        this->data[i] = new int[m.cols()];
    }

    //Copy copy
    for (int i = 0; i < m.rows(); i++){
        for (int j = 0; j < m.cols(); j++){
            this->data[i][j] = m.data[i][j];
        }
    }
}

matrix::matrix(matrix&& m){
    if(this == &m)
        return;
    this->nRows = m.nRows;
    this->nCols = m.nCols;

    this->data = m.data;

    m.nCols = 0;
    m.nRows = 0;
    m.data = nullptr;
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

//Sobrecarga de operadores

bool matrix::operator==(const matrix& other){

    if (this->nRows != other.nRows || this->nCols != other.nCols)
        return false;
    
    for (int i = 0; i < this->nRows; i++){
        for (int j = 0; j < this->nCols; j++){
            if(this->data[i][j] != other.data[i][j])
                return false;
        }
    }
    return true;
}

bool matrix::operator!=(const matrix& other){
    return !(matrix::operator==(other));
}

matrix& matrix::operator+(const matrix& other){

    if (this->nRows != other.nRows || this->nCols != other.nCols)
        return;


    matrix buffer(this->nRows,this->nCols);
    for (int i = 0; i < this->nRows; i++){
        for (int j = 0; j < this->nCols; j++){
            buffer(i,j) = this->data[i][j] + other.data[i][j];
        }
    }
    return buffer;
}

matrix& matrix::operator*(const matrix& other){

    if (this->nCols != other.nRows)
        return;

    matrix buffer(this->nRows,other.nCols);

    for (int i = 0; i < this->nRows; i++){
        for (int j = 0; j < this->nCols; j++){
            int tempValue = 0;
            for(int t = 0; t < this->nCols; t++)
                tempValue += this->data[i][t] * other.data[t][j];
            buffer(i,j) = tempValue;
        }
    }

    return buffer;
}

matrix& matrix::operator*(const int c){
    for (int i = 0; i < this->nRows; i++){
        for (int j = 0; j < this->nCols; j++){
            this->data[i][j] *= c;
        }
    }
}

matrix& matrix::operator+=(const matrix& other){
    *this = (*(this) + other);
    return *this
}

std::ostream& operator<<(std::ostream& os, const matrix& m){

    os << "Matrix: " << m.nRows << "x" << m.nCols << std::endl;

    for (int i = 0; i < m.nRows; i++){
        for (int j = 0; j < m.nCols; j++){
            os << m.get(i,j) << " ";
        }
        os << std::endl;
    }
    return os;
}



