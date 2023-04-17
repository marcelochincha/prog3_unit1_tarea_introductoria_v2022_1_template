//
// Created by rudri on 10/11/2020.
//

#include <iostream>
#include "PC1.h"
#include "matrix.h"
using namespace std;

void question_1_1(){

    cout << "Q1" << endl;
    // Definir aqui alguno de los casos de usos
    matrix m1(4, 5);

    for (int i = 0; i < m1.rows(); ++i) {
        for (int j = 0; j < m1.cols(); ++j) {
            m1(i, j) = 1;
        }
    }

    cout << m1;
}

void question_1_2(){

    cout << "Q2" << endl;
    // Definir aqui alguno de los casos de usos
    matrix m1(4,5);

    for (int i = 0; i < m1.rows(); ++i) {
        for (int j = 0; j < m1.cols(); ++j) {
            m1(i, j) = (rand() % 40) + 10;
        }
    }
    cout << m1;

    matrix m2 = m1; //Copiando matriz
    cout << m2;
}

void question_1_3(){
    
    cout << "Q3" << endl;
    // Definir aqui alguno de los casos de usos
    matrix m1(2,2), m3(2,2);

    for (int i = 0; i < m1.rows(); ++i) {
        for (int j = 0; j < m1.cols(); ++j) {
            m1(i, j) = (rand() % 10);
            m3(i, j) = (rand() % 100) ;
        }
    }    

    matrix m2 = m1;

    cout << m1 << m2 << m3;

    cout << "m1 == m2 " << boolalpha << (m1 == m2) << endl;
    cout << "m2 == m3 " << boolalpha << (m2 == m3) << endl;
    cout << "m1 != m3 " << boolalpha << (m1 != m3) << endl;
}

void question_1_4(){
    // Definir aqui alguno de los casos de usos

}
