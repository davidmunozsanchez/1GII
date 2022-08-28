/*	Programa para intercambiar una variable de un vector con la variable de otro vector
	correspondiente a la misma posicion
*/

#include <iostream>

using namespace std;

int main(){
	
	// Declaracion de variables y del tamanio del vector a modo de prueba
	int vector1 [5];
	int vector2 [5];
	int i, posicion1, posicion2, copia, copia2;
	
	// Introducimos los elementos en el vector
	for (i = 0; i < 5; i++){
		cout << "Introduce los enteros del vector 1: ";
		cin >> vector1 [i];
		cout << "Introduce los enteros del vector 2: ";
		cin >> vector2 [i];
	}
	
	cout << "Introduce las posiciones que desea intercambiar";
	cin >> posicion1 >> posicion2;
	
	// Intercambiamos las posiciones
	copia = vector1[posicion1];
	copia2 = vector2[posicion2];
	vector1[posicion1] = copia2;
	vector2[posicion2] = copia;
	
	cout << vector1[posicion1]<< "\n" << vector2[posicion2];
}
