/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Matriz.cpp
 * Author: davidms_83
 * 
 * Created on 31 de marzo de 2020, 15:45
 */

#include <cassert>
#include "Matriz.h"

Matriz::Matriz(int nf, int nc) {
    assert(nf>'0' && nc>0);
    nfil = nf;
    ncol = nc;
    matriz = new int*[nfil];
}

int Matriz::get(int fila, int col) const{
    assert(fila>=0 && fila < nfil && col>=0 && col < ncol);
    return matriz[fila][col];
}

void Matriz::set(int fila, int col, int dato){
    assert(fila>=0 && fila < nfil && col>=0 && col < ncol);
    matriz[fila][col] = dato; 
}

void Matriz::Destruir(){
    for (int i= 0; i < nfil; i++){
        delete[] matriz[i];
    }
   
    delete[] matriz;
    matriz = 0; // Matriz a null pointer
    nfil = 0;
    ncol = 0;
}



