#include <iostream>

using namespace std;


int main(){
	int numero, numero_final, grado, cifra, potencia, suma_total;
	int contador_iteraciones = 0;
	bool es_uno, cifras;
	int i;
	
	do {
		cout << "Introduce el numero natural y el grado, para ver si es feliz: ";
		cin  >> numero >> grado;
	} while (numero <= 0 && grado <= 0);
	
	es_uno = false;
	cifras = true;
	
	while (!es_uno){
		
		while (cifras){
			cifra = numero % 10;
			potencia = cifra * cifra;
			suma_total  += potencia;	
			numero /= 10;
			
			if (numero == 0)
				cifras = false;
		}
		
		if (suma_total == 1)
			es_uno = true;
			
		numero = suma_total;
		suma_total = 0;
		cifras = true;
		contador_iteraciones++;
	
	}
	
	if (es_uno && grado >= contador_iteraciones)
		cout << "El numero es amigo de grado mayor o igual que " << grado;
		
	else {
		cout << "No es amigo";
	}
	
}
