/*	Programa para jugar al tres en raya de forma generalizada, dando el tamanio del tablero
	y las fichas necesarias para el m en raya
*/

#include <iostream>

using namespace std;

// Struct para almacenar parejas de enteros que corresponde a la posicion de la ficha
struct Posicion{
   int fila;
   int columna; 
};

// Clase TresRaya
class TresRaya{
   private:
      static const int MAXIMO = 100;	// Constante para el tamanio de la matriz
      int tablero[MAXIMO][MAXIMO];		// Matriz tablero
      int tamanio_tablero;				// Tamanio maximo del tablero
      int tresraya;						// Entero que hace referencia al numero de fichas que hay que tener en linea
      
    /* 	Metodo privado que se encarga de comprobar si existe una línea con m fichas en raya,
    	le pasamos como parametro el jugador que deseamos comprobar, y va recorriendo todas las 
    	fichas de ese jugador y comprobando si hay mas fichas en linea a su derecha
    */
    bool CompruebaFila(int jugador){
      	int contador_filas = 1;
      	int fila = 0, columna = 0;
      	bool tres_en_raya = false;
      	bool filas = true, columnas = true;
      	bool devolver = false;
      	
      	while (fila < tamanio_tablero && filas){
      		while (columna < tamanio_tablero && columnas){
      			if (tablero[fila][columna] == jugador){
      				if (tablero[fila][columna] == tablero[fila][columna + 1])
      					contador_filas += 1;
      			
      				if (contador_filas == tresraya){
      					devolver = true;
      					columnas = filas = false;
					}
				}
				
				columna++;
			}
			columna = 0;
			contador_filas = 1;
			fila++;	
		}
		return devolver;
		
	}
	
	/* 	Metodo que sirve para lo mismo que al anterior pero lo comprueba para las columnas
		en vez de para las filas
	*/
	bool CompruebaColumna(int jugador){
      	int contador_columnas = 1;
      	int fila = 0, columna = 0;
      	bool tres_en_raya = false;
      	bool filas = true, columnas = true;
      	bool devolver = false;
      	
      	while (columna < tamanio_tablero && columnas){
      		while (fila < tamanio_tablero && filas){
      			if (tablero[fila][columna] == jugador){
      				if (tablero[fila][columna] == tablero[fila + 1][columna])
      					contador_columnas += 1;
      			
      				if (contador_columnas == tresraya){
      					devolver = true;
      					columnas = filas = false;
					}
				}
				
				fila++;
			}
			fila = 0;
			contador_columnas = 1;
			columna++;	
		}
		return devolver;	
	}
	
	/* 	Metodo privado que se encarga de comprobar las diagonales a partir de la ficha del jugador.
		Devuelve un booleano si hay m fichas en raya
	*/
	bool CompruebaDiagonal(int jugador){
      	int contador_diagonal1 = 1, contador_diagonal2 = 1;
      	int fila = 0, columna = 0;
      	bool tres_en_raya = false;
      	bool filas = true, columnas = true;
      	bool devolver = false;
      	bool seguir_comprobando = true;
      	int copia_fila_derecha, copia_columna_derecha, copia_fila_izquierda, copia_columna_izquierda;
      	
      	while (fila < tamanio_tablero && filas){
      		while (columna < tamanio_tablero && columnas){
				if (tablero[fila][columna] == jugador){
				  	copia_fila_derecha = fila;
      				copia_columna_derecha = columna;
      				copia_fila_izquierda = fila;
      				copia_columna_izquierda = columna;
				
					while (seguir_comprobando){
      					if (tablero[copia_fila_derecha][copia_columna_derecha] == tablero[copia_fila_derecha + 1][copia_columna_derecha + 1]){
      						contador_diagonal1 += 1;
      						copia_fila_derecha += 1;
					  		copia_columna_derecha += 1;
					  	}
					  	else if (tablero[copia_fila_izquierda][copia_columna_izquierda] == tablero[copia_fila_izquierda + 1][copia_columna_izquierda - 1]){
					  		contador_diagonal2 += 1;
      						copia_fila_izquierda += 1;
					  		copia_columna_izquierda -= 1;
						  }
					  	else 
					  		seguir_comprobando = false;
      				
      					if (contador_diagonal1 == tresraya ||contador_diagonal2 == tresraya){
      						devolver = true;
      						seguir_comprobando = false;
      						columnas = filas = false;
					  	}
					}
				}
				seguir_comprobando = true;
				columna++;
			}
			columna = 0;
			contador_diagonal1 = 1;
			fila++;	
		}
		return devolver;
	}
      	
   public:
      TresRaya(){} // Constructor por defecto
      
      	/* 	Constructor dado el tamanio del tablero y el numero de fichas que
      		hay que tener en raya
    	*/
      TresRaya(int tamanio, int m){
         tamanio_tablero = tamanio;
         tresraya = m;
      }
      
      /* Metodo publico que se encarga de mostrar el tablero tal y como se encuentra en
      	ese momento
    	*/
      void MostrarTablero(){
         for (int i = 0; i < tamanio_tablero; i++){
            for (int j = 0; j < tamanio_tablero; j++)
               cout << tablero[i][j] << " "; 
            
            cout << endl;
         }
      }
      
      /* Metodo publico que se encarga de colocar una ficha dado el jugador
      	y la posicion
    	*/
      void MoverFicha (int jugador, Posicion posicion){
         if (jugador == 1)
            tablero[posicion.fila][posicion.columna] = 1;
         if (jugador == 2)
            tablero[posicion.fila][posicion.columna] = 2;  
      }
      
      	/* Metodo publico que se encarga de comprobar si algun jugador tiene m fichas en raya
      	*/
      	bool TresEnRaya(int jugador){
         	return CompruebaDiagonal(jugador) || CompruebaFila(jugador) || CompruebaColumna(jugador);
		}
};

int main(){
  	Posicion posicion;
  	TresRaya tablero1(4,3);
  	
  	for (int i = 0; i < 3; i++){
  		cin >> posicion.fila >> posicion.columna;
  		tablero1.MoverFicha(1, posicion);
	  }
	  
	  tablero1.MostrarTablero();
	  cout<<tablero1.TresEnRaya(1);
  		
  		
  	
  	
	 

	  
}
