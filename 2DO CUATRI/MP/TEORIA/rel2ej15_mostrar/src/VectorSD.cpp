/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "VectorSD.h"
#include <cassert>


using namespace std;

void VectorSD::redimensionar(int aumento){
    assert(capacidad + aumento > 0);
    
    int *info_ampl  = new int [util + aumento];
    for (int i = 0; (i < capacidad) && (i < capacidad + aumento); i++)
        info_ampl[i] = info [i];
    delete [] info;
    info = info_ampl;
    capacidad = capacidad + aumento;
}

VectorSD::VectorSD() {
    info = new int [10];
    util = 0;
    capacidad = 10;
}

VectorSD::VectorSD(int n){
    assert(n > 0);
    info = new int[n];
    util = 0;
    capacidad = n;
}

int VectorSD::getDato(int posicion) const{
    assert(posicion <= util);
    return info[posicion];
}

void VectorSD::aniadir(int dato){
    if (util == capacidad){
        redimensionar(capacidad);
        info[util] = dato;
        util += 1;
    }
    else{
        info[util] = dato;
        util += 1;
    }
}

void VectorSD::copia(const VectorSD& vector){
    int *copia = new int [vector.nElementos()];
    for (int i=0; i < vector.nElementos(); i++){
        copia[i] = vector.getDato(i);
    }
    liberar();
    info = copia;
    util = vector.nElementos();
    capacidad = vector.nElementos();
}

void VectorSD::liberar(){
    delete[] info;
    util = 0;
    capacidad = 0;
}

void VectorSD::mostrar(ostream& flujo) const{
    for(int i=0; i<util; i++){
        flujo << info[i] << " ";
    }
    flujo << endl;
}

void VectorSD::leer(istream& flujo){
    int dato;
    
    flujo >> dato;
    do{ 
        if (dato != 99)
            aniadir(dato);
    }while(dato != 99 && flujo >> dato);
}