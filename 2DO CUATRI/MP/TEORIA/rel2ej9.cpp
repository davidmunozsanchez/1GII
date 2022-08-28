#include <iostream>

using namespace std;

void ordenacionPorBurbuja(int vector[], int* array_p[], int p, int (*compare)(int, int)){
    for (int i = 0; i < p; i++)
        array_p[i] = &vector[i];

    for (int i = p -1; i > 0; --i ){
        for (int j = 0; j<i; ++j){
            if (compare(*array_p[j], *array_p[j+1]) > 0){
                int *aux = &(*array_p[j]);
                array_p[j] = &(*array_p[j+1]);
                array_p[j+1] = aux;
            } 
        }
    }
}

int ordenCreciente(int l, int r){
    return l-r;
}
int ordenDecreciente(int l, int r){
    return r-l;
}
int main(){
    int vec [100];
    int *punt[100];
    int hola;

    cout << "Rellena el vector de enteros: ";
    for (int i = 0; i < 10; i++ ){
        cin >> vec[i];
    }

    ordenacionPorBurbuja(vec, punt, 10, ordenDecreciente);
    
    for (int i =0; i < 10; i++){
        cout << *punt[i] << endl;
    }
}