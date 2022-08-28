/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "VectorDinamicoChar.h"

void inicializar(char* &array, int &nchar){
    array = 0;
    nchar = 0;
}

void liberar(char* &array, int &nchar){ //IMPORTANTE LIBERAR MEMORIA DINAMICA CUANDO YA NO SE NECESITA
    if(array != 0){
        delete[] array;
        inicializar(array,nchar);
    }    
}

void redimensionar(char* &array, int &nchar, int aumento){
    if(nchar + aumento > 0){
        char *array_ampliado = new char [nchar+aumento];
        
        for (int i= 0; (i < nchar) && (i<nchar+aumento);i++)
            array_ampliado[i] = array[i];
        delete[] array;
        array = array_ampliado;
        nchar += aumento;
    }
}

void aniadir(char* &array, int &nchar, char aniade){
    redimensionar(array, nchar, 1);
    array[nchar-1] = aniade;
}

void leer(istream& flujo, char*&array, int& nchar){
    char caracter;
    while(flujo.get(caracter)){
        aniadir(array, nchar, caracter);
    }
}

void mostrar(ostream& salida,char* array,int nchar){
    for(int i = 0; i < nchar; i++){
        salida << array[i] << " ";
    }
}
