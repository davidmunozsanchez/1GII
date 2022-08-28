/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   VectorSD.h
 * Author: davidms_83
 *
 * Created on 25 de abril de 2020, 17:00
 */

#ifndef VECTORSD_H
#define VECTORSD_H

#include <iostream>
#include <fstream>

class VectorSD{
    private:
        int *info; //array dinamino de enteros
        int util; //numero de enteros en el array
        int capacidad; //capacidad del array
        void redimensionar(int aumento);
        
    public:
        VectorSD();
        VectorSD(int n);
        int getDato(int posicion) const;
        inline int nElementos()const {return util;}
        void aniadir(int dato);
        void copia(const VectorSD &vector);
        void liberar();
        void mostrar(std::ostream& flujo) const;
        void leer(std::istream& flujo);
};


#endif /* VECTORSD_H */

