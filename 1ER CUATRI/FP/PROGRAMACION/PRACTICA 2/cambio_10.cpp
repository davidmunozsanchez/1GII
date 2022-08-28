/*	Programa para dar el cambio de una cantidad de dinero usando monedas de 1 euro, 50 centimos,
	20 centimos, 10 centimos y 5 centimos. Cabe decir que se puede realizar sin condicionales, pero
	si se añaden queda mucho más concisa la salida, mostrando solo los datos necesarios para el usuario.
	
	Suponemos ademas que todo el dinero se introduce en centimos y que la entrega siempre sera mayor o igual
	al precio.
*/

#include <iostream>			// Incluimos los recursos E/S

using namespace std;

int main(){			//Programa principal

	int precio, entrega, devol;						// Declaramos variables para manejar los datos de entrada (precio y entrega) y la devolucion a desglosar
	int noasig, eur1, cen50, cen20, cen10, cen5;	// Declaramos variables para manejar las monedas a devolver y si queda dinero sin asignar (no asig)
	
	cout << "Introduce el precio del producto: " ;					// Se piden el precio y el dinero entregado
	cin  >> precio ;												// y se asigna a precio y entrega respectivamente
	cout << "Introduce el dinero ingresado por el cliente: " ,
	cin  >> entrega ;
	
	devol = entrega - precio ;			// Con esta expresion asignamos a devol la cantidad a devolver
	
	if (devol/100 >= 1){											// En el caso de que la division entera de devol entre 100 cents de uno, podremos dar monedas de 1 euro
		cout << "\n" << devol / 100 << " moneda(s) de 1 euro\n" ;	// Mostramos en pantalla las monedas de 1 euro a devolver
		devol = devol % 100;										// devol cambia de valor ahora, puesto que hemos extraido monedas de 1 euro (resto de la division entre 100)
	}
	
	if (devol/50 >= 1){												// En el caso de que la division entera de devol entre 50 cents de uno, podremos dar monedas de 1 euro	
		cout << "\n" << devol / 50 << " moneda(n) de 50 cents\n" ;	// Mostramos en pantalla las monedas de 50 cents a devolver
		devol = devol % 50;											// devol cambia de valor ahora, puesto que hemos extraido monedas de 50 cents (resto de la division entre 50)
}
	if (devol/20 >= 1){												// En el caso de que la division entera de devol entre 20 cents de uno, podremos dar monedas de 20 cents
		cout << "\n" << devol / 20 << " moneda(s) de 20 cents\n" ;	// Mostramos en pantalla las monedas de 20 cents a devolver
		devol = devol % 20;											// devol cambia de valor ahora, puesto que hemos extraido monedas de 20 cents (resto de la division entre 20)
	}
	
	if (devol/10 >= 1){												// En el caso de que la division entera de devol entre 10 cents de uno, podremos dar monedas de 10 cents
		cout << "\n" << devol / 10 << " moneda(s) de 10 cents\n" ;	// Mostramos en pantalla las monedas de 10 cents a devolver
		devol = devol % 10;											// devol cambia de valor ahora, puesto que hemos extraido monedas de 10cents (resto de la division entre 10)
	}
	
	if (devol/5 >= 1){												// En el caso de que la division entera de devol entre 5 cents de uno, podremos dar monedas de 5 cents
		cout << "\n" << devol / 5 << " moneda(s) de 5 cents\n" ;	// Mostramos en pantalla las monedas de 5 cents a devolver
		devol = devol % 5;											// devol cambia de valor ahora, puesto que hemos extraido monedas de 5 cents (resto de la division entre 5)
	}
	
	if (devol != 0){												// Si nos sigue quedando dinero a devolver, lo mostraremos en pantalla tal cual
		noasig  = devol;
		cout << "\nQueda(n) sin asignar " << noasig << " cent(n)\n";
	}
	
	cout << "\n" ;			// Separamos el pause sea cual sea el resultado
	system ("pause") ;		// El usuario termina el problema cuando quiera
}
	

