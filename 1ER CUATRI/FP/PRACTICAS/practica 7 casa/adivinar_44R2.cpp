#include <iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

int main (){
	
	int limite_inf, limite_superior;
	int numero, numero_int, numero_a_comparar;
	bool seguir_partida, acertado;
	char eleccion;
	
	srand(time(NULL));
	acertado = false;
	seguir_partida = true;
	
	while (seguir_partida){
		cout << "Introduce un limite inferior y un limite superior para jugar a adivinar el numero: ";
		cin  >> limite_inf >> limite_superior;
		
		numero = limite_inf + rand() % (limite_superior + 1 - limite_inf);
		
		while (!acertado){
		
			cout << "\nIntroduce un numero, para probar suerte (introduce un valor fuera de rango para salirte):\n";
			cin  >> numero_int;
			
			if (numero_int <= limite_superior && numero_int >= limite_inf){
				
				if (numero_a_comparar > numero)
				cout << "\nEl numero que buscas es menor\n";
				
				else if (numero_a_comparar < numero)
					cout << "\nEl numero que buscas es mayor\n";
				
				else if (numero_a_comparar == numero){
					cout << "\nHas acertado!\n";
					acertado = true;
				}
				
			}
			
			else {
				acertado = true;
			}
			
		}
			
		cout << "\n\nQuiere seguir jugando (S/n)?\n";
		cin  >> eleccion;
		
		switch (eleccion){
			case 'S':
				acertado = false;
				
				break;
				
			case 'n':
				seguir_partida = false;
				
				break;
		}
	}
	
		
}
