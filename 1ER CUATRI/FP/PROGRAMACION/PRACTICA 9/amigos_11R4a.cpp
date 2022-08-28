/*	Programa para determinar si dos numeros son amigos haciendo uso de una funcion y también para mostrar
	todos las parejas de amigos contenidas en un intervalo
*/
#include <iostream>

using namespace std;

/* 	Hacemos uso de una funcion que devuelve un booleano y que trabaja con dos enteros,
	los cuales comprueba si son amigos o no
*/
bool Amigos (int num1, int num2){
	int mitad_num1 = num1 / 2;
	int mitad_num2 = num2 / 2;
	int suma_div1 = 0, suma_div2 = 0;
	
	for (int i = 1; i <= mitad_num1; i++){
		if (num1 % i == 0)
			suma_div1 += i;	
	}
	
	for (int j = 1; j <= mitad_num2; j++){
		if (num2 % j == 0)
			suma_div2 += j;	
	}
	
	if (suma_div1 == num2 && suma_div2 == num1)
		return true;
		
	else
		return false;	
}

int main(){
	int numero1, numero2;
	bool es_amigo;
	int minimo, tope;
	
	cout << "Introduce dos numeros para ver si son amigos: ";
	cin  >> numero1 >> numero2;
	
	es_amigo = Amigos(numero1, numero2);
	
	if (es_amigo)
		cout << "Los numeros son amigos";
		
	else 
		cout << "No son amigos";
		
	// Programa B
	cout << "\n\nIntroduce un numero minimo y un tope para calcular parejas de amigos hasta el: ";
	cin >> minimo >> tope;
	
	for (int i = minimo; i <= tope; i++){
		for (int j = i; j <= tope; j++){
			if (Amigos(i, j))
				cout << i << "   " << j << "\n";
		}
	}
	
}
