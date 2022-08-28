/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   VectorDinamicoChar.h
 * Author: davidms_83
 *
 * Created on 17 de marzo de 2020, 17:25
 */

#ifndef VECTORDINAMICOCHAR_H
#define VECTORDINAMICOCHAR_H

#include <fstream>
#include <iostream>

struct VectorDinamicoChar{
    char* arrayChar; //array dinamico de char
    int nCaracteres; //numero de caracteres actualmente en el array
};
using namespace std;

void inicializar(VectorDinamicoChar &array);

void liberar(VectorDinamicoChar &array);

void mostrar(ostream& salida, const VectorDinamicoChar &array); //cout << dato

void redimensionar(VectorDinamicoChar &array, int aumento);

void aniadir(VectorDinamicoChar &array, char aniade);

void leer(istream& flujo, VectorDinamicoChar &array); //cin >> dato istream es superclase de ifstream, podría usarlo con un fichero tambien
#endif /* VECTORDINAMICOCHAR_H */

