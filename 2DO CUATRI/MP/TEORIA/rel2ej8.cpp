#include <iostream>

using namespace std;

void ordenacionPorBurbuja(int vector[], int* array_p[], int p){
    for (int i = 0; i < p; i++)
        array_p[i] = &vector[i];
    for (int i = p -1; i > 0; --i ){
        for (int j = 0; j<i; ++j){
            if (*array_p[j] > *array_p[j+1]){
                int *aux = &(*array_p[j]);
                array_p[j] = &(*array_p[j+1]);
                array_p[j+1] = aux;
            } 
        }
    }
}

void ordenacionPorBurbujaMitad(int vector[], int* array_p[], int p){
    for (int i = 0; i < p/2; i++)
        array_p[i] = &vector[i + p/2];
    for (int i = p/2 - 1; i > 0; --i ){
        for (int j = 0; j<i; ++j){
            if (*array_p[j] > *array_p[j+1]){
                int *aux = &(*array_p[j]);
                array_p[j] = &(*array_p[j+1]);
                array_p[j+1] = aux;
            } 
        }
    }
}

int main(){
    int vec [100];
    int *punt[100];
    int hola;

    cout << "Rellena el vector de enteros: ";
    for (int i = 0; i < 10; i++ ){
        cin >> vec[i];
    }

    ordenacionPorBurbujaMitad(vec, punt, 10);
    
    for (int i =0; i < 5; i++){
        cout << *punt[i] << endl;
    }
}