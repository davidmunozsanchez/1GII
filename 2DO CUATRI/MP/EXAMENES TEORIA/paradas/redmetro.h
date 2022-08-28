/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   redmetro.h
 * Author: davidms_83
 *
 * Created on 14 de junio de 2020, 10:52
 */

#ifndef REDMETRO_H
#define REDMETRO_H

#include "linea.h"
#include <string>

class RedMetro {
    private:
        int num_lineas;
        Linea *lineas;
        void liberar_memoria();
        void reservar_memoria(int n);
        void copiar(const RedMetro &rm);
        double valorCalidad()const;
    public:
        RedMetro();
        RedMetro(const RedMetro &rm);
        ~RedMetro();
        RedMetro(const std::string &fichero);
        bool EstaVacia();
        inline int GetNumLineas()const{
            return num_lineas;
        }
        
        RedMetro& operator=(const RedMetro &rm);
        
        bool operator==(const RedMetro &rm) const;
        bool operator!=(const RedMetro &rm) const;
        bool operator>(const RedMetro &rm) const;
        
        int MejorConectada()const;
        
        friend std::ostream& operator<<(std::ostream& flujo, const RedMetro &rm);
        friend std::istream& operator>>(std::istream& flujo, RedMetro &rm);
    

};


#endif /* REDMETRO_H */

