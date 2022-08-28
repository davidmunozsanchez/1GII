/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: acu
 *
 * Created on 24 de marzo de 2020, 15:41
 */

#include <fstream>
#include <iostream>

#include "VectorDinamicoChar.h"

using namespace std;

/*
 * 
 */
int main(int argc, char* argv[]) {
    VectorDinamicoChar vectorChar;

    if (argc == 1)
        vectorChar.leer(cin);
    else {
        ifstream flujo;
        flujo.open(argv[1]);
        if (!flujo) {
            cerr << "Error: Fichero " << argv[1] << "no válido." << endl;
            return 1;
        }
        vectorChar.leer(flujo);
        //...
        //leer(flujo, vectorChar);
        flujo.close();
    }
    vectorChar.mostrar(cout);

    for (int i = 0; i < vectorChar.numeroCaracteres(); i++) {
        vectorChar.valor(i) = toupper(vectorChar.valor(i));
        //char a = toupper(vectorChar.valor(i));
    }
    vectorChar.mostrar(cout);

    vectorChar.liberar();
    return 0;
}

void funcionPrueba(const VectorDinamicoChar& v1, VectorDinamicoChar& v2) {
    cout << v1.valor(0) << endl;
    cout << v2.valor(0) << endl;
}