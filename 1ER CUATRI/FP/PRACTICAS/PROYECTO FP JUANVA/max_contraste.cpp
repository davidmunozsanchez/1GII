/*	Programa para maximizar el contraste de una imagen pgm, es decir,
	cambiando los bits menores de 125 a 0 y los mayores o iguales a 255
*/

#include <iostream>

using namespace std;

const int TAMANIO_MAX = 650;

void Max_Contraste(short int matriz[TAMANIO_MAX][TAMANIO_MAX], int filas, int columnas){
	for (int i = 0; i < filas; i++){
		for (int j = 0; j < columnas; j++){
			if (matriz[i][j] < 125)
				matriz[i][j] = 0;
			
			else
				matriz[i][j] = 255;
		}
		
	}
}

int main(){
	short int matriz[TAMANIO_MAX][TAMANIO_MAX];
	string elemento1;
	int filas, columnas, elemento3;
	
	cin >> elemento1;
	cin >> filas >> columnas;
	cin >> elemento3;
	
	for(int i = 0; i < filas; i ++){
      	for( int j = 0; j < columnas; j++)
        	cin >> matriz[i][j];
   	}
   
   Max_Contraste(matriz, filas, columnas);
   
   cout << elemento1 << endl;
   cout << filas << " " << columnas << endl;
   cout << elemento3 << endl;
   
   for (int i = 0; i < filas; i ++){
		for (int j = 0; j < columnas; j++){
			cout << matriz[i][j] << " ";
		}
		cout << endl;
   }
}
