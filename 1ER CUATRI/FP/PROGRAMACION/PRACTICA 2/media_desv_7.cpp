/*	Programa para calcular la media aritmetica y la desviacion tipica
	de la altura de tres personas n=3. Suponemos que los datos son dados en el SI.
	La formula de la media equivale al sumatorio de las tres alturas dividido entre el numero de elementos (3)
	La de la desviacion equivale a la raíz cuadrada del sumatorio de la diferencia de toas las alturas con respecto a la media dividio entre el numero de elementos (3)
*/

#include <iostream>		// Incluimos los recursos E/S
#include <cmath>		// Incluimos los recursos matematicos

using namespace std;

int main(){									// Programa principal
	const double FRACCION = 1/3.0;			// Declaramos 1/3 como constante para simplificar la expresion posteriormente
	double altura1, altura2, altura3;		// Declaramos las tres variables correspondientes a las alturas
	double media;							// Declaramos dos variables:
	double desviacion;						// una para la media y otra para la desviacion
	
	cout << "Introduce la primera altura: " ;		// Pedimos las tres alturas
	cin  >> altura1 ;								// y las asignamos a sus 
	cout << "Introduce la segunda altura: " ;		// respectivas variables
	cin  >> altura2 ;
	cout << "Introduce la tercera altura: " ;
	cin  >> altura3 ;
	
	media = FRACCION * (altura1 + altura2 + altura3);																// Expresion para la media
	desviacion = sqrt (FRACCION *(pow(altura1 - media, 2)+ pow(altura2 - media, 2)+ pow(altura3 - media, 2)));		// Expresion para la desviacion
	
	cout << "\nLa altura media es " << media << " metros y la desviacion tipica " << desviacion << " metros.\n\n";	// Mostramos los datos al usuario
	system ("pause");			// Añadimos una pausa para que el usuario finalice cuando quiera			

	
	
	
	
}
