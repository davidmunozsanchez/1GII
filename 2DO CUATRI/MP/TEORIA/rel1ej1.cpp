#include <iostream>
using namespace std;

void generarArray(int array[], int util, int min, int max){
    for (int i = 0; i < util, i++)
        array[i] = uniforme(min, max); //La copiamos del programa que nos dan

}

void imprimirArray(const int array[], int util){
    cout << util << endl;
    
    for (int i = 0; i < util; i++)
        cout << array[i] << " ";

    cout << endl;
}

int main(){
    int array[100], util_array = 100;
    int n, minimo, maximo;

    cin >> n;
    cout << "Minimo: ";
    cin >> minimo;
    cout << "Maximo: ";
    cin >> maximo;

    generarArray(array, util_array, minimo, maximo);

    imprimirArray(array, util_array);


}

¿Olvidaste tu contraseña?¿Olvidaste tu contraseña?¿Olvidaste tu contraseña?