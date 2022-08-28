/*	Programa para eliminar caracteres de un objeto de la clase frase creada en el codigo del ejercicio anterior
	segun un patron dado por un vector de la clase VectorParejaCaracterEntero. El vector es de tipo ParejaCaracterEntero,
	struct que tiene un char (caracter) y un int (entero), que nos dice que caracter eliminar y cuantas veces eliminarlo si es posible
*/

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

// Struct para cada elemento del vector
struct ParejaCaracterEntero{
	char caracter;
	int entero;
};

class VectorParejaCaracterEntero{
	private:
		vector<ParejaCaracterEntero> vector_parejas; // Vector de pares (caracter, entero), privado
		
	public:
		
		/*	Constructor que a partir de un vector de tipo ParejaCaracterEntero, lo asigna al dato privado
			de la clase
		*/
		VectorParejaCaracterEntero (vector<ParejaCaracterEntero> a){
				vector_parejas = a;
		}
		
		// Constructor vacio
		VectorParejaCaracterEntero(){
		}
		
		// Metodo publico para obtener el caracter asociado a cierta posicion i de vector_parejas
		char ObtenerCaracter(int i){
			return vector_parejas[i].caracter;
		}
		
		// Metodo publico para obtener el entero asociado a cierta posicion i de vector_parejas
		int ObtenerEntero(int i){
			return vector_parejas[i].entero;
		}
		
		// Metodo publico para obtener el tamanio de vector_parejas
		int ObtenerTamanio(){
			return vector_parejas.size();
		}
		
};

/*  La clase Frase, exactamente igual que en el ejercicio anterior, salvo por la adicion de varios metodos,
	abajo explicados
*/
class Frase{
	private:
		vector<char> vector1;
		
		void EliminaBlancosIniciales(){
			vector<char> copia;
			int contador = 0;
			bool continuar = true;
			int posicion;
			
			while (continuar && vector1[0] == ' '){
				if (vector1[contador] == ' ')
					contador++;
				
				if (vector1[contador] != ' '){
					continuar = false;
					posicion = contador;
				}
			}
			
			copia = vector1;
			
			vector1.clear();
			
			for (int i = posicion; i < copia.size(); i++){
				vector1.push_back(copia[i]);
			
			}	
			
		}
		
		void EliminaBlancosFinales(){
			int contador = vector1.size()- 1;
			bool continuar = true;
			
			while (continuar && vector1[vector1.size()-1] == ' ' && contador >= 0){
				if (vector1[contador] == ' '){
					vector1.pop_back();
					contador--;
				}
				
				else
					continuar = false;
			}
		}
		
		/* 	Metodo privado para quitar un caracter de una frase dado el caracter en cuestion. Para ello
			recorre el vector con un bulce hasta que da con el primer caracter igual al que tiene que eliminar.
			Para eliminarlo, hace uso de un vector auxiliar al que copia el vector1, el cual limpia y vuelve a llenar
			teniendo en cuenta los elementos anteriores al caracter que queremos eliminar y los posteriores
		*/
		void QuitarCaracter(char caracter){
			vector<char> copia;
			int i = 0;
			int posicion;
			bool seguir = true;
			
			while (seguir == true && i < vector1.size()){
				if (vector1[i] == caracter){
					seguir = false;
					posicion = i;
				}
					
				else 
					i++;
				}
		
				copia = vector1;
				vector1.clear();
				
				for (int j = 0; j < posicion; j++)
					vector1.push_back(copia[j]);
						
				for (int j = posicion + 1; j < copia.size(); j++)
					vector1.push_back(copia[j]);
		}
		
	public:
		Frase (string frase){
			const int TAMANIO = 100;
			char copia [TAMANIO];
			
			strcpy(copia, frase.c_str());
			
			for (int i = 0; i < strlen(copia); i++)
				vector1.push_back(copia[i]);
				
			EliminaBlancosIniciales();
			EliminaBlancosFinales();
		}
		
		void Motrar(){
			for (int i = 0; i < vector1.size(); i++){
				cout << vector1[i] << " ";
			}
		}
		
		/* 	Metodo publico para eliminar ciertos caracteres segun el patron que nos otorga el objeto 
			de la clase VectorParejaCaracterEntero, el cual nos dice con cada elemento, el caracter que tenemos que quitar,
			y cuantas veces tenemos que eliminarlo si apareciera al menos una de esas veces
		*/	
		void EliminaCaracter(VectorParejaCaracterEntero objeto){
			vector<char> copia1;
			int total_a_eliminar;
			int contador_eliminaciones = 0;
			int contador = 0;
			int tope;
			char caracter_a_eliminar;
			bool primera;
			
			copia1 = vector1;
			tope = copia1.size();
			
			for (int i = 0; i < objeto.ObtenerTamanio(); i++ ){
				total_a_eliminar = objeto.ObtenerEntero(i);
				caracter_a_eliminar = objeto.ObtenerCaracter(i);
				
				while (contador_eliminaciones < total_a_eliminar && contador < tope){ // Si no se cumple el total a eliminar pero el contador de pasadas supera al tope, se para el bucle
					if (copia1[contador] == caracter_a_eliminar){
						QuitarCaracter(caracter_a_eliminar);
						contador_eliminaciones += 1;
					}
						
					contador++;
						
				}
				
				contador_eliminaciones = 0;
				contador = 0;
			}
			
			EliminaBlancosIniciales();
			EliminaBlancosFinales();
		}
		
};

int main(){
	ParejaCaracterEntero prueba[100];
	vector<ParejaCaracterEntero> vector1;
	int longitud;
	string palabra;
	int eso;
	
	cout << "Introduce la longitud: ";
	cin  >> longitud;
	
	cout << "Introduce los componentes: ";
	
	for (int i = 0; i < longitud; i++){
		cin >> prueba[i].caracter >> prueba[i].entero;
	}
	
	for (int i = 0; i < longitud; i++){
		vector1.push_back(prueba[i]);
	}
	
	VectorParejaCaracterEntero objeto (vector1);
	
	Frase frase1("hola david");
	frase1.EliminaCaracter(objeto);
	frase1.Motrar();
	
	
	
	
	
}


