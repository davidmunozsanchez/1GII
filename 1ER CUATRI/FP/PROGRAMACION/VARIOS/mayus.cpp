/*	Programa para eliminar las mayusculas de un vector utilizando dos bucles anidados
*/

#include <iostream>

using namespace std;

int main(){
	
	// Declaracion de variables
	int tamanio, elemento;
	int i;
	int posicion = 0;
	
	cout << "Introducir numero de componentes del vector: ";
    cin >> tamanio;
    
    // Creamos y asignamos valores al vector
    char vector1[tamanio];
	
	cout << "Introducir vector: ";
	for (int i = 0 ; i < tamanio ; i++)
		cin >> vector1[i];
    
    // Eliminamos las mayusculas
    while (posicion <= tamanio ){
        if (vector1[posicion] >= 'A' && vector1[posicion] <= 'Z' ){
            for (i = posicion; i < tamanio - 1; i++)
                vector1[i] = vector1[i + 1];
            tamanio--;
        }
        else
            posicion++;
    }
	
	// Mostramos el vector
    cout << "\nEl vector queda: ";
	for (i = 0; i < tamanio; i++)
		cout << vector1[i] << " ";
    cout << "\n";
}
	

