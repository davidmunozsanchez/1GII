#include <iostream>

using namespace std;

int Maximo (int a, int b){
	if (a > b)
		return a;
	if (b > a)
		return b;
	else
		return a;	
}
int main(){
	const int TAMANIO_MAX = 100;
	int vector_final[TAMANIO_MAX];
	int matriz[2][TAMANIO_MAX];
	int componentes1, componentes2;
	int maximo;
	
	cout << "Introduce el numero de elementos del primer vector: ";
	cin >> componentes1;
	cout << "Introduce el primer vector ordenador de menor a mayor: ";
	for (int i = 0; i < componentes1; i++)
		cin  >> matriz[0][i];
		
	cout << "Introduce el numero de elementos del segundo vector: ";	
	cin >> componentes2;
	cout << "Introduce el segundo vector ordenador de menor a mayor: ";
	for (int i = 0; i < componentes2; i++)
		cin  >> matriz[1][i];
	
	maximo = Maximo(componentes1, componentes2);
	
	for (int i = 0; i <= maximo; i + 2){
		if (matriz[0][i-1] <= matriz[1][i-1]){
			vector_final[i] = matriz[0][i];
			vector_final[i+1] = matriz[1][i];
		}
		if (matriz[0][i-1] > matriz[1][i-1]){
			vector_final[i] = matriz[1][i];
			vector_final[i+1] = matriz[0][i];
		}		
	}
	
	for (int i = 0; i < componentes1 + componentes2; i++){
		cout << vector_final[i] << " ";
	}
		
	
	
}
