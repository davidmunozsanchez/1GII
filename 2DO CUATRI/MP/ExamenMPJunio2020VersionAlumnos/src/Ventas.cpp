/* 
 * File:   Ventas.cpp
 * Author: David Muñoz Sánchez
 * Created on 11 de junio de 2020, 20:58
 */

#include "Ventas.h"
#include <string>
#include <istream>
#include <cassert>

#include <ifstream>

using namespace std;

Ventas::Ventas() {
    numVentas = 0;
    lasVentas = nullptr;
}

// Las indicaciones oportunas al ejercicio 1.2 están explicadas en clientes.cpp

Ventas::~Ventas() {
    liberar_memoria();
}


// Las indicaciones oportunas al ejercicio 1.3 están explicadas en clientes.cpp

Ventas::Ventas(const Ventas& vnts) {
    lasVentas = nullptr;
    copiar(vnts);
}

Ventas& Ventas::operator=(const Ventas& vnts) {
    if (this != &vnts) {
        copiar(vnts);
    }

    return *this;
}

// Ejercicio 2.1

Ventas& Ventas::operator+=(const Venta& vnt) {
    redimensionar(1);
    lasVentas[numVentas - 1] = vnt;

    return *this;
}

// Ejercicio 3.2

std::istream& operator>>(std::istream& flujo, Ventas& vnts) {
    std::string palabra_magica;
    std::string cadena;
    flujo >> palabra_magica;

    if (flujo || !flujo.eof()) {
        while (!flujo.eof()) { // Mientras que no lleguemos al final del fichero
            getline(flujo, cadena);
            Venta aniadir(cadena);
            vnts += aniadir;
        }
    }
    
    else{
        vnts.numVentas = 0;
        vnts.lasVentas = nullptr;
    }


}

// Ejercicio 4.1

Ventas::Ventas(const std::string& fichero) {
    ifstream entrada;
    entrada.open(fichero);
    entrada >> *this;

    entrada.close();
}

// Ejercicio 5

double Ventas::ventaMedia() const {
    double suma_ventas = 0;
    double total_ventas = numVentas / 1.0;
    double media;

    for (int i = 0; i < numVentas; i++) {
        suma_ventas += lasVentas[i].getTotal();
    }

    media = suma_ventas / total_ventas;

    return media;
}

bool operator>(const Ventas &vent1, const Ventas &vent2) {
    if (vent1.ventaMedia() > vent2.ventaMedia())
        return true;

    else
        return false;

}

bool operator==(const Ventas &vent1, const Ventas &vent2) {
    if (vent1.ventaMedia() == vent2.ventaMedia())
        return true;
    else
        return false;
}

void Ventas::liberar_memoria() {
    if (lasVentas != nullptr)
        delete[] lasVentas;

    numVentas = 0;
}

void Ventas::reservar_memoria(int n) {
    liberar_memoria();

    if (n > 0) {
        lasVentas = new Venta[n];
        numVentas = n;
    }
}

void Ventas::copiar(const Ventas& vnts) {
    reservar_memoria(vnts.numVentas);

    for (int i = 0; i < vnts.numVentas; i++)
        lasVentas[i] = vnts.lasVentas[i];
}

void Ventas::redimensionar(int n) {
    if (numVentas + n > 0) {
        Venta *v_ampliado = new Venta[numVentas + n];
        for (int i = 0; (i < numVentas) && (i < numVentas + n); i++)
            v_ampliado[i] = lasVentas[i];
        delete[] lasVentas;
        lasVentas = v_ampliado;
        numVentas = numVentas + n;
    }
}
