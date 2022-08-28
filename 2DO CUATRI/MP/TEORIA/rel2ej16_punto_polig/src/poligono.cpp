/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "poligono.h"
#include <cassert>

void Poligono::redimensionar(int aumento){
    assert(nVertices + aumento > 0);
    
    Punto *info_ampl  = new Punto [nVertices + aumento];
    for (int i = 0; (i < nVertices) && (i < nVertices + aumento); i++)
        info_ampl[i] = vertices[i];
    delete[] vertices;
    vertices = info_ampl;
    nVertices += aumento;
}

Poligono::Poligono(){
    vertices = 0;
    nVertices = 0;
}

Poligono::Poligono(int n){
    assert(n>0);
    vertices = new Punto [n];
    nVertices = n;
}

void Poligono::liberar(){
    delete[] vertices;
    nVertices = 0;
}

Punto Poligono::getVertice(int index) const{
    assert(index >= 0 && index < nVertices);
    return vertices[index];
}

void Poligono::addVertice(const Punto& v){
    redimensionar(1);
    vertices[nVertices] = v; 
}

double Poligono::getPerimetro() const{
    
}


