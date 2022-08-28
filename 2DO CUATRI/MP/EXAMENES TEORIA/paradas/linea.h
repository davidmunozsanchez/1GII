/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   linea.h
 * Author: davidms_83
 *
 * Created on 14 de junio de 2020, 10:53
 */

#ifndef LINEA_H
#define LINEA_H
class Linea{
    private:
        int num_paradas;
        InfoParada * paradas;
        void redimensionar(int aumento);
        
    public:
        Linea& operator+=(const InfoParada &parada);
        bool EstaTotalmenteOperativa() const;
        
        friend istream& operator>>(istream& flujo, Linea &linea);
};


#endif /* LINEA_H */

