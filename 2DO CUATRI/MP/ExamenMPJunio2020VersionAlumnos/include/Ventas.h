/* 
 * File:   Ventas.h
 * Author: David Muñoz Sánchez
 *
 * Created on 11 de junio de 2020, 20:58
 */

#ifndef VENTAS_H
#define VENTAS_H

#include "Venta.h"

class Ventas {
public:
    // Constructor por defecto 1.1
    Ventas();
    
    // Destructor 1.2
    ~Ventas();
    
    // Constructor de copia 1.3
    Ventas(const Ventas &vnts);
    
    Ventas& operator=(const Ventas &vnts);
    
    // Operador += 2.1
    Ventas& operator+=(const Venta &vnt);
    
    // Operador >> 3.2
    friend std::istream& operator>>(std::istream& flujo, Ventas& vnts);
    
    //Constructor 4.1
    Ventas(const std::string &fichero);
    
    // Función para el 5
    double ventaMedia() const;
    friend bool operator> (const Ventas &vent1, const Ventas &vent2);
    friend bool operator==(const Ventas &vent1, const Ventas &vent2);
    
private:
    int numVentas;
    Venta *lasVentas;
    void liberar_memoria();
    void reservar_memoria(int n);
    void copiar(const Ventas &vnts);
    void redimensionar(int n);
};

std::istream& operator>>(std::istream& flujo, Ventas& vnts);
bool operator> (const Ventas &vent1, const Ventas &vent2);
bool operator== (const Ventas &vent1, const Ventas &vent2);

#endif /* VENTAS_H */

