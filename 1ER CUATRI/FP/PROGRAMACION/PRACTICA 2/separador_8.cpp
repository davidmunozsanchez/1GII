/*	Programa para separar con espacios los numeros enteros de tres digitos
	introducidos por el usuario. Apostamos por tratar con divisiones enteras 
	y restos, ya que tratamos la entrada como un entero. Si tratásemos la entrada
	como un string, podríamos aplicar el programa a números más grandes o a otros 
	tipos de datos de esta forma (con un bucle):

	#include <iostream>

	using namespace std;

	int main(){
		string numero;
	
		cout << "Introduce el numero a separar: " ;
		cin  >> numero ;
		cout << "\n" ; 
	
		for (int i = 0; i < numero.size(); i++){
		
		cout << numero[i] << " " ;
	}
*/

#include <iostream>			// Incluimos los recursos matematicos

using namespace std;


int main(){								// Programa princiapl
	int numero;							// Declaramos una variable para el numero que se introduzca
	int primera, segunda, tercera;		// Y otras dos para las cifras que separemos
	
	cout << "Introduce el numero de tres cifras a separar: " ;		// Pedimos el numero de tres cifras a separar
	cin  >> numero ;												// Asignamos ese entero a la variable numero
	
	primera = numero / 100 ;		// Con la division entera entre cien extramos las centenas
	numero = numero % 100 ;			// El numero con el que trataremos sera el mismo elminando las centenas (resto entre 100)
	segunda = numero / 10 ;			// Al igual que con las centenas, extraemos las decenas
	numero = numero % 10 ; 			// De la misma manera, eliminamos las decenas (resto entre 10)
	tercera = numero ;				// El numero que nos queda ya conforma las unidades
	
	cout << "\n" << primera << " " << segunda << " " << tercera << "\n\n" ; 		// Mostramos los datos al usuario
	system ("pause") ; 			// Anadimos una pausa para que el usuario finalice cuando desee

}	
