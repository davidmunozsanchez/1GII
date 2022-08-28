/* 
 * File:   Clientes.cpp
 * Author: David Muñoz Sánchez
 * 
 * Created on 11 de junio de 2020, 19:20
 */

#include "Clientes.h"
#include "Cliente.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Constructor por defecto 1.1

Clientes::Clientes() {
    numClientes = 0;
    losClientes = nullptr;
}

// Destructor 1.2
// Solo sería necesario implementar el destructor en las clases Clientes y Ventas
// que son las que usan memoria dinámica. En las clases restantes, nos bastaría con
// el destructor por defecto

Clientes::~Clientes() {
    liberar_memoria();
}

// Cosntructor de copia 1.3
// De forma similar al destructor, solo será necesario implementar constructores de copia
// para las clases clientes y ventas, que son las que usan memoria dinámica

Clientes::CLientes(const Clientes& cls) {
    losClientes = nullptr;
    copiar(cls);
}

// Operador de asignacion 1.3
// Como sucede en apartados anteriores, solo será necesario implementar el operador 
// de asignación para clientes y ventas, puesto que el operador de asignacion por defecto
// funciona correctamente para las clases cliente y venta, al no contener ni punteros ni memoria 
// dinámica

Clientes& Clientes::operator=(const Clientes& cls) {
    if (this != &cls) {
        copiar(cls);
    }

    return *this;
}

Clientes& Clientes::operator+=(const Cliente& cl) {
    
    bool repetido = false;
    
    for (int i = 0; i < getNumeroClientes() && !repetido; i++) {
        if (losClientes[i].getNIF() == cl.getNIF())
            repetido = true;
    }
    
    if (!repetido){
        redimensionar(1);
        losClientes[getNumeroClientes() - 1] = cl;
    }
    return *this;
}

//Aunque lo recomendable es implementarlo como función externa, como vamos a sumar
// dos objetos de la misma clase, no supondría ningún problema hacerlo como función
// miembro
Clientes Clientes::operator +(const Clientes& cls){
    Clientes a_devolver(*this);
    bool iguales = false;
    for (int i = 0; i < cls.getNumeroClientes(); i++){
        for (int j = 0; j < a_devolver.getNumeroClientes(); j++){
            if (cls[i].getNIF() == a_devolver[j].getNIF()) 
                iguales = true;
            
        }
        
        if (!iguales){
            a_devolver.redimensionar(1);
            a_devolver += cls[i];
        }
        else
            iguales = false;
    }
    
    return a_devolver;
}

// Ejercicio 3.1
std::ostream& operator<<(std::ostream& flujo, const Clientes& cls){
    flujo << "FICHEROCLIENTES" << endl;
    
    for (int i = 0; i < cls.getNumeroClientes(); i++){
        flujo << cls[i].toString() << endl;
    }
    
    return flujo;
}

// Ejercicio 4.2
void Clientes::escribirClientes(const string &nombre) const{
    ofstream salida;
    salida.open(nombre);
    
    salida << *this;
    
    salida.close();
}

Cliente& Clientes::operator[](int n) {
    return losClientes[n];

}

const Cliente& Clientes::operator[](int n) const {
    return losClientes[n];
}

int Clientes::getNumeroClientes() const {
    return numClientes;
}

void Clientes::liberar_memoria() {
    if (losClientes != nullptr)
        delete[] losClientes;

    numClientes = 0;
}

void Clientes::reservar_memoria(int n) {
    liberar_memoria();
    if (n > 0) {
        losClientes = new Cliente[n];
        numClientes = n;
    }
}

void Clientes::copiar(const Clientes& cl) {
    reservar_memoria(cl.getNumeroClientes());

    for (int i = 0; i < cl.getNumeroClientes(); i++) {
        losClientes[i] = cl[i]; //Hacemos uso del operador de indexacion que se nos proporciona
    }
}

void Clientes::redimensionar(int n) {
    int clientes = getNumeroClientes();
    if (clientes + n > 0) {
        Cliente *v_ampliado = new Cliente[clientes + n];
        for (int i = 0; (i < clientes) && (i < clientes + n); i++)
            v_ampliado[i] = losClientes[i];
        delete[] losClientes;
        losClientes = v_ampliado;
        numClientes = clientes + n;
    }
}