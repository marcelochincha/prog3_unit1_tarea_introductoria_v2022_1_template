//
// Created by rudri on 3/23/2022.
//

#ifndef PROG3_UNIT1_TAREA_INTRODUCTORIA_V2022_1_MATRIX_H
#define PROG3_UNIT1_TAREA_INTRODUCTORIA_V2022_1_MATRIX_H

#include <iostream>

class matrix
{
    int nRows,nCols;
    int **data;

    public:

        //Constructores
        matrix(int nRows, int nCols);

        matrix(const matrix& m);    //Copia
        matrix(matrix&& m);         //Movimiento

        ~matrix();

        int rows() const;
        int cols() const;

        int get(int i, int j) const;
        int& operator()(int i, int j);

        friend std::ostream& operator<<(std::ostream& os, const matrix& m);    
};

std::ostream& operator<<(std::ostream& os, const matrix& m);    

#endif //PROG3_UNIT1_TAREA_INTRODUCTORIA_V2022_1_MATRIX_H
