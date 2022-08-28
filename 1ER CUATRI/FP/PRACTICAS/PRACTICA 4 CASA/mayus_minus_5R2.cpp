/*	Programa para comprobar si una letra es mayuscula o no y en dicho caso
	sustituirla por la letra minuscula correspondiente
*/

#include <iostream>

using namespace std;

int main(){
	
	/* Declaramos variables para guardar la letra introducida, entre una minuscula 
	y otra mayuscula y un booleano para ver si es mayuscula*/
	char letra_convertida, letra_original;
	const int DISTANCIA_MAY_MIN = 'a' - 'A';
	bool es_mayuscula;
	
	// Introducimos los datos
	cout << "Introduzca una letra: ";
	cin  >> letra_original;
	
	// Comparamos los casos con estructuras condicionales
	if ((letra_original >= 'A') && (letra_original <= 'Z'))
		es_mayuscula = true;
	
	else 
		es_mayuscula = false;
	
	if (es_mayuscula)
		letra_convertida = letra_original + DISTANCIA_MAY_MIN;
		
	else
		letra_convertida = letra_original;
		
	cout << "\nEl caracter " << letra_original << " convertido es: " << letra_convertida;
}
