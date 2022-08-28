/* 	Programa para realizar diversas operaciones con conjuntos haciendo uso de clases y de la
	clase vector
*/

#include <iostream>
#include <vector>

using namespace std;


class Conjunto{
	private:
		vector <int> elementos;
		
		// Metodo privado para ordenar los elementos del conjunto de menor a mayor
		void Ordenar(){
			int minimo;
			int posicion_minimo;
			int intercambia;
			
			for (int izda = 0 ; izda < elementos.size(); izda++){
				minimo = elementos[izda];
				posicion_minimo = izda;
				
				for (int i = izda + 1; i < elementos.size(); i++){
					if (elementos[i] < minimo){
						minimo = elementos[i];
						posicion_minimo = i;
					}
				}
				
				intercambia = elementos[izda];
				elementos[izda] = elementos[posicion_minimo];
				elementos[posicion_minimo] = intercambia;
			}
		}
		
		// Metodo privado para eliminar un valor, comprobando que este en el conjunto primero
		void Eliminar(int valor){
			vector<int> copia;
			int i = 0;
			int posicion;
			bool seguir = true;
			
			while (seguir == true && i < elementos.size()){
				if (elementos[i] == valor){
					seguir = false;
					posicion = i;
				}
					
				else 
					i++;
			}
			
			
				copia = elementos;
				elementos.clear();
				
				for (int j = 0; j < posicion; j++)
					elementos.push_back(copia[j]);
						
				for (int j = posicion + 1; j < copia.size(); j++)
					elementos.push_back(copia[j]);
					
		}
		
		/* Metodo privado que devuelve un booleano segun un elemento este o no en el conjunto
			TRUE = NO_REPE (SI ESTÁ EN EL CONJUNTO)
			FALSE = !NO_REPE (SI NO ESTÁ EN EL CONJUNTO)
		*/
		bool No_repe(int elemento){
			int i = 0;
			bool repe  = false;
			
			while (!repe && i < elementos.size()){
				if (elementos[i] == elemento)
					repe = true;
				
				else 
					i++;
			}
			
			return repe;
		}
		
		
	public:
		// Constructor para inicializar un cojunto con 0 elementos
		Conjunto(){}
		
		// Constructor para inicializar un conjunto segun un vector, evitando repetidos
		Conjunto(vector <int> vector_intr){
			int tamanio = vector_intr.size();
			bool una_vez;
			
			for (int i = 0; i < tamanio; i++)
				elementos.push_back(vector_intr[i]);

			Ordenar();
			
			for (int i = 0; i < elementos.size(); i++){
				for (int j = i + 1; j < elementos.size(); j++){
					if (elementos[i] == elementos[j] )
						Eliminar(elementos[j]);
				}
			}	
		}
		
		// Metodo publico para ver si un entero pertenece al conjunto
		void Pertenece(int entero){
			if (No_repe(entero)){
				cout << "\nEl entero pertenece al conjunto" << endl;
			}
			
			else 
				cout << "\nEl entero no pertenece al conjunto" << endl;
				
		}
		
		// Metodo publico para aniadir elementos al conjunto
		void Aniadir(int elemento){
			if (!No_repe(elemento)){
				elementos.push_back(elemento);
				
				Ordenar();
			}
			
		}
		
		// Metodo publico para mostrar un vector
		void Mostrar(){
			for (int i = 0; i < elementos.size(); i++)
				cout << elementos[i] << " ";
				
			cout << endl;
		}
		
		/*	Metodo que devuelve un conjunto interseccion de otros dos.
			Para ello, va aniadiendo al conjunto3 creado los elementos repetidos del
			conjunto 1 en el 2 o viceversa
		*/
		Conjunto Interseccion(Conjunto conjunto2){
			Conjunto conjunto3;
			
			for (int i = 0; i < elementos.size(); i++){
				if (conjunto2.No_repe(elementos[i]))
					conjunto3.Aniadir(elementos[i]);
			}
			
			return conjunto3;
		}
		
		/*	Metodo que devuelve un conjunto union de otros dos.
			Para ello, elimina los elementos comunes de uno de los dos vectores y,
			posteriormente, los une en el conjunto3 y ordena dicho vector
		*/
		Conjunto Union(Conjunto conjunto2){
			Conjunto conjunto3;
			
			for (int i = 0; i < elementos.size(); i++){
				if (conjunto2.No_repe(elementos[i])){
					conjunto2.Quitar(elementos[i]);
				}
			}
			
			for (int i = 0; i < elementos.size(); i++)
				conjunto3.Aniadir(elementos[i]);
			
			for (int i = 0; i < conjunto2.elementos.size(); i++)
				conjunto3.Aniadir(conjunto2.elementos[i]);
			
			conjunto3.Ordenar();
			
			return conjunto3;
		}
		
		// Metodo publico para quitar un valor de un conjunto
		void Quitar(int valor){
			Eliminar(valor);
		}
	
		
};

int main(){
	const char FINALIZADOR = -1;
	int elemento;
	vector <int> vector1;
	vector <int> vector2;
	
	cout << "Introduce las componentes del primer vector y finaliza con un -1: ";
	
	cin  >> elemento;
	
	while (elemento != FINALIZADOR){
		vector1.push_back(elemento);
		cin >> elemento;
	}
	
	cout << "Introduce las componentes del segundo vector y finaliza con un -1: ";
	cin  >> elemento;
	
	while (elemento != FINALIZADOR){
		vector2.push_back(elemento);
		cin >> elemento;
	}
	
	
	Conjunto conjunto1(vector1);
	Conjunto conjunto2(vector2);
	Conjunto conjunto3;

	conjunto2.Mostrar();
	
	}
