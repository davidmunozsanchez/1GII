/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "skyline.h"


void SkyLine::liberar_memoria(){
    delete[] abscisas;
    delete[] alturas;
    
    n = 0;
    abscisas = nullptr;
    alturas = nullptr;
}

void SkyLine::reservar_memoria(int n){
    liberar_memoria();
    
    abscisas = new double[n];
    alturas = new double[n];
    
    this->n = n;
}

void SkyLine::copia(const SkyLine& sk){
    if (this->n != sk.n){
        reservar_memoria(sk.n);
    }
    for (int i = 0; i < n; i++)
        this->abscisas[i] = sk.abscisas[i];
    
    for (int i = 0; i < n; i++)
        this->alturas[i] = sk.alturas[i];
}

SkyLine::SkyLine(){
    abscisas = nullptr;
    alturas = nullptr;
    n = 0;
}

SkyLine::~SkyLine(){
    liberar_memoria();
}

SkyLine::SkyLine(double ab1, double ab2, double alt){
    reservar_memoria(2);
    n = 2;
    
    abscisas[0] = ab1;
    abscisas[1] = ab2;
    alturas[0]  = alt;
    alturas[1] = 0.0;
}

SkyLine::SkyLine(const SkyLine& sk){
    n = 0;
    abscisas = nullptr;
    alturas = nullptr;
    
    copia(sk);
}

SkyLine SkyLine::operator =(const SkyLine& sk){
    if (this != &sk) {
        copia(sk);
    }

    return *this;
}

double SkyLine::Altura(int ab){
    
}