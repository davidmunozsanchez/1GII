/* 
 * File:   main.cpp
 * Author: David Muñoz Sánchez
 *
 * Created on 11 de junio de 2020, 19:16
 */

#include <iostream>

#include "Ventas.h"

using namespace std;
void redimensionar(Ventas* &v, int& tama, int aumento);

int main(int argc, char* argv[]) {
    Ventas *ventas = new Ventas[0];
    int tamanio_vector = 0;
    int arg = 1;
    string str_arg;
    Ventas maximo;
    double venta_media;
    int indice;

    // Tratamos los parametros del main, si en la lectura de alguno hubiera algun
    // error, ventas se inicializaría como un objeto vacio
    while (arg < argc) {
        tamanio_vector += 1;

        str_arg = argv[arg];

        Ventas aniadir(str_arg);

        redimensionar(ventas, tamanio_vector, 1);
        ventas[tamanio_vector - 1] = aniadir;

        arg++;
    }

    // Ahora hacemos buscamos cual es el archivo de ventas con mejor venta media
    maximo = ventas[0];
    indice = 0;
    for (int i = 0; i < tamanio_vector; i++) {
        if (ventas[i] > maximo) {
            maximo = ventas[i];
            venta_media = maximo.ventaMedia();
            indice = i;
        }
    }

    cout << "EL valor de la mejor venta media es: " << venta_media << endl;

    // Ahora buscamos los archivos con la misma venta media y los imprimimos en pantalla
    cout << "Los archivos con la misma venta media son: " << endl;
    for (int i = 0; i < tamanio_vector; i++) {
        if (ventas[i] == maximo) {
            cout << argv[i] << endl;
        }
    }

    delete[] ventas;
    return 0;
}

void redimensionar(Ventas* &v, int& tama, int aumento) {
    if (tama + aumento > 0) {
        Ventas *v_ampliado = new Ventas[tama + aumento];
        for (int i = 0; (i < tama) && (i < tama + aumento); i++)
            v_ampliado[i] = v[i];
        delete[] v;
        v = v_ampliado;
        tama = tama + aumento;
    }
}