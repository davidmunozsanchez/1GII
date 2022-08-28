/*	Programa para ver cuantas subsecuencias ascendentes hay en un vector introducido
*/

#include <iostream>

using namespace std;

int main (){
	
	// Declaracion de variables
	int numero_elem, contador_sub;
	int i;
	int minimo, num_sub = 0;
	
	cout << "Introduce el numero de elementos que tendra tu vector: ";
	cin  >> numero_elem;
	
	// Declaracion del vector e introduccion de los elementos
	int secuencia [numero_elem];
	
	cout << "Introduce los elementos de tu vector: ";
	
	for (i= 0; i< numero_elem; i++)
		cin >> secuencia [i];
	
	// Realizamos la comparacion 1 a 1 de los elementos del vector
	minimo = secuencia [0];
	
	for (i = 0; i < numero_elem; i++){
		if (secuencia[i] != secuencia [i + 1]){
			if (secuencia[i] <= minimo){
				minimo = secuencia [i];
				num_sub += 1;
			}
		}
			
	}
	
	cout << "Hay " << num_sub << " subsecuencia(s) ascendente(s)";
	
	
}
