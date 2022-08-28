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

using namespace std;

void inicializar(char* &array, int &nchar);

void liberar(char* &array, int &nchar);

void mostrar(ostream& salida,char* array,int nchar); //cout << dato

void redimensionar(char* &array, int &nchar, int aumento);

void aniadir(char aniade);

void leer(istream& flujo, char*&array, int& nchar); //cin >> dato istream es superclase de ifstream, podría usarlo con un fichero tambien
#endif /* VECTORDINAMICOCHAR_H */

