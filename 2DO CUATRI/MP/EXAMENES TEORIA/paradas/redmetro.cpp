/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "redmetro.h"
#include "linea.h"
#include <fstream>

using namespace std;

void RedMetro::liberar_memoria() {
    delete[] lineas;
    num_lineas = 0;
    lineas = nullptr;
}

void RedMetro::reservar_memoria(int n) {
    liberar_memoria();
    if (n > 0) {
        lineas = new Linea[n];
        num_lineas = n;
    }
}

void RedMetro::copiar(const RedMetro& rm) {
    if (this->num_lineas != rm.num_lineas)
        reservar_memoria(rm.GetNumLineas());

    for (int i = 0; i < rm.GetNumLineas(); i++) {
        this->lineas[i] = rm.lineas[i];
    }
}

RedMetro::RedMetro() {
    num_lineas = 0;
    lineas = nullptr;
}

RedMetro::RedMetro(const RedMetro& rm) {
    lineas = nullptr;
    num_lineas = 0;
    copiar(rm);
}

RedMetro::~RedMetro() {
    liberar_memoria();
}

bool RedMetro::EstaVacia() {
    if (GetNumLineas() == 0) {
        return true;
    } else
        return false;
}

RedMetro& RedMetro::operator=(const RedMetro& rm) {
    if (&rm != this) {
        copiar(rm);
    }

    return *this;
}

ostream& operator<<(ostream& flujo, const RedMetro &rm) {
    flujo << rm.num_lineas << endl;

    for (int i = 0; i < rm.num_lineas; i++) {
        flujo << rm.lineas[i].GetNumParadas() << endl;
        for (int j = 0; j < rm.lineas[i].GetNumParadas(); j++) {
            flujo << rm.lineas[i][j].GetIndice() << " " << rm.lineas[i][j].EstaActiva() ? "S" : "N";
            flujo << endl;
        }
    }


}

istream& operator>>(istream& flujo, RedMetro &rm) {
    int num_lineas;
    int num_paradas;

    flujo >> num_lineas;
    rm.reservar_memoria(num_lineas);

    for (int i = 0; i < num_lineas; i++) {
    }
}

RedMetro::RedMetro(const std::string& fichero) {
    fstream flujo;
    flujo.open(fichero);
    string palabra;

    flujo >> palabra;


    flujo >> *this;
}

double RedMetro::valorCalidad() const {
    int num_paradas = 0;

    for (int i = 0; i < num_lineas; i++) {
        for (int j = 0; j < lineas[i].GetNumParadas(); j++) {
            if (lineas[i][j + 1].EstaActiva())
                num_paradas += 1;
        }
    }

    return (num_lineas * 0.3 + num_paradas * 0.7);
}

bool RedMetro::operator==(const RedMetro& rm) const {
    if (valorCalidad() == rm.valorCalidad()) {
        return true;
    }
    else
        return false;
}

bool RedMetro::operator!=(const RedMetro& rm) const {
    if (valorCalidad() == rm.valorCalidad())
        return false;

    else
        return true;


}

bool RedMetro::operator>(const RedMetro& rm) const {
    if (valorCalidad() > rm.valorCalidad())
        return true;

    else
        return false;


}

int RedMetro::MejorConectada() const{
    int *vector = new int [GetNumeroParadas()];
    
    for (int i = 0; i < GetNumeroParadas(); i++){
        vector[i] = 0;
    }
    
    for (int i = 0; i < num_lineas; i++){
        for (int j = 0; j < lineas[i].GetNumParadas(); j++){
            vector[lineas[i][j].GetIndice - 1] += 1; 
        }
    }
    
    int max = 0;
    
    for (int i = 0; i < GetNumeroParadas(); i++){
        if(vector[i] > vector[max])
            max = i;
    }
    
    return max;
}