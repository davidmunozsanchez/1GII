/*	Programa para convertir una minuscula y una mayuscula en mayuscula y minuscula
	respectivamente. Si se introduce un caracter no alfabetico, no se hace nada, 
	simplemente se almacena en la variable de salida
*/

#include <iostream>

using namespace std;

int main(){
	
	//Decalaramos las mismas constantes y variables que en el 5, pero con un booleano mas
	const int DISTANCIA_MAYUS_MIN = 'a' - 'A';
	char letra_original, letra_convertida;
	bool es_mayuscula, es_minuscula;
	
	// Introducimos los datos
	cout << "Introduce la letra que quieras pasar a mayuscula o a minuscula: ";
	cin  >> letra_original;
	
	// Asignamos a los booleanos el valor true o false, segun se cumpla eso
	es_mayuscula = (letra_original >= 'A') && (letra_original <= 'Z');
	es_minuscula = (letra_original >= 'a') && (letra_original <= 'z');
	
	// Comparamos con estructuras condicionales y hacemos las operaciones
	if (es_mayuscula)
		letra_convertida = letra_original + DISTANCIA_MAYUS_MIN;
	
	if (es_minuscula)
		letra_convertida = letra_original - DISTANCIA_MAYUS_MIN;
	
	else 
		letra_convertida = letra_original;
	
	// Imprimimos el resultado final
	cout << "El caracter " << letra_original << " una vez convertido es: " << letra_convertida << "\n\n";
}
