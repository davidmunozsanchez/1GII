#include <iostream>

using namespace std;

int main (){
	int numero1, suma = 0;
	int i, j;
	bool hacer_suma;

	cout << "Introduce un numero tope: ";
	cin  >> numero1;
	
	hacer_suma = true;
	
	for (i = numero1; i > 0; i--){
		
		suma = 0;
		
		for ( j = 0; suma <= i; j++){
			
			suma += j;
			
			if (suma == i)
				cout << suma << " ";
			
		}
	}

	
}
