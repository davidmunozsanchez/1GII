#include <iostream>

using namespace std;

int main(){
    int *p=0, n; //CONVIENE INICIALIZAR PUNTEROS A 0 o nullptr

    cout << "Numero de casillas: ";
    cin >> n;

    //Reservamos memoria
    p = new int [n];

    for (int i=0; i < n; i++){
        cout << "Valor en casilla " << i << ": ";
        cin  >> v[i];
    }

    cout << endl;

    for (int i = 0; i < n; i++)
        cout << "EN la casilla " << i << " guardo: " <<
            v[i] << endl;

    delete [] p; //No afecta al puntero, solo marcamos como libre la memoria

    p = 0; //Esto es para indicar que v no apunta a ningún sitio;
}