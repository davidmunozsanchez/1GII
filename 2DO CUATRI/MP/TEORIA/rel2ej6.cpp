#include <iostream>

using namespace std;

void rellenarArray(int tam, int v[]){
    cout << "Introduce los elementos de tu array: ";
    for (int i=0; i<tam; i++)
        cin >> v[i];
}

int main(){
    int v[10];
    int *maximo, *minimo;
    int *p = v;

    rellenarArray(10, v);
    maximo = &(v[0]);
    minimo = &(v[0]);
    for (int i=0; i<10; i++){
        if (*p >= *maximo)
            maximo = &(*p);

        if (*p <= *minimo){
            minimo = &(*p);
        }
        p++;
    }

    cout << "El maximo es: " << *maximo <<", y el minimo es: "
        << *minimo << endl;
}