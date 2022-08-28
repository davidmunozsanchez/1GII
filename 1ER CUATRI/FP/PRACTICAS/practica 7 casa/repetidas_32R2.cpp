/*	Programa para calcular cuantas veces se repite una cifra en los numeros de un
	intervalo cerrado de numeros enteros, ya sean positivos o negativos
*/

#include <iostream>

using namespace std;

int main(){
	
	// Declaracion de variables
	int numero1, numero2, numero_aux, cifra, cifra_aux, contador_cifra = 0;
	int i;
	bool bucle;
	
	do {
		cout << "Introduce dos numeros enteros (separados por espacios): ";
		cin  >> numero1 >> numero2;	
	} while (numero2 <= 0);
	
	
	// Controlamos la introduccion de una cifra que este enter 0 y 9, ambos inclusive
	do {
		cout << "Introduce una cifra entre 0 y 9: ";
		cin  >> cifra;
	} while (cifra < 0 || cifra > 9);
	
	// Buecle principal, para ir cambiando de numero en el intervalo
	for (i = numero1; i <= numero2; i++){
		
		bucle = true;
		numero_aux = i;
		
		/* 	Bucle secundario, para descomponer cada numero en cifras
			y comparar con la cifra introducida por el usuario
		*/
		while (bucle){
			
			// Distinguimos dos condicionales para ver si es negativo o positivo el entero en cuestion
			if (numero_aux >= 0){
				cifra_aux = numero_aux % 10;
			}
			
			if (numero_aux < 0){
				cifra_aux = (-1)*numero_aux % 10;
			}
			
			if (cifra_aux == cifra)
				contador_cifra += 1;
				
			numero_aux /= 10;
			
			if (numero_aux == 0)
				bucle = false;
		}
		
		
	}
	
	cout << contador_cifra;
	
	
	
	
}
