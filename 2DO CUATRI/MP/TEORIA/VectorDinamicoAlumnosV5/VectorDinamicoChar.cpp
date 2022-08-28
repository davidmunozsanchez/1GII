/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <cassert>

#include "VectorDinamicoChar.h"

void VectorDinamicoChar::inicializar() {
    this->capacidad = 10;
    this->arrayChar = new char[capacidad];
    this->nCaracteres = 0;
}

VectorDinamicoChar::VectorDinamicoChar() {
    inicializar();
}

void VectorDinamicoChar::liberar() {
    if (arrayChar != nullptr) {
        delete[] arrayChar;
        arrayChar = nullptr;
    }
    nCaracteres = 0;
    capacidad = 0;
}

void VectorDinamicoChar::leer(std::istream& flujo) {
    char caracter;

    liberar();
    inicializar();
    while (flujo.get(caracter)) {
        aniadir(caracter);
    }
}

void VectorDinamicoChar::mostrar(std::ostream& flujo) const {
    for (int i = 0; i < nCaracteres; i++) {
        flujo << arrayChar[i];
    }
}

void VectorDinamicoChar::redimensionar(int incremento) {
    if (nCaracteres + incremento > 0) {
        char* nuevoArray = new char[nCaracteres + incremento];
        for (int i = 0; (i < nCaracteres) &&
                (i < nCaracteres + incremento); i++) {
            nuevoArray[i] = arrayChar[i];
        }
        delete[] arrayChar;
        arrayChar = nuevoArray;
        capacidad += incremento; //nchar = nchar + incremento;
    }
}

void VectorDinamicoChar::aniadir(char caracter) {
    //redimensionar(arraychar, capacidad * 2);
    if (capacidad == nCaracteres) {
        char* nuevoArray = new char[capacidad * 2];
        for (int i = 0; (i < nCaracteres); i++) {
            nuevoArray[i] = arrayChar[i];
        }
        delete[] arrayChar;
        arrayChar = nuevoArray;
        capacidad *= 2;
    }
    arrayChar[nCaracteres] = caracter;
    nCaracteres++;
}

int VectorDinamicoChar::numeroCaracteres() const {
    return nCaracteres;
}

char& VectorDinamicoChar::valor(int pos) {
    assert(pos>=0 && pos<nCaracteres);
    return arrayChar[pos];
}

const char& VectorDinamicoChar::valor(int pos) const {
    assert(pos>=0 && pos<nCaracteres);
    return arrayChar[pos];
}