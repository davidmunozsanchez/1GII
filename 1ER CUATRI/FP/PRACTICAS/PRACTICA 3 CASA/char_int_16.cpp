/*	Programa que obtiene el valor dentero de un número a partir de su valor como caracter.
	Tiene especial importancia que el caracter 0, vale 48, el 1, 49, y asi sucesivamente
*/

#include <iostream>
using namespace std;

int main(){
	char car;		// Declaramos un char y un int
	int numero;
	
	cout << "Introduce el caracter entre 0 y 9 que desee: ";	// Se introduce los datos desde teclado
	cin  >> car ;
	
	numero = car - 48 ;		// Transformamos el valor del caracter a entero, restandole 48
	
	cout << "\nEl numero es: " << numero << ".\n\n" ;
	
	
}
