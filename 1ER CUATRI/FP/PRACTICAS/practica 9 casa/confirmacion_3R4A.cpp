#include <iostream>

using namespace std;

char Confirmacion (char letra){
	
	cout << "Confirmar (S/N)? ";
	cin  >> letra;
	
	if (letra == 'N' || letra == 'n')
		return false;
		
	if (letra == 'S' || letra == 's')
		return true;
}

int main(){
	char valor = 's';
	bool resultado;
	
	resultado = Confirmacion (valor);
	
	cout << resultado;
}
