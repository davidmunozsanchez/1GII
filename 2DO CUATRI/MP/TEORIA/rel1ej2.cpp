#include <iostream>
using namespace std;

void leerArray(int array[], int dim, int util){
    for(int i = 0; i < util; i++)
        cin >> array[i];
}

int buscarMinimo(const int array[], int ini, int fin){
    int pos = ini;
    min = array [ini];

    for (int i = ini + 1; i <= fin; i++){
        if (array[i] < min){ //min se puede elminar y usar array[pos]
            pos = i;
            min = array[i];
        }
    }
    return pos;
}

void imprimirArray(const int array[], int util){
    cout << util << endl;
    
    for (int i = 0; i < util; i++)
        cout << array[i] << " ";

    cout << endl;
}

int main(){
    int array[100], util_array = 100;
    int n, pos_min;

    cout << "Numero de elementos: ";
    cin >> n;

    leerArray(array, util_array, 10);

    pos_min = buscarMinimo (array, 0, 9);

    imprimirArray(array, 10);

    cout << "Minimo: " << array[pos_min] << endl;


}