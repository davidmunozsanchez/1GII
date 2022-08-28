//Programa para a partir de un vector de enteros, se obtengan dos vecctores con los numeros pares y los impares

#include <iostream>
using namespace std; 

const int LONG = 50;
void vector_par( int vector[LONG], int longitud){
	for (int i = 0; i < longitud; i++){
		if (vector[i] % 2 == 0)
			cout << vector[i] << " ";
	}
}

void vector_impar( int vector[LONG], int longitud){
	for (int i = 0; i < longitud; i++){
		if (vector[i] % 2 != 0)
			cout << vector[i] << " ";;
	}
}

int main (){
	int numero[LONG];
	int longitud1;
	
	cout << "Introduce longitud del vector: ";
	cin >> longitud1;
	
	cout << "Introduce vector: ";
	for (int i = 0; i < longitud1; i++)
		cin >> numero[i];

   cout << "\nLos numeros pares del vector son: ";
   vector_par(numero, longitud1);
   
   cout << "\nLos numeros impares del vector son: ";
   vector_impar(numero, longitud1);
}
