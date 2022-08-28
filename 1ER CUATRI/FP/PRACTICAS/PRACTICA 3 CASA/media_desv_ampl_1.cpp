/*	Programa para calcular la media aritmetica y la desviacion tipica
	de la altura de tres personas n=3. Suponemos que los datos son dados en el SI.
	La formula de la media equivale al sumatorio de las tres alturas dividido entre el numero de elementos (3)
	La de la desviacion equivale a la raíz cuadrada del sumatorio de la diferencia de toas las alturas con respecto a la media dividio entre el numero de elementos (3)
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){									// Programa principal
	const double FRACCION = 1/3.0;			// Declaramos 1/3 como constante para simplificar la expresion posteriormente
	double altura1, altura2, altura3;		// Declaramos las tres variables correspondientes a las alturas
	double media;							// Declaramos dos variables:
	double desviacion;						// una para la media y otra para la desviacion
	string menor = " es menor que la media.\n\n";
	string mayor_igual = " es mayor o igual que la media.\n\n";
	
	
	cout << "Introduce la primera altura: " ;
	cin  >> altura1 ;								 
	cout << "Introduce la segunda altura: " ;
	cin  >> altura2 ;
	cout << "Introduce la tercera altura: " ;
	cin  >> altura3 ;
	
	media = FRACCION * (altura1 + altura2 + altura3);																// Expresion para la media
	desviacion = sqrt (FRACCION *(pow(altura1 - media, 2)+ pow(altura2 - media, 2)+ pow(altura3 - media, 2)));		// Expresion para la desviacion
	
	cout << "\nLa altura media es " << media << " metros y la desviacion tipica " << desviacion << " metros.\n\n";

	if (altura1 >= media){							// Con diversos condicionales, decimos si el valor
		cout << altura1 << mayor_igual ;			// es menor o mayor o igual a la media
	}
	else{
		cout << altura1 << menor ;
	}
	
	if (altura2 >= media){
		cout << altura2 << mayor_igual ;
	}
	else{
		cout << altura2 << menor ;
	}
	
		if (altura3 >= media){
		cout << altura3 << mayor_igual ;
	}
	else{
		cout << altura3 << menor ;
	}

}
