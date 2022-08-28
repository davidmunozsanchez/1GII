#include <iostream>

using namespace std;

int main(){
	int numero1, numero2;
	int contador_1 = 0, contador_2 = 0;
	bool no_es_1, gana_1, gana_2;
	
	cout << "Introduce una secuencia de parejas de numero, de manera que el primero sea el dorsal y el segundo el numero de puntos: ";
	
	no_es_1 = true;
	
	while (no_es_1){
		cin >> numero1;
		
		switch (numero1){
			
			case 1:
			case 2:
			case 3:
				
				cin >> numero2;
				
				contador_1 += numero2;
				
				break;
				
			case 4:
			case 5:
			case 6:
				
				cin >> numero2;
				
				contador_2 += numero2;
				
				break;
		
			case -1:
				
				no_es_1 = false;
				
				break;
		}
	}
	
	gana_1 = contador_1 > contador_2;
	gana_2 = contador_1 < contador_2;
	
	if (gana_1)
		cout << "El ganador es el equipo 1";
	
	if (gana_2)
		cout << "El ganador es el equipo 2";
	
	else {
		cout << "Han empatado";
	}
}
