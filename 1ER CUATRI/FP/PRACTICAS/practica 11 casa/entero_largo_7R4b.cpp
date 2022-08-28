/*	Programa para realizar diversas operaciones con numeros enteros, pero haciendo uso de estos
	como si de un vector de enteros se trataran
*/

#include <iostream>

using namespace std;

class EnteroLargo{
	private:
		// Creamos un vector adicional, con las cifras al contrario
		static const int MAXIMO = 100;
		int entero[MAXIMO];
		int entero_reves[MAXIMO];
		int tope;
		bool iguales;
		
		// Metodo privado que devuelve true si un numero es negativo y false si no lo es
		bool Es_negativo(){
			if (entero[0] < 0)
				return true;
			
			else 
				return false;
		}
		
		// Metodo privado para dar la vuelta a un vector que esta al reves
		void Dar_la_vuelta(){
			int copia;
			for (int i = 0; i < tope/2; i++){
				copia = entero[tope - (i+1)];
				entero [tope - (i+1)] = entero[i];
				entero[i] = copia;
			}
		}
		
	public:
		// Constructor para inicializar un objeto con todo a 0
		EnteroLargo(){
		}
		
		// Constructor para inicializar un objeto a partir de un entero
		EnteroLargo(int numero){
			int num_cifras = 1;
			int copia;
			
			iguales = false;
			
			copia = numero;
			
			while (copia > 9){
				copia /= 10;
				num_cifras++;
			}
			
			tope = num_cifras;
			
			for (int i = 0; i < tope; i++){
				if (numero > 9){
					entero[i] = numero % 10;
					entero_reves[i] = entero[i];
					numero /= 10;
				}
				
				else{
					entero[i] = numero;
					entero_reves[i] = entero[i];
				}
			}
			
			Dar_la_vuelta();
		}
		
		// Metodo para mostrar en pantalla un entero
		void Mostrar(){
			for (int i = 0; i < tope; i++){
				cout << entero[i];
			}
		}
		
		// Metodo para ver si un numero es mayor que otro
		bool Mayor (EnteroLargo entero2){
			int i = 0;
			
			
			if (Es_negativo() && !entero2.Es_negativo())
				return false;
				
			if (!Es_negativo() && entero2.Es_negativo())
				return true;
			
			else {
				if (tope > entero2.tope)
					return true;
			
				if (tope < entero2.tope)
					return false;
				
				else{
					while (i < tope){
						if (entero[i] == entero2.entero[i]){
							i++;
						}
							
						if (entero[i] > entero2.entero[i])
							return true;
							
						if (entero[i] < entero2.entero[i])
							return false;
					}
				}
			}
		}
		
		// Metodo para ver si un numero es menor que otro (no es mayor que otro)
		bool Menor (EnteroLargo entero2){
			return !Mayor(entero2);
		}
		
		// Metodo para ver si dos enteros son exactamente iguales
		bool Igual(EnteroLargo entero2){
			int i = 0;
			if (tope == entero2.tope && ((Es_negativo() && entero2.Es_negativo()) || (!Es_negativo() && !entero2.Es_negativo()))){
				while (i < tope){
					if (entero[i] == entero2.entero[i]){
						if (i = tope - 1)
							return true;
						
						else 
							return false;
					}
					
					else
						return false;
				}
			}
			
			else 
				return false;
		}
		
		// Metodo para ver si un entero es mayor o igual a otro
		bool Mayor_igual(EnteroLargo entero2){
			return Igual(entero2) || Mayor(entero2);
		}
		
		// Metodo para ver si un entero es menor o igual a otro
		bool Menor_igual(EnteroLargo entero2){
			return Igual(entero2) ||Menor(entero2);
		}
		
		// Metodo para ver si dos enteros son distintos
		bool Distinto(EnteroLargo entero2){
			return !Igual(entero2);
		}
		
		/*	Metodo que devuelve un objeto que es la suma de otros dos objetos (enteros positivos).
			Primero comprobamos que ambos tengan igual numero de cifras (tope), si no añadimos tantos 
			0 a la derecha del vector al reves como sea necesario.
			Despues comprobamos que ambos numeros son positivos y sumamos cifra a cifra.
			Si el resultado es mayor que 10, sumamos un 1 a la componente siguiente de uno de los dos vectores.
			Si el resultado de la suma del las dos cifras finales es mayor que 10, aniadimos un 1 a la derecha del vector resultado
			Asignamos el vector al vector entero, y le damos la vuelta
		*/
		EnteroLargo Suma(EnteroLargo entero2){
			EnteroLargo entero3;
			if (tope < entero2.tope){
				for (int i = tope; i < entero2.tope; i++)
					entero_reves[i] = 0;
				
				tope = entero2.tope;
			}
			
			if (tope > entero2.tope){
				for (int i = entero2.tope; i < tope; i++ )
					entero2.entero_reves[i] = 0;
				
				entero2.tope = tope;
			}
			
			if (!Es_negativo() && !entero2.Es_negativo()){
				
				entero3.tope = 0;
				
				for (int i = 0; i < tope; i++){
					if (entero_reves[i] + entero2.entero_reves[i] > 9){
						entero3.entero_reves[i] = (entero_reves[i] + entero2.entero_reves[i]) % 10;
						entero2.entero_reves[i + 1] += 1;
					}
					
					if (entero_reves[i] + entero2.entero_reves[i] <= 9) {
						entero3.entero_reves[i] = (entero_reves[i] + entero2.entero_reves[i]);
					}
					
					
					if (i == tope - 1 && (entero_reves[i] + entero2.entero_reves[i] >= 10)){
						entero3.entero_reves[tope] = 1;
						entero3.tope += 1;
					}
						
						
					entero3.tope += 1;
					
				}
				
				for (int i = 0; i < entero3.tope; i++ ){
					entero3.entero[i] = entero3.entero_reves[i];
					
					
				}
				
				entero3.Dar_la_vuelta();
				
				
				return entero3;
				
			}
			
		}
		
		/*	Metodo publico para restar dos enteros positivos siendo el primero mayor que el segundo.
			Primero procedemos exactamente igual que en la suma, igualando el numero de cifras.
			Despues restamos cifra a cifra. Si la cifra primera es mayor que la segunda restamos normal.
			Si es menor, le sumamos diez y restamos normal, teniendo en cuenta que hay que sumar 1 a la cifra siguiente
			del vector del numero menor. Al final procedemos igual que en la suma
		*/
		EnteroLargo Resta(EnteroLargo entero2){
			EnteroLargo entero3;
			
			if (tope > entero2.tope){
				for (int i = entero2.tope; i < tope; i++ )
					entero2.entero_reves[i] = 0;
				
				entero2.tope = tope;
			}
			
			if (!Es_negativo() && !entero2.Es_negativo()){
				
				entero3.tope = 0;
				
				for (int i = 0; i < tope; i++){
					if (entero_reves[i] >= entero2.entero_reves[i])
						entero3.entero_reves[i] = entero_reves[i] - entero2.entero_reves[i];
					
					
					if (entero_reves[i] < entero2.entero_reves[i]) {
						entero3.entero_reves[i] = entero_reves[i] + 10 - entero2.entero_reves[i];
						entero2.entero_reves[i + 1] += 1;
					}
					
					
					if (i == tope - 1 && (entero_reves[i] == entero2.entero_reves[i])){
						entero3.tope -= 1;
					}
						
						
					entero3.tope += 1;
					
				}
				
				for (int i = 0; i < entero3.tope; i++ ){
					entero3.entero[i] = entero3.entero_reves[i];
					
					
				}
				
				entero3.Dar_la_vuelta();
				
				
				return entero3;
				
			}
		}
		
		
		
};

int main(){
	EnteroLargo entero1(300);
	EnteroLargo entero2(199);
	EnteroLargo entero3;
	
	entero3 = entero1.Suma(entero2);
	
	entero3.Mostrar();
	
}
