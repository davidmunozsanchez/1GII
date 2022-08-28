/*	Programa para practicar la asignación de datos a las variables
	partiendo del error que supone hacer a = b y posteriormente b = a
	dado que los valores no se intercambian sino que a y b tendrán el valor de b
*/

#include <iostream>		// Inclusion de los recursos de E/S

using namespace std ;

int main(){

	int edad_Pedro ;	// Declaramos dos variables donde almacenaremos
	int edad_Juan ;		// las edades iniciales de Pedro y Juan
	int intercambio;	// Declaramos una variable auxiliar con el fin de poder intercambiar las variables
	
	
	cout << "Introduzca la edad de Pedro: " ;	// Se introduce la edad de Pedro
	cin  >> edad_Pedro ;						// Y se asigna a la varibale edad_Pedro
	cout << "Introduzca la edad de Juan: " ;	// Se introduce la edad de Juan
	cin  >> edad_Juan;							// Y se asigna a la variable edad_Juan
	
	intercambio = edad_Juan ;	// Asignamos la variable edad_Juan a intercambio
	edad_Juan = edad_Pedro ;	// Realizamos el primer cambio al asignar a edad_Juan el valor de edad_Pedro
	edad_Pedro = intercambio ;	// A edad_Pedro le asignamos el valor de intercambio (edad de Juan)
	
	cout << "\nLa edad de Pedro es " << edad_Pedro << " ano(s) y la de Juan " << edad_Juan << " ano(s).\n\n" ;	// Mostramos el mensaje con las variables cambiadas
	system("pause") ; 	// Añadimos una pausa para que el programa finalice cuando el usuario quiera
	
}
