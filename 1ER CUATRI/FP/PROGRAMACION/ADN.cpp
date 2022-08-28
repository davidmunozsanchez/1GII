#include <iostream>
#include <cstring>

using namespace std;

const int TAMANIO_MAX = 100;
const int MAX_FILAS = 100;
const int MAX_COL = 2;

class Base_de_datos{
	private:
		int pares;
		string base_datos[MAX_FILAS][MAX_COL];
		
	public:
		void lectura_base();
		
		void comparacion();
};

int main(){
	Base_de_datos base1;
	
	base1.lectura_base();
	
	base1.comparacion();
}

void Base_de_datos::lectura_base(){
	cout << "Introduce el tamanio de la base de datos (numero de pares): ";
	cin  >> pares;;
	
	cout << "Introduce un nombre y una secuencia de ADN, separados por espacio: "; 
	for (int i = 0; i < pares; i++){
		cin >> base_datos [i][0];
		cin >> base_datos [i][1];
	}
}	

void Base_de_datos::comparacion(){
	char adn[TAMANIO_MAX];
	char adn_introducido[TAMANIO_MAX];
	int longitud_adn_intr;
	bool continuar = true;
	bool evaluar = true;
	
	cout << "Introduce una secuencia de ADN para buscarla: ";
	cin  >> adn_introducido;
	
	longitud_adn_intr = strlen(adn_introducido);
	
	for (int i = 0; i < pares; i++){
		
		strcpy(adn, base_datos[i][1].c_str());
		
		if (strlen(adn) == longitud_adn_intr){
			if (evaluar){
				for (int h = 0; h < longitud_adn_intr; h++){
					if (adn_introducido[h] != '#'){
						continuar = true;	
					}
						
					else{
						cout << "El ser vivo buscado es: " << base_datos[i][0];
						evaluar = false;
					}
				}
			}
			if (continuar){
				for (int j = 0; j < longitud_adn_intr; j++){
					for (int k = 0; k < longitud_adn_intr; k++){
						if (adn[j] == (adn_introducido[k])){
							adn_introducido[k] = '#';
							continuar = false;	
						}
					}	
				continuar = true;
				if (j == longitud_adn_intr - 1){
					continuar = false;
					evaluar = true;
				}
				}
			}	
		}
	}
}

