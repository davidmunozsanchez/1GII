/* 
 * File:   Cliente.cpp
 * Author: David Muñoz Sánchez
 * 
 * Created on 11 de junio de 2020, 19:17
 */
#include <string>
#include <iostream>

#include "Cliente.h"

using namespace std;

// 1.1 Este sería el unico caso donde no hay que hacer constructor por defecto, puesto
// que no hay otros constructores ni usamos memoria dinámica
int Cliente::getIdCliente() const{
    return idCliente;
}

double Cliente::getDescuento() const{
    return descuento;
}

std::string Cliente::getNombre() const{
    return nombre;
}

string Cliente::getNIF() const {
    return NIF;
}

std::string Cliente::toString() const {
    string cadena = to_string(idCliente) + " " + to_string(descuento) + " " + 
            nombre + " " + NIF;
    return cadena;
}