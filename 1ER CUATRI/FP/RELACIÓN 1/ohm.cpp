/* Programa para calcular el voltaje dados la intensidad y la resistencia, según Ley de Ohm
voltaje = intensidad x resistencia */

#include <iostream> //Inclusión de los recursos E/S

using namespace std;

int main (){ //Programa principal
	double intensidad;
	double resistencia;
	double voltaje;
	
	cout <<"Introduzca el valor de la intensidad: ";
	cin >> intensidad;
	cout <<"Introduzca el valor de la resistencia: ";
	cin >> resistencia;
	
	voltaje = intensidad * resistencia;
	
	cout <<"\nEl valor del voltaje es "<< voltaje <<".\n";
}

