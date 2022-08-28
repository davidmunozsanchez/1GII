/* 
 * File:   Clientes.h
 * Author: David Muñoz Sánchez
 *
 * Created on 11 de junio de 2020, 19:20
 */

#ifndef CLIENTES_H
#define CLIENTES_H

#include "Cliente.h"

class Clientes {
public:
    
    // Constructor por defecto 1.1
    Clientes();
    /**
     * Versión de devolución por referencia del operador de acceso a un elemento 
     * de la colección de clientes
     * @param n el número de elemento al que se quiere acceder
     * @return el elemento que hay en la posición n (comienza desde la posición 0)
     */
    
    // Destructor 1.2
    ~Clientes();
    
    // Constructor de copia 1.3
    CLientes(const Clientes &cls);
    
    // Operador de asignacion 1.3
    Clientes& operator=(const Clientes &cls);
    
    // Operador += 2.1
    
    Clientes& operator +=(const Cliente &cl);
    
    // Operador + 2.2
    Clientes operator+(const Clientes &cls);
    
    // Operador << 3.1
    friend std::ostream& operator<<(std::ostream& flujo, const Clientes& cls);
    
    Cliente& operator[](int n);
    
    /**
     * Versión de devolución por referencia constante del operador de acceso 
     * a un elemento de la colección de clientes
     * @param n el número de elemento al que se quiere acceder
     * @return el elemento que hay en la posición n (comienza desde la posición 0)
     */
    const Cliente& operator[](int n) const;
    
    /**
     * Devuelve el número de clientes en la colección
     * @return el número de clientes en la colección
     */
    int getNumeroClientes() const;
    
    // 4.2
    void escribirClientes(const std:::string &nombre) const;
    
private:
    int numClientes;
    Cliente *losClientes;
    void liberar_memoria();
    void reservar_memoria(int n);
    void copiar(const Clientes &cl); //1.3
    void redimensionar(int n);
};

std::ostream& operator<<(std::ostream& flujo, const Clientes& cls);
#endif /* CLIENTES_H */

