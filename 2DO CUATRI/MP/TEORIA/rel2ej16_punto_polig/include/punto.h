/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Punto.h
 * Author: davidms_83
 *
 * Created on 25 de abril de 2020, 18:15
 */

#ifndef PUNTO_H
#define PUNTO_H

class Punto{
    double x;
    double y;
    
public:
    inline Punto(){x=0; y=0;}
    inline Punto(double x, double y){this->x=x; this->y=y;}
    inline double getX() const{return x;}
    inline double getY() const{return y;}
    inline void setXY(double x, double y){this->x=x; this->y=y;}
};

#endif /* PUNTO_H */

