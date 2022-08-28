/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   vectorpuntos.h
 * Author: davidms_83
 *
 * Created on 13 de junio de 2020, 16:25
 */

#ifndef VECTORPUNTOS_H
#define VECTORPUNTOS_H
class VectorPuntos{
    private:
        Punto *puntos;
        int nPuntos;
        int reservados;
        void reservar_memoria(int n);
        void liberar_memoria();
        void copia (const VectorPuntos &v);
        void redimensionar(int* &v, int& tama, int aumento);
    public:
        VectorPuntos();
        VectorPuntos(const VectorPuntos &v);
        VectorPuntos& operator=(const VectorPuntos &v);
        ~VectorPuntos();
        void add(const Punto &p);
        
        Punto& operator[](int i);
        const Punto& operator[] (int i);
    
};


#endif /* VECTORPUNTOS_H */

