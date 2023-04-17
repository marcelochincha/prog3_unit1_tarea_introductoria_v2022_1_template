//
// Created by rudri on 10/11/2020.
//

#include <iostream>
#include "PC1.h"
#include "matrix.h"
using namespace std;

void question_1_1(){
    // Definir aqui alguno de los casos de usos

    // Constructor por parametros
    matrix m1(4, 5);
    cout << "DONE!";
    // Ingreso de datos
    for (int i = 0; i < m1.rows(); ++i) {
        for (int j = 0; j < m1.cols(); ++j) {
            m1(i, j) = 1;
        }
    }
    // Impresion de libreria
    std::cout << m1;
}

void question_1_2(){
    // Definir aqui alguno de los casos de usos

}

void question_1_3(){
    // Definir aqui alguno de los casos de usos

}

void question_1_4(){
    // Definir aqui alguno de los casos de usos

}
