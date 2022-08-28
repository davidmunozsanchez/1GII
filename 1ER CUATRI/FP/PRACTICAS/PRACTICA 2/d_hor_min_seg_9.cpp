/*	Programa para optimizar una entrada de horas, minutos y segundos en días, horas,
	minutos y segundos, en su rango correspondiente. Importante partir de que un minuto 
	son 60 segundos, 1 hora son 60 minutos y un dia 24 horas
*/


#include <iostream>		// Incluimos los recursos E/S

using namespace std;

int main(){		//Programa principal
	int dias, horas, minutos, segundos;		// Declaramos variables enteras para dias, horas, minutos y segundos
	
	cout << "Introduzca las horas: " ;		// Pedimos horas, minutos y segundo por teclado
	cin  >> horas ; 						// y las asignamos a sus correspondientes variables
	cout << "Introduzca los minutos: " ;
	cin  >> minutos ;
	cout << "Introduzca los segundos: " ;
	cin  >> segundos ;
	
	if (segundos >= 60){						// En el caso de haya mas de 60 segundos ya se puede agrupar en minutos
		
		minutos = minutos + segundos / 60 ;		// Los minutos corresponen a la division entera entre 60 más
		segundos = segundos % 60 ; 				// lo que ya había sido introducido. Los segundos restantes los asignaremos a segundos
		
	}
	
	if (minutos >= 60){							// En el caso de haya mas de 60 minutos ya se puede agrupar en horas
		
		horas = horas + minutos / 60 ;			// Las horas corresponen a la division entera entre 60 más 
		minutos = minutos % 60 ;				// lo que ya había sido introducido. Los minutos restantes los asignaremos a minutos
		
	}
	
	if (horas >= 24){							// En el caso de haya mas de 24 horas ya se puede agrupar en horas
		
		dias = dias + horas / 24 ;				// Los dias corresponen a la division entera entre 24 más 
		horas = horas % 24 ;					// lo que ya había sido introducido. Las horas restantes las asignaremos a horas
		 
	}
	
	cout << "\n" << dias << " dia(s), " << horas << " hora(s), " ;		// Mostramos los resultados al usuario
	cout << minutos << " minuto(s), " << segundos << " segundo(s).\n\n" ;	
	system("pause") ;		// Dejamos que el usuario acabe el programa cuando desee
}
