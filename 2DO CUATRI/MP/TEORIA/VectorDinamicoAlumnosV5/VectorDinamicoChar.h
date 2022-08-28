/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   VectorDinamicoChar.h
 * Author: acu
 *
 * Created on 24 de marzo de 2020, 15:42
 */

#ifndef VECTORDINAMICOCHAR_H
#define VECTORDINAMICOCHAR_H
#include <iostream>

class VectorDinamicoChar {
    char* arrayChar; // array dinámico de char
    int nCaracteres; // no de caracteres actualmente en el array
    int capacidad;
    
    void inicializar();
public:
    VectorDinamicoChar();
    void liberar();
    void leer(std::istream& flujo);
    void mostrar(std::ostream& flujo) const;
    void redimensionar(int incremento);
    void aniadir(char caracter);
    int numeroCaracteres() const;
    char& valor(int pos);
    const char& valor(int pos) const;
};



#endif /* VECTORDINAMICOCHAR_H */

