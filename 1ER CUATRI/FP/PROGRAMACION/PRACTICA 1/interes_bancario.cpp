/*	Programa para calcular el total de dinero obtenido en un año
	dados el capital y el interes
*/

#include <iostream> // Inclusion de los recursos de E/S

using namespace std;

int main(){				// Programa principal
	double capital;   	// Declaracion de variables
	double interes;   	// (capital e interes)
	
	cout << "Introduzca el capital: " ;			// Se introduce el capital
	cin  >> capital ;							// Se asigna el capital a la variable capital
	cout << "Introduzca el interes: " ;			// Se introduce el interes
	cin  >> interes ;							// Se asigna el interes a la variable interes
	
	capital = capital + capital * (interes / 100) ; 	// Realizamos el calculo del total
														// y lo asignamos a la variable capital
															
	cout << "\nEl total del dinero obtenido en un ano es "<< capital << ".\n\n" ;	// Mostramos al usuario el valor total
	system("pause");		//Pausamos el programa hasta que el usuario quiera finalizarlo
	
}
