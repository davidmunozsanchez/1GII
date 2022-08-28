/* Programa para calcular el area del circulo y la longitud de la circunferencia
	dado el radio. Nos ayudaremos de las formulas: 
	area = pi * radio^2
	longitud = 2 * pi * radio
*/

#include <iostream>		// Inclusion de los recursos de E/S
#include <cmath>		// Inclusion de los recursos matematicos

using namespace std;

int main(){							// Programa principal
	const double PI = 3.1416 ; 		// Declaracion de una constante con el valor de PI 
	double radio ;					// Declaracion de varias variables
	double area ;					// para guardar el radio, el area y la longitud
	double longitud ;
	
	cout << "Introduce la longitud del radio: " ;	// Se introduce el radio
	cin  >> radio ;									// y se asigna a la variable radio
	
	area = PI * pow (radio, 2) ;		// Calculamos el area mediante su expresion
	longitud = 2 * PI * radio ;			// Calculamos la longitud de la circunferencia
	
	cout << "\nEl area del circulo es " << area <<" y la longitud de la circunferencia es " << longitud << ".\n\n" ;		// Mostramos los datos en pantalla
	system("pause");		//Añadimos una pausa para que el programa finalice cuando lo desee el usuario
	
}
	
