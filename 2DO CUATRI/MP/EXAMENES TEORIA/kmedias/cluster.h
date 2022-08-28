/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cluster.h
 * Author: davidms_83
 *
 * Created on 13 de junio de 2020, 16:49
 */

#ifndef CLUSTER_H
#define CLUSTER_H
class Cluster{
private:
    Punto centroide;
    VectorPuntos puntos;
public:
    Punto calcularCentroide();
    friend std::ostream& operator<<(std::ostream& flujo, const Cluster &c);
    friend std::istream& operator>>(std::istream& flujo, Cluster &c);
};


#endif /* CLUSTER_H */
