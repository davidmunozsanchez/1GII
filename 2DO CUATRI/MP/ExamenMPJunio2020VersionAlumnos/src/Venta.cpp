/* 
 * File:   Venta.cpp
 * Author: David Muñoz Sánchez
 * 
 * Created on 11 de junio de 2020, 20:57
 */

#include <sstream>
#include <string>

#include "Venta.h"

using namespace std;

// 1.1
// En este caso, al tener un constructor con un parámetro string, sí que sería
// necesario implementar un constructor por defecto, puesto que el compilador
// usará el que se nos ha proporcionado como el constructor por defecto
Venta::Venta(){
    idCliente = 0;
    idProducto = 0;
    total = 0;
    
}
Venta::Venta(const std::string &linea) {
    istringstream flujodeString;
    if (linea.size() > 0) {
        flujodeString.str(linea);
        flujodeString >> idCliente;
        flujodeString >> idProducto;
        flujodeString >> total;
    } else {
        idCliente = 0;
        idProducto = 0;
        total = 0;
    }
}

int Venta::getIdCliente() const {
    return idCliente;
}

int Venta::getIdProducto() const {
    return idProducto;
}

double Venta::getTotal() const {
    return total;
}
