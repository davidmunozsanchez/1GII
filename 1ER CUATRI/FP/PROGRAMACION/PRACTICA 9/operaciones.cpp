/* Programa para hacer mcd, mcm y operaciones aritmeticas con numeros enteros positivos
*/

#include <iostream>

using namespace std;

/*	Tiene especial interes declarar una funcion para el MCD fuera de la otra funcion, ya que lo usaremos
	tanto para el MCD como para el MCM. Esta funcion devuelve un entero y trabaja con dos.
*/
int Mcd (int a, int b){
	int mcd;
	
	for (int i = 1; i < a && i < b; i++){
		if (a % i == 0 && b % i == 0)
			mcd = i;
			
	}
	
	return mcd;
}

/* Esta funcion devuelve un entero y trabaja con dos enteros y un char, que nos
	indica el tipo de operacion
*/

int Operacion(int num1, int num2, char tipo){
	int minimo_aux, resultado;
	
	if (tipo == 'm'){
		minimo_aux = num1 * num2;
		resultado = minimo_aux / Mcd(num1, num2);
		return resultado;
	}
	
	if (tipo == 'd'){
		resultado = Mcd (num1, num2);
		return resultado;
	}
	
	if (tipo == '+'){
		resultado = num1 + num2;
		return resultado;
	}
	
	if (tipo == '-'){
		resultado = num1 - num2;
		return resultado;
	}
	
	if (tipo == '*'){
		resultado = num1 * num2;
		return resultado;
	}
	
	if (tipo == '/'){
		resultado = num1 / num2;
		return resultado;
	}
}

	int main(){
		int numero1, numero2, final;
		char operador;
		
		do {
			cout << "Introduce dos numeros y un operador, separado por espacios: ";
			cin  >> numero1 >> numero2 >> operador;
		} while (numero1 <= 0 && numero2 <= 0);
		
		final = Operacion(numero1, numero2, operador);
		
		cout << "El resultado de la operacion elegida es " << final;
	}

