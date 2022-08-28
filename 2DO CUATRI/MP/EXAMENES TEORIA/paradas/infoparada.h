/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   infoparada.h
 * Author: davidms_83
 *
 * Created on 14 de junio de 2020, 10:53
 */

#ifndef INFOPARADA_H
#define INFOPARADA_H

class InfoParada {
    private:
        bool activa;
        int indice_parada;
    public:
        friend istream& operator>>(istream& flujo, InfoParada &parada);


};


#endif /* INFOPARADA_H */

