/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   poligono.h
 * Author: davidms_83
 *
 * Created on 25 de abril de 2020, 18:20
 */

#ifndef POLIGONO_H
#define POLIGONO_H
#include "punto.h";

class Poligono{
    int nVertices; //Numero de puntos en el array dinamico
    Punto *vertices; //Array dinamico de objetos 
    void redimensionar(int aumento);
    
public:
    Poligono();
    Poligono(int n);
    void liberar();
    inline int getNumeroVertices() const{return nVertices;}
    Punto getVertice (int index) const;
    void addVertice(const Punto& v);
    double getPerimetro() const;
    
};


#endif /* POLIGONO_H */

