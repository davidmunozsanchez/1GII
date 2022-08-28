/*	Programa para mostrar un numero con sus cifras invertidas haciendo uso de una funcion
*/

#include <iostream>
#include <cmath>

using namespace std;

/*	La funcion devuelve un entero y trabaja ocn un entero, del que se encarga de dar
	la vuelta
*/

int Inverso (int numero ){
	int contador_cifras = 0;
	int copia, final = 0, cifra = 0;
	int potencia, num_aux;
	
	copia = numero;
	num_aux = numero;
	
	while (copia != 0){
		copia /= 10;
		contador_cifras ++;
	}
	
	for (int i = 1; i <= contador_cifras; i ++){
		cifra = num_aux % 10;
		final += cifra * (int) pow (10, contador_cifras - i);
		num_aux /= 10;
	}
	
	return final;
}

int main(){
	int numero;
	int resultado;
	
	cout << "Introduce un numero para darle la vuelta: ";
	cin >> numero;
	
	resultado = Inverso(numero);
	
	cout << resultado;
	
}


