/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <ostream>

#include "cluster.h"


/* 
 * File:   cluster.cpp
 * Author: davidms_83
 *
 * Created on 13 de junio de 2020, 16:49
 */



using namespace std;

Punto Cluster::calcularCentroide() {
    Punto centroide;
    int num_puntos = puntos.size();
    double sumax = 0.0;
    double sumay = 0.0;
    double mediax;
    double mediay;

    for (int i = 0; i < num_puntos; i++) {
        sumax += puntos[i].getX();
    }

    for (int i = 0; i < num_puntos; i++) {
        sumay += puntos[i].getY();
    }

    mediax = sumax / (num_puntos * 1.0);
    mediay = sumay / (num_puntos * 1.0);

    centroide.setXY(mediax, mediay);

    return centroide;

}

std::ostream& operator<<(std::ostream& flujo, const Cluster &c){
    flujo << c.centroide << endl;
    flujo << c.puntos << endl;
    
    return flujo;
}

std::istream& operator>>(std::istream& flujo, Cluster &c){
    flujo >> c.centroide; //falta libeemrar memoria antes
    
    flujo >> c.puntos;
    
    return flujo;
}

