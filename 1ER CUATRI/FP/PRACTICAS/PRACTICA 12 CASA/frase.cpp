/*	Programa para trabajar con una frase, tomandola como un vector (de la clase vector), que almacena
	caracteres.
*/

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Frase{
	private:
		vector<char> vector1; // Dato privado donde almacenaremos la frase
		
		/* 	Metodo privado para elminar los posibles espacios iniciales que el usuario
			introduzca en su frase. Copia el vector1 a otro llamado copia, localiza el primer elemento
			que no es un espacio, limpia el vector1 y lo vuelve a rellenar a partir de esa posicion
		*/
		void EliminaBlancosIniciales(){
			vector<char> copia;
			int contador = 0;
			bool continuar = true;
			int posicion;
			
			while (continuar && vector1[0] == ' '){
				if (vector1[contador] == ' ')
					contador++;
				
				else{
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
		
		/* 	Metodo privado para elminar los posibles espacios finales que el usuario introduzca.
			Va leyendo el vector desde atras, si el elemento es un espacio, lo quita, y asi hasta que
			encuentre un elemento diferente a un espacio
		*/
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
	
		
	public:
		/*	Constructor publico que crea una frase en un vector dinamico de char a partir de un string,
			pasando previamente este a cstring y almacenandolo en un vector normal tipo char
		*/
		Frase (string frase){
			const int TAMANIO = 100;
			char copia [TAMANIO];
			
			strcpy(copia, frase.c_str());
			
			for (int i = 0; i < strlen(copia); i++)
				vector1.push_back(copia[i]);
				
			EliminaBlancosIniciales();
			EliminaBlancosFinales();
		}
		
		/* 	Metodo publico que cuenta el numero de palabras en una frase. Cada vez que encuentra un elemento diferente a 
			un espacio, suma una sola vez 1 al contador de palabras. Cuando encuentra otro espacio, el booleano otra_vez se
			vuelve true, por lo que podra volver a contar
		*/	
		int NumeroPalabras(){
			int contador = 0;
			int num_palabras = 0;
			bool una_vez = true;
			
			while (contador < vector1.size()){
				if (vector1[contador] != ' '){
					if (una_vez){
						num_palabras += 1;
						una_vez = false;
					}
					contador++;
				}
				
				
				if(vector1[contador] == ' '){
					una_vez = true;
					contador++;
				}
			}
			
			return num_palabras;
		}
		
		/*	Metodo publico para localizar la posicion donde empìeza una palabra en la frase dada
			el orden en que se encuentra esta en la frase. Para ello, igual que antes, va aumentando
			el contador de palabras "posicion", cada vez que encuentra una palabra. Si coincide con kesima,
			devuelve el contador del bucle while, que es la posicion de la pirmera letra de la palabra buscada
		*/
		int LocalizarPalabra(int kesima){
			int contador = 0;
			int posicion = 0;
			bool una_vez = true;
			bool encontrada = false;
			
			while (contador < vector1.size() && !encontrada){
				if (una_vez && vector1[contador] != ' '){
					posicion += 1;
					
					if (posicion == kesima && !encontrada){
						encontrada = true;
						return contador;
					}
					
					una_vez = false;
				}
				
				if (vector1[contador] != ' ')
					contador++;
				
				
				if(vector1[contador] == ' '){
					contador++;
					una_vez = true;
				}
			}
			
		}
		
		/*	Metodo publico para borrar una palabra completa dado su orden en la frase.
			Para ello, primero localizamos la palabra haciendo uso del metodo LocalizarPalabra(kesima),
			y la recorremos en el vector de la frase hasta que encontremos un espacio, ese es el tamanio_a_eliminar, despues simplemente
			creamos una copia del vector, limpiamos el vector y metemos todos los elementos anteriores a la palabra con un bucle, y todos los posteriores con otro.
		*/
		void BorraPalabra(int kesima){
			vector<char> copia;
			int posicion;
			int contador;
			int tamanio_a_eliminar = 1; // Se inicializa a 1 para borrar tambien el espacio siguiente a la palabra y que no quede una separacion con un espacio mas al original
			bool seguir = true;
			
			posicion = LocalizarPalabra(kesima);
			contador = posicion;
		
			while (contador < vector1.size() && seguir){
				if (vector1[contador] != ' '){
					tamanio_a_eliminar += 1;
					contador++;
				}
				
				else
					seguir = false;
			}
			
			copia = vector1;
			vector1.clear();
			
			for (int i = 0; i < posicion; i++)
				vector1.push_back(copia[i]);
				
			for (int i = posicion + tamanio_a_eliminar; i < copia.size(); i++)
				vector1.push_back(copia[i]);
				
			EliminaBlancosIniciales();
			EliminaBlancosFinales();
			
		}
		
		/*	Metodo publico para mover una palabra al final de la frase dado su orden en esta. Para ello, tomamos su posicion,
			y a partir de ahi añadimos todos los elementos hasta que aparezca un espacio, al final. Despues, eliminamos esa palabra con
			la funcion anterior
		*/
		void MoverPalabraFinal(int kesima){
			int posicion;
			int contador;
			bool seguir = true;
			
			posicion = LocalizarPalabra(kesima);
			contador = posicion;
			
			vector1.push_back(' '); // Para dejar una separacion con la palabra que previamente estaba al final
			while (contador < vector1.size() && seguir){
				if (vector1[contador] != ' '){
					vector1.push_back(vector1[contador]);
					contador++;
				}
				
				else
					seguir = false;
			}
			
			BorraPalabra(kesima);
		}
		
		/*	Metodo publico con el objetivo de visualizar un objeto de la clase
		*/
		void Motrar(){
			for (int i = 0; i < vector1.size(); i++){
				cout << vector1[i] << " ";
			}
		}
	
		
};

int main(){
	string palabra;
	int eso;
	
	palabra = "     hoy hace calor en azuaga";
	
	Frase frase1 (palabra);

	
	frase1.MoverPalabraFinal(4);
	
	frase1.Motrar();

	
	
}
