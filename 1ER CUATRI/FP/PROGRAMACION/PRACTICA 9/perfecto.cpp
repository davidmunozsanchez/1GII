/* Programa para imprimir todos los numeros perfectos hasta un tope, comprobando si es perfecto
	o no con una funcion
*/

#include <iostream>

using namespace std;

// Esta funcion devuelve un booleano y trabaja con un entero, el cual calcula si es perfecto o no

bool Perfecto(int numero){
	int suma_div = 0;
	
	for (int i = 1; i <= numero/2; i++){
		if (numero % i == 0)
			suma_div += i;
	}
	if (suma_div == numero)
		return true;
	
	else
		return false;
}

int main(){
	int numero1;
	
	cout << "Introduce un numero tope para imprimir todos los perfectos hasta el: ";
	cin  >> numero1;
	
	for (int i = 1; i <= numero1; i++){
		if (Perfecto(i))
			cout << i << "\n";
	}
}
