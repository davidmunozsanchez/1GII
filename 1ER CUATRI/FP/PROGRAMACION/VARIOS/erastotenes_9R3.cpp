/*	Programa para calcular todos los numeros primos hasta un cierto numero dado, usando el algoritmo
	de Erastotenes
*/

#include <iostream>

using namespace std;

int main(){
	// Declaracion de variables
	int numero;
	int i, j;
	
	cout << "Introduce un numero tope para calcular todos los primos hasta el: ";
	cin  >> numero;
	
	int vector_num[numero-2];
	
	// Asignamos valores al vector
	for (i = 0; i < numero; i++)
		vector_num[i] = i + 2;
	
	// Calculo de los numeros primos, si es multiplo, asignamos un 0
	for (i = 0; i < numero; i++){
		for (j = numero - i; j > i; j--){
 			if(vector_num[i] != 0){
 				if (vector_num[j] % vector_num[i] == 0)
				vector_num[j] = 0;
			}
		 		
					
		}
	}
	
	// Mostramos el resultado en pantalla
	for (i = 0; i <= numero-3; i++){
		if (vector_num[i] != 0)
			cout << vector_num[i] << " ";
	}
	
	
}
