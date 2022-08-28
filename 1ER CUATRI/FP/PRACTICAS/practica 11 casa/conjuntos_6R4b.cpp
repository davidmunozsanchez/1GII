/* Programa para realizar diversas operaciones con conjuntos haciendo uso de clases
*/

#include <iostream>

using namespace std;

const int MAXELEM = 100;

class Conjunto{
	private:
		int num_elem;
		int elementos[MAXELEM];
		
		// Metodo privado para ordenar los elementos del conjunto de menor a mayor
		void Ordenar(int elementos_actuales){
			int minimo;
			int posicion_minimo;
			int intercambia;
			
			for (int izda = 0 ; izda < elementos_actuales; izda++){
				minimo = elementos[izda];
				posicion_minimo = izda;
				
				for (int i = izda + 1; i < elementos_actuales; i++){
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
			int posicion;
			int total_utilizados;
			int tope;
			int i = 0;
			bool seguir = true;
			
			if (No_repe(valor)){
				while (seguir == true){
					if (elementos[i] == valor){
						seguir = false;
						posicion = i;
					}
					
					else 
						i++;
				}
				if (posicion >= 0 && posicion < num_elem){
					int tope = num_elem - 1;
					for (int i = posicion ; i < tope ; i++)
						elementos[i] = elementos[i+1];
						
					total_utilizados--;
				
					num_elem -= 1;
				}
			}
			
			
		}
		
		/* Metodo privado que devuelve un booleano segun un elemento este o no en el conjunto
			TRUE = NO_REPE (SI ESTÁ EN EL CONJUNTO)
			FALSE = !NO_REPE (SI NO ESTÁ EN EL CONJUNTO)
		*/
		bool No_repe(int elemento){
			int i = 0;
			bool repe  = false;
			
			while (!repe && i < num_elem){
				if (elementos[i] == elemento)
					repe = true;
				
				else 
					i++;
			}
			
			return repe;
		}
		
		
	public:
		// Constructor para inicializar un cojunto con 0 elementos
		Conjunto(){
			num_elem = 0;
		}
		
		// Constructor para inicializar un conjunto segun un vector y el numero de elementos de este
		Conjunto(int vector[MAXELEM], int elem){
			num_elem = elem;
			
			for (int i = 0; i < num_elem; i++)
				elementos[i] = vector[i];
				
			Ordenar(num_elem);	
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
				elementos[num_elem] = elemento;
				num_elem += 1;
				Ordenar(num_elem);
			}
			
		}
		
		// Metodo publico para mostrar un vector
		void Mostrar(){
			for (int i = 0; i < num_elem; i++)
				cout << elementos[i] << " ";
				
			cout << endl;
		}
		
		/*	Metodo que devuelve un conjunto interseccion de otros dos.
			Para ello, va aniadiendo al conjunto3 creado los elementos repetidos del
			conjunto 1 en el 2 o viceversa
		*/
		Conjunto Interseccion(Conjunto conjunto2){
			Conjunto conjunto3;
			
			for (int i = 0; i < num_elem; i++){
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
			
			for (int i = 0; i < num_elem; i++){
				if (conjunto2.No_repe(elementos[i])){
					conjunto2.Quitar(elementos[i]);
				}
			}
			
			for (int i = 0; i < num_elem; i++)
				conjunto3.Aniadir(elementos[i]);
			
			for (int i = 0; i < conjunto2.num_elem; i++)
				conjunto3.Aniadir(conjunto2.elementos[i]);
			
			conjunto3.Ordenar(conjunto3.num_elem);
			
			return conjunto3;
		}
		
		// Metodo publico para quitar un valor de un conjunto
		void Quitar(int valor){
			Eliminar(valor);
		}
	
		
};

int main(){
	int vector[MAXELEM] = {5,6,7,4,1,12,13,15,11};
	int vector2[MAXELEM] = {1,6,4,7};
	
	Conjunto conjunto1(vector, 9);
	Conjunto conjunto2(vector2, 4);
	Conjunto conjunto3;
	
	conjunto3 = conjunto2.Interseccion(conjunto1);
	
	conjunto3.Mostrar();
	}
