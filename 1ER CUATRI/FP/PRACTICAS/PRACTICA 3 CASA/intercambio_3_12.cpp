/*	Programa para intercambiar los valores de 3 variables usando
	usando el menor numero de auxiliares posibles
*/

# include <iostream>

using namespace std ;

int main (){
	int x = 10, y = 20, z = 30 ;		// Declaro variables y asigno valores de prueba
	int var_aux ;
	
	var_aux = x ;		// Realizo los cambios
	x = z;
	z = y ;
	y = var_aux;
	
	cout << x <<" "<< y <<" "<< z ;
	
}
