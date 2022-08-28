//Programa que busca un caracter dado en una cadena y dice si se encuentra o no

#include <iostream>
#include <cstring>
using namespace std;

const int LONG = 50;
bool Caracter_esta (char cadena[LONG], char caracter, int longitud){
	int contador = 0;
	for (int i = 0; i < longitud; i++){
		if (cadena[i] == caracter)
			contador++;
	}
	
	return contador >= 1;
}

int main (){
	char cadena1[LONG];
	char caracter1;
	int longitud1;
	bool caracter_en_cadena = false;
	
	cout << "Introduce cadena: ";
	cin >> cadena1;
	
	cout << "Introduce el caracter: ";
	cin >> caracter1;
	
	longitud1 = strlen (cadena1);
	
	caracter_en_cadena = Caracter_esta(cadena1, caracter1, longitud1);
	
	if (caracter_en_cadena)
		cout << "\nEl caracter esta en en la cadena";
	else 
	   cout << "\nEl caracter no esta en la cadena";
}
