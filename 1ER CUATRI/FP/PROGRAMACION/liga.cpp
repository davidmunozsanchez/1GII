/*	Programa para trabajar con matrices y clases, aplicandolo a una competicion.
	Hay que generar una matriz de la competicion y calcular los resultados finales, devolviendo
	la puntuacion de cada equipo
*/

#include <iostream>
#include <vector>

using namespace std;

// Datos constantes globales
const int FILAS_MAX = 100;
const int COLUMNAS_MAX = 100;

class Liga{
	public:
		char matriz_liga[FILAS_MAX][COLUMNAS_MAX];	// Matriz para almacenar los resultados
		int num_equipos;							// Numero de equipos
		
		/* 	Metodo privado que devuelve un vector con los resultados ordenados desde el primer equipo
			hasta el ultimo. Usa un switch para ir calculando cada puntuacion y al final lo aniade al vector
		*/
		vector<int> CalculoPuntos(){
			vector<int> puntuacion_final;
			int contador = 0;
			int suma;
			
			while (contador < num_equipos){
				suma = 0;
				// Suma de las filas
				for (int i = 0; i < num_equipos; i++){
					switch(matriz_liga[contador][i]){
						case '1':
							suma += 3;
							break;
							
						case '2':
							suma += 0;
							break;
						
						case 'X':
							suma += 1;
							break;		
					}
				}
				
				// Suma de las columnas
				for (int i = 0; i < num_equipos; i++){
					switch(matriz_liga[i][contador]){
						case '1':
							suma += 0;
							break;
						
						case '2':
							suma += 3;
							break;
							
						case 'X':
							suma += 1;
							break;
					}
				}
				
				puntuacion_final.push_back(suma);
				contador ++;
				
				
			}
			
			return puntuacion_final;
			
		}
		
		void Mostrar(){
			for (int i= 0; i < num_equipos; i++){
				for (int j = 0; j < num_equipos; j++){
					if (i != j)
						cout << matriz_liga[i][j] << " ";
					
					else 
						cout << 'I' << " ";
					
				}
				cout << endl;
			}	
		}
		
		// Metodo privado para mostrar los resultados
		void MostrarResultados(vector<int> puntuacion){
			for (int i = 0; i < puntuacion.size(); i++){
				cout << "Equipo " << i + 1 << ": " << puntuacion[i] << " punto(s)." << endl;
			}
		}
};

// Clase para generar un objeto liga
class GeneradorLiga{
	public:
		
		/* 	Como los datos de Liga son publicos, puedo modificarlos desde este metodo,
			que se encarga de leer una matriz redireccionada desde un fichero
		*/
		Liga Lee(){
			Liga liga1;
			char elemento;
			int num_equipos;
			
			cin >> num_equipos;
			
			for (int i= 0; i < num_equipos; i++){
				for (int j = 0; j < num_equipos; j++){
					if (i != j){
						cin >> elemento;
						liga1.matriz_liga[i][j] = elemento;
					}
						
							
				}
			}
			
			liga1.num_equipos = num_equipos;
			
			return liga1;
		}
};

int main(){
	GeneradorLiga liga1;
	Liga liga_oficial;
	vector <int> resultados;
	
	liga_oficial = liga1.Lee();
	liga_oficial.Mostrar();
	liga_oficial.MostrarResultados(liga_oficial.CalculoPuntos());
	
	
}
