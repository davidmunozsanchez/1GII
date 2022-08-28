/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "vectorpuntos.h"
#include "punto.h"
#include <cassert>


/* 
 * File:   vectorpuntos.cpp
 * Author: davidms_83
 *
 * Created on 13 de junio de 2020, 16:25
 */

VectorPuntos::VectorPuntos(){
    nPuntos = 0;
    reservar_memoria(10);
}

VectorPuntos::VectorPuntos(const VectorPuntos& v){
    reservar_memoria(v.reservados);
    copia(v);
}
void VectorPuntos::reservar_memoria(int n){
    liberar_memoria();
    if (n > 0){
        puntos = new Punto[n];
        reservados = n;
    }
}

VectorPuntos& VectorPuntos::operator =(const VectorPuntos& v){
    if (&v != this){
        liberar_memoria();
        reservar_memoria(v.reservados);
        copia(v);
    }
    
    return *this;
}

void VectorPuntos::liberar_memoria(){
    delete[] puntos;
    puntos = nullptr;
    nPuntos = 0;
    reservados = 0;
}

void VectorPuntos::copia(const VectorPuntos& v){
    this->nPuntos = v.nPuntos;
    this->reservados = v.reservados;
    for (int i = 0; i < nPuntos; i++){
        this->puntos[i] = v.puntos[i];
    }
    
}

VectorPuntos::~VectorPuntos(){
    liberar_memoria();
}

void VectorPuntos::redimensionar (int* &v, int& tama, int aumento){
	if(tama+aumento > 0){
		Punto *v_ampliado = new Punto[tama+aumento];
		for (int i=0; (i<tama) && (i<tama+aumento); i++)
			v_ampliado[i] = v[i];
		delete[] v;
		v = v_ampliado;
		tama=tama+aumento;
	}
}

void VectorPuntos::add(const Punto& p){
    int posicion_final = nPuntos;
    if (nPuntos == reservados){
        redimensionar(puntos, reservados, reservados);
    }
    
    nPuntos += 1;
    puntos[posicion_final];
}

Punto& VectorPuntos::operator [](int i){
    assert(i >= 0 && i < nPuntos);
    return puntos[i];
}

const Punto& VectorPuntos::operator [](int i)const{
    assert(i >= 0 && i < nPuntos);
    return puntos[i];
}