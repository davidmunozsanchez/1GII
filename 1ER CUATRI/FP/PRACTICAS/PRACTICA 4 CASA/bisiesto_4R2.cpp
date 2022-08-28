/*	Programa para evaluar si un numero es bisiesto o no, teniendo en cuenta que
	los anios que sean multiplo de cuatro y no sean mulitplos de 100, serán bisiestos.
	Los multiplos de 400 son bisiestos tambien
*/

#include <iostream>

using namespace std;

int main (){
	int anio;
	bool es_bisiesto;
	
	// Introducimos los datos
	cout << "Introduce el anio a evaluar: ";
	cin  >> anio;
	
	// Asignamos al booleano true or false, segun sea bisiesto o no
	es_bisiesto = (anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0;
	
	// Evaluamos el booleano e imprimimos el resultado en pantalla
	if (es_bisiesto)
		cout << "El anio " << anio << " es bisiesto\n\n";
	
	else
		cout << "El anio " << anio << " no es bisiesto\n\n";
}
