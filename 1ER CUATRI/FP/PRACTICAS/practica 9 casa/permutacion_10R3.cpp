
#include <iostream>
using namespace std;

struct Permutacion {
	int vector[100], resultado[100], aux[100];
	int tope;
};
int main() {
	Permutacion vector1, permutacion1;
	int aplicacion[100], aux[100], resultado[100];
	bool correcto;
	int potencia, posicion;
	
	do{
		cout << endl << "Introduce el numero de elementos del vector: ";
		cin >> vector1.tope;
	}while(vector1.tope > 100 || vector1.tope < 1);
	cout << endl << "Introduce los datos del vector: " << endl;
	for(int i = 0; i < vector1.tope; i++){
		cin >> vector1.vector[i];
	}
	
	permutacion1.tope = vector1.tope;
		do{
		cout << endl << "Introduce la permutacion: " << endl;
		for(int i = 0; i < permutacion1.tope; i++){
			cin >> permutacion1.vector[i];
		}
		
		for(int i = 0; i < vector1.tope; i++){
			correcto = false;
			for(int j = 0; j < permutacion1.tope; j++){
				if(permutacion1.vector[j] == vector1.vector[i])
					correcto = true;
			}
			if(!correcto){
				cout << "La permutacion no es correcta";
				}
		}
	}while(!correcto);
	if(correcto)
		cout << endl << "Permutacion correcta" << endl;
		
		
		
	
	for(int i = 0; i < vector1.tope; i++){
		for(int j = 0; j < permutacion1.tope; j++){
			if(vector1.vector[i] == permutacion1.vector[j])
				aplicacion[i] = j;
		}
	}
	
	
	
	do{
		cout << endl << "Introduce el grado de la potencia: ";
		cin >> potencia;
	}while(potencia <= 1);

	
	for(int i = 0; i < permutacion1.tope; i++)
		aux[i] = permutacion1.vector[i];
	for(int i = 0; i < potencia - 1; i++){
		for(int j = 0; j < permutacion1.tope; j++){
			posicion = aplicacion[j];
			resultado[posicion] = aux[j];
		}
		for(int z = 0; z < permutacion1.tope; z++)
			aux[z] = resultado[z]; 
}
	
	cout << endl;
	for(int i = 0; i < permutacion1.tope; i++)
		cout << resultado[i] << " ";
	
}

