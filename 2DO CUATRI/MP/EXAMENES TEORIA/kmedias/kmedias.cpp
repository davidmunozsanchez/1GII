/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "kmedias.h"
#include "cluster.h"

KMedias::KMedias() {
    reservar_memoria(2);
}

void KMedias::reservar_memoria(int n) {
    liberar_memoria();
    if (n > 0) {
        clusters = new Cluster[n];
        K = n;
    }
}

void KMedias::liberar_memoria() {
    delete[] clusters;
    K = 0;
    clusters = nullptr;
}

void KMedias::clearAndSetK(int n) {
    if (n > 0) {
        reservar_memoria(n);
    }
}

Cluster KMedias::clusterMasCercano(const Punto& p) {
    int minimo;
    double distancia_minima;
    double distancia;
    bool primera = true;

    for (int i = 0; i < K; i++) {
        distancia = clusters[i].calcularCentroide().getDistancia(p);
        if (primera) {
            distancia_minima = distancia;
            minimo = i;
            primera = false;
        }
        else {
            if (distancia < distancia_minima) {
                distancia_minima = distancia;
                minimo = i;
            }
        }

    }

    return clusters[minimo];
}

double KMedias::cohesion() {
    // Para calcular las combinaciones posibles hacemos uso de combinacinoes sin repeticion, udespués sería un bucle normal

}

std::ostream& operator<<(std::ostream& flujo, const KMedias &k){
    flujo << k.K << endl;
    
    for (int i = 0; i < k.K; i++){
        flujo << k.clusters[i] << endl;
    }
    
    return flujo;
}

std::istream& operator>>(std::istream& flujo, KMedias &k){
    int grupos;
    
    flujo >> grupos;
    k.clearAndSetK(grupos);
    
    for (int i = 0; i < grupos; i++){
        flujo >> k.clusters;
    }
}
