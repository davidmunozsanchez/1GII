#include <iostream>
#include <cmath>

using namespace std;

int main (){
	int numero, numero2, contador_cifras = 0, cifra;
	int i;
	bool contar;
	
	cout << "Introduce un numero a desglosar en cifras: ";
	cin  >> numero;
	
	contar = true;
	numero2 = numero;
	
	while (contar){
		numero2 /= 10;
		contador_cifras++;
		
		if (numero2 == 0)
			contar = false;
	}
	
	for (i = contador_cifras - 1; i >= 0; i--){
		cifra = numero / (int) pow (10, i);
		numero -= cifra * (int) pow(10, i);
		cout << cifra << " ";
	}
}
