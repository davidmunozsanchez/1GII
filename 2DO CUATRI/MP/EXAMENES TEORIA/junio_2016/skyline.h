/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   skyline.h
 * Author: davidms_83
 *
 * Created on 14 de junio de 2020, 15:54
 */

#ifndef SKYLINE_H
#define SKYLINE_H
class SkyLine{
    double *abscisas;
    double *alturas;
    int n;
    void liberar_memoria();
    void reservar_memoria(int n);
    void copia(const SkyLine &sk);
    
    public:
        SkyLine();
        ~SkyLine();
        SkyLine(double ab1, double ab2, double alt);
        SkyLine(const SkyLine &sk);
        SkyLine operator =(const SkyLine& sk);
        double Altura(int ab);
};


#endif /* SKYLINE_H */

