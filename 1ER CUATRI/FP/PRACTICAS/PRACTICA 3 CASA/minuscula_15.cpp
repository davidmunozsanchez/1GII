/*	Programa que lee un caracter que suponemos en mayuscula y lo pasa a minuscula
	conociendo que segun la tabla ASCII, el valor de una mayuscula es como el de la miniscula
	sumandole 32.
*/

# include <iostream>

using namespace std ; 

int main (){
	char letra_min, letra_mayus;	// Declaracion de variables
	
	cout << "Introduce la letra que quieres pasar a minusculas: ";	//Introducimos datos
	cin  >> letra_mayus;
	
	letra_min = letra_mayus + 32 ;	// Al valor del caracter de la mayuscula le sumamos 32
	
	cout << letra_min ;

}
