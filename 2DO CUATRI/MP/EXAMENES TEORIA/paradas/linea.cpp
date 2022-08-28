/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "linea.h"
#include "infoparada.h"

Linea& operator+=(const InfoParada &parada) {
    redimensionar(1);
    paradas[num_paradas - 1] = parada;
    
    return *this;
    
}

void Linea::redimensionar(int aumento) {

    if (num_paradas + aumento > 0) {
        InfoParada *v_ampliado = new InfoParada[num_paradas + aumento];
        for (int i = 0; (i < num_paradas) && (i < num_paradas + aumento); i++)
            v_ampliado[i] = paradas[i];
        delete[] paradas;
        paradas = nullptr;
        paradas = v_ampliado;
        num_paradas = num_paradas + aumento;
    }

}

bool Linea::EstaTotalmenteOperativa()const{
    for (int i = 0; i < num_paradas; i++){
        if (paradas[i].activa() == false)
            return false;
    }
    
    return true;
}

istream& operator>>(istream& flujo, Linea &linea){
    flujo >> linea.num_paradas;
    
    
    for (int i = 0; i < linea.num_paradas; i++){
        flujo >> linea.paradas[i];
    }
    
    return flujo;
}