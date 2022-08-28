/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Matriz.h
 * Author: davidms_83
 *
 * Created on 31 de marzo de 2020, 15:45
 */

#ifndef MATRIZ_H
#define MATRIZ_H

class Matriz {
public:
    Matriz(int nf, int nc);
    int get(int fila, int col) const;
    void set(int fila, int col, int dato);
    void Destruir();
private:
    int **matriz;
    int nfil, ncol;
};

#endif /* MATRIZ_H */

