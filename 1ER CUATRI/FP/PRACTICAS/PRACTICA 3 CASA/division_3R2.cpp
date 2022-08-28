/* Programa para comprobar si dos numeros se pueden dividir de forma entera entre sí
*/

#include <iostream>

using namespace std;

int main(){
	int num1, num2;		// Declaracion de variables
	
	cout << "Introduzca los numeros separados por un espacio: ";		// Introduccion de valores desde teclado
	cin  >> num1 >> num2 ;
	
	if (num1 % num2 == 0 || num2 % num1 == 0){		// Si el resto de alguna division da 0, es que se dividen de forma entera
		
		cout << "Uno de los dos divide de forma entera al otro.";
	}
	else {
		cout << "No dividen de forma entera ninguno de los dos.";
	}
	
}

