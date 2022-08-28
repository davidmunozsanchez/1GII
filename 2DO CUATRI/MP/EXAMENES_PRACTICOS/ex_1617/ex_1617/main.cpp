/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: davidms_83
 *
 * Created on 26 de abril de 2020, 17:04
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define ERROR_ARG 1
#define ERROR_APER 2
#define ERROR_DATOS 3



void errorCall(int codigo);

void leer(istream &flujo, string* &v, int &tamanio);

void redimensionar(string* &v, int& tama, int aumento);

void eliminar(string* &v, int p, int &tamanio);

void comparar (string* &v1, string* &v2, int &tam1, int &tam2);


int main(int nargs, char* args[]) {
    string *puntero_a = 0, *puntero_b = 0;
    string *puntero_final = 0;
    string fichero1, fichero2;
    ifstream entrada1, entrada2;
    istream *input1, *input2;

    int tamanio1 = 0,
            tamanio2 = 0,
            tamanio_final = 0;
   

    // Vamos a recorrer los argumentos del main, en busca de los dos ficheros de texto
    if (nargs != 3)
        errorCall(ERROR_ARG);
    else {
        fichero1 = args[1];
        fichero2 = args[2];
    }
    //Una vez que tengo los dos ficheros procedo a leerlos
    entrada1.open(fichero1);
    entrada2.open(fichero2);

    input1 = &entrada1;
    input2 = &entrada2;

    leer(*input1, puntero_a, tamanio1);
    leer(*input2, puntero_b, tamanio2);

    //Ahora procedemos  a marcar los repetidos en el más pequeño de los strings
    
    comparar(puntero_a, puntero_b, tamanio1, tamanio2);
       
    puntero_final = new string [tamanio1 + tamanio2];
    
    for (int i = 0; i < tamanio1; i++){
        puntero_final[i] = puntero_a[i];
    }
    for (int i = tamanio1; i < tamanio2+tamanio1; i++){
        puntero_final[i] = puntero_b[i-tamanio1];
    }
    
    for (int i = 0; i < tamanio1 + tamanio2; i++)
        cout << puntero_final[i] << " ";
    
    cout << endl;
    
    delete[] puntero_a;
    delete[] puntero_b;
    delete[] puntero_final;
   
    
}

void errorCall(int codigo) {
    switch (codigo) {
        case ERROR_ARG:
            cerr << "Error en la llamada. Por favor, introduce dos arhivos de texto." << endl;
            break;

        case ERROR_APER:
            cerr << "Error abriendo el archivo." << endl;
            break;

        case ERROR_DATOS:
            cerr << "Error da datos en una de los archivos." << endl;
            break;
    }

    std::exit(1);
}

void redimensionar(string* &v, int &tama, int aumento) {
    if (v != 0) {
        if (tama + aumento > 0) {
            string *v_ampliado = new string[tama + aumento];
            for (int i = 0; (i < tama) && (i < tama + aumento); i++)
                v_ampliado[i] = v[i];
            delete[] v;
            v = v_ampliado;
            tama = tama + aumento;
        
        }
    }
    
}

void leer(istream &flujo, string* &v, int &tamanio) {
    int longitud;
    string palabra;
    flujo >> tamanio;
    
    v = new string[tamanio];
    
    for (int i = 0; i < tamanio; i++) {
        flujo >> palabra;
        v[i] = palabra;
    }
}

void comparar (string* &v1, string* &v2, int &tam1, int &tam2){
    if (tam1 - tam2 >= 0){
        for (int i = 0; i < tam2; i++){
            for (int j = 0; j < tam1; j++){
                if (v2[i] == v1[j]){
                    eliminar(v1, j, tam1);
                }          
            }
        }
    }
    
    else{
        for (int i = 0; i < tam1; i++){
            for (int j = 0; j < tam2; j++){
                if (v1[i] == v2[j]){
                    eliminar(v2, j , tam2);
                }          
            }
        }
    }    
 }


void eliminar(string* &v, int p, int &tamanio){
    if (p >= 0 && p < tamanio){
        for (int i = p; i < tamanio - 1; i++)
            v[i] = v[i+1];
    }
    
    redimensionar(v,tamanio,-1);
}



