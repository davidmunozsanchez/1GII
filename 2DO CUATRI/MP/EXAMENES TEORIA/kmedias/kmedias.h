/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   kmedias.h
 * Author: davidms_83
 *
 * Created on 13 de junio de 2020, 16:50
 */

#ifndef KMEDIAS_H
#define KMEDIAS_H

class KMedias {
private:
    int K;
    Cluster *clusters;
    void reservar_memoria(int n);
    void liberar_memoria();


public:

    KMedias();
    void clearAndSetK(int n);
    Cluster clusterMasCercano(const Punto &p);
    double cohesion();
    friend std::ostream& operator<<(std::ostream& flujo, const KMedias &k);
    friend std::istream& operator>>(std::istream& flujo, KMedias &k);
};





#endif /* KMEDIAS_H */

