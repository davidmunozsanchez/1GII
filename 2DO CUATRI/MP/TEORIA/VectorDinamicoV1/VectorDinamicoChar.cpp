/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "VectorDinamicoChar.h"

void inicializar(VectorDinamicoChar &array){
    array.arrayChar = 0;
    array.nCaracteres = 0;
}

void liberar(VectorDinamicoChar &array){ //IMPORTANTE LIBERAR MEMORIA DINAMICA CUANDO YA NO SE NECESITA
    if(array.arrayChar != 0){
        delete[] array.arrayChar;
        inicializar(array);
    }    
}

void redimensionar(VectorDinamicoChar &array, int aumento){
    if(array.nCaracteres + aumento > 0){
        char *array_ampliado = new char [array.nCaracteres+aumento];
        
        for (int i= 0; (i < array.nCaracteres) && (i<array.nCaracteres+aumento);i++)
            array_ampliado[i] = array.arrayChar[i];
        delete[] array.arrayChar;
        array.arrayChar = array_ampliado;
        array.nCaracteres += aumento;
    }
}

void aniadir(VectorDinamicoChar &array, char aniade){
    redimensionar(array, 1);
    array.arrayChar[array.nCaracteres-1] = aniade;
}

void leer(istream& flujo, VectorDinamicoChar &array){
    char caracter;
    while(flujo.get(caracter)){
        aniadir(array, caracter);
    }
}

void mostrar(ostream& salida, const VectorDinamicoChar &array){
    for(int i = 0; i < array.nCaracteres; i++){
        salida << array.arrayChar[i] << " ";
    }
}
