/*	Programa para trabajar con polinomios, implementando la suma
	la evalucaion en un punto x y simplemente inicializarlo

*/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Declaramos una estructura con 4 enteros dentro
struct polinomio{
	int coef0, coef1, coef2, coef3;
};

int main(){
	polinomio polinomio1, polinomio2, polinomio_suma; 
	string grado0 = "Introduce el coef de tu poliniomio de grado 0: ";
	string mas_de_0 = "Introduce los coef de tu polinomio, de izq a dcha, separados por espacios: ";
	int eleccion;
	double valor_x, valor_poli; 
	
	// Introducimos los coeficientes del polinomio (inicializacion desde teclado), que corresponderia al apartado 1 de nuestro programa
	
	cout << "Introduce los coeficientes del polinomio (separados por espacios y de mayor a menor): ";
	cin  >> polinomio1.coef3 >> polinomio1.coef2 >> polinomio1.coef1 >> polinomio1.coef0,
	
	// Dejamos que el usuario elija que quiere hacer
	
	cout << "\n\nQue quieres hacer?\n\n";
	cout << "1 Evaluar un polinomio en x\n2 Sumar polinomios\n";
	cin  >> eleccion;
	
	// Hay dos posibles casos
	
	switch (eleccion){
		case 1:
			cout << "Introduce para que valor de x quieres evaluar el polinomio: ";
			cin  >> valor_x;
			
			valor_poli = polinomio1.coef3 * pow(valor_x, 3) + polinomio1.coef2 * pow(valor_x, 2) + polinomio1.coef1 * valor_x + polinomio1.coef0;
			
			cout << "El valor del polinomio para x = " << valor_x << " es " << valor_poli;
			
			break;
			
		case 2:
			cout << "Introduce los coeficientes del polinomio 2, para realizar la suma (separados por espacios y de mayor a menor): ";
			cin  >> polinomio2.coef3 >> polinomio2.coef2 >> polinomio2.coef1 >> polinomio2.coef0,
			
			polinomio_suma = {polinomio1.coef0 + polinomio2.coef0, polinomio1.coef1 + polinomio2.coef1, polinomio1.coef2 + polinomio2.coef2, polinomio1.coef3 + polinomio2.coef3};
			
			cout << "Los coeficientes del nuevo polinomio son: " << polinomio_suma.coef3 << ", " << polinomio_suma.coef2 << ", ";
			cout << polinomio_suma.coef1 << ", " << polinomio_suma.coef0 << "\n\n";
	}
}
