/*	Programa para calcular el beneficio que obtiene un diseñador y tres fabricantes
	a partir de la ganancia de la empresa, sabiendo que el diseñador obtiene el doble
	de beneficio que cada uno de los fabricantes
*/

#include <iostream>		// Incluimos los recursos E/S

using namespace std;

int main(){					// Programa principal
	double total;			// Declaramos las variables
	double disenador;		// total, disenador y fabricante
	double fabricante;
	
	cout << "Introduzca la ganancia total de la empresa: " ;	// Se introduce la ganancia total de la empresa
	cin  >> total ;												// Se asigna a la variable total
	
	disenador = 0.4 * total ;		// Mediante esta expresion hallamos las ganancias del disenador
	fabricante = 0.2 * total ;		// Mediante esta expresion hallamos las ganancias de uno de los fabricantes
	
	cout << "\nEl disenador gana " << disenador ;											// Imprimimos lo que ganan el diseñador y los fabricantes
	cout << " euro(s) y los fabricantes " << fabricante << " euro(s) cada uno.\n\n" ;		// (que ganan todos el mismo porcentaje)
	system ("pause") ;		//Añadimos una pausa para que el usuario finalice cuando quiera
	
}
