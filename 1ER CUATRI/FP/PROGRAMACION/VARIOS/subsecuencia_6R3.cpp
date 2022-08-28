/*	Programa para determinar cuantas veces se repite un vector en otro de mayor o igual tamanio,
	aportando las posiciones en la que se empieza a repetir
*/

#include <iostream>

using namespace std;

int main(){
	
	// Declaracion de variables
	int i, j = 0;
	int capacidad1, capacidad2;
	int contador_apariciones;
	int valor1, valor2, maximo_apariciones, posicion;
	bool una_vez = true;
	
	// Filtamos la entrada para que la capacidad del vector 2 sea adecuada
	do{
		cout << "Introduce la capacidad del vector 1: ";
		cin >> capacidad1;
		cout << "Introduce la capacidad del vector 2: ";
		cin >> capacidad2;
	} while (capacidad1 < capacidad2);

	// Creamos y rellenamos ambos vectores
	int vector1 [capacidad1], vector2 [capacidad2];
	
	cout  << "Introduce los valores para el vector 1: ";
	
	for (i = 0; i < capacidad1; i++){
		cin >> valor1;
		
		vector1 [i] = valor1;
	}
	
	cout << "Introduce los valores para el vector 2: ";
	
	for (j = 0; j < capacidad2; j++){
		cin >> valor2;
		
		vector2 [j] = valor2;
	}
	
	// Realizamos las operaciones para calcular las apariciones
	for (i = 0; i < capacidad1; i++){
		for (j = 0; j < capacidad2; j++){
			if (vector1[i] == vector2[j]){
				contador_apariciones += 1;
				if (una_vez)
					posicion = i;
					una_vez = false;
			}
		}
		
		if (contador_apariciones % capacidad2 == 0){
			maximo_apariciones = contador_apariciones / capacidad2;
			una_vez = true;
			
			cout << "En la posicion " << posicion << "\n";
		}
			
	}	
		
		cout << "Se repite el vector 2, que aparece " << maximo_apariciones << " vece(s)";	
	}
	
	
	
	
	
	

