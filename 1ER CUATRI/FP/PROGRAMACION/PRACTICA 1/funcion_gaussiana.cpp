/* Programa para calcular el valor en x de una funcion gaussiana
	dados el punto x, la esperanza y la desviacion tipica       
*/

#include <iostream>		// Inclusion de los recursos E/S
#include <cmath>		// Inclusion de los recursos matematicos

using namespace std ;

int main(){							// Programa principal
	const double PI = 3.1416 ;		// Declaro el numero pi como constante
	double media ;					// Declaro las variables media, desv (desviacion)
	double desv ;					// x (punto donde quiero calcular la funcion)
	double x ;						// y valor.
	double valor ;
	double base1 ;					// Decñaro dos variables y una constante
	const double EXPONENTE1 = -1;	// para facilitar la comprension de la 
	double exponente2 ;				// expresion final
	
	cout << "Introduce la media o esperanza: " ;		// Se introcue la media
	cin  >> media ;										// y se asigna a la variable media
	cout << "Introduce la desviacion tipica: " ;		// Se introduce la desviacion tipica
	cin  >> desv ;										// y se asigna a la variable desv
	cout << "Introduce el punto donde quieres calcular el valor de la funcion: " ;	//Se introduce el punto
	cin  >> x ;																		// y se asigna a la variable x
	
	
	base1 = desv * sqrt(2 * PI) ;							// Asignamos a base1 la base del primer factor de la expersion
	exponente2 = -1/2 * pow (((x-media) / desv ), 2) ;		//Asignamos a exponente2 el exponente del segundo factor de la epxresión
	valor = pow (base1, EXPONENTE1 ) * exp (exponente2) ;	// El exponente1 es constante y la base2 es una funcion predefinida (exp())
	
	cout << "\nEl valor de la funcion en el punto " << x << " es " << valor << ".\n\n" ;	//Mostramos el valor de la funcion en x
	system("pause");		//Añadimos una pausa

}
	
