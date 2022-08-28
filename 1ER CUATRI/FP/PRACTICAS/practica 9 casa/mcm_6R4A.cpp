#include <iostream>
#include <algorithm>

using namespace std;


int MCM (int a, int b){
	
	int maximo, minimo;
	int i;
	
	for (i = 1; i < a && i < b; i++){
		if (a % i == 0 && b % i == 0)
			maximo = i;
	}
	
	minimo = (a * b) / maximo;
	
	return minimo;
}

int main(){
	int num1, num2, resultado;
	
	cout << "Introduce dos numeros para hallar el MCM: ",
	cin  >> num1 >> num2;
	
	resultado = MCM(num1, num2);
	
	cout << "El MCM es " << resultado;
	
	
}
