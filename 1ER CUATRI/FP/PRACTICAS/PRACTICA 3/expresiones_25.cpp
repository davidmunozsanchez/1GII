/* Programa para transformar diversas formulas matematicas a c++ usando la 
   libreria cmath
*/

#include <iostream>			// Inclusion de recursos E/S y matematicos
#include <cmath>

using namespace std;

int main(){										// Programa principal
   double x, y, h;								// Declaracion de variables para comprobar las expresiones
   double expresion1, expresion2, expresion3;
   
   cout << "Introduce el valor de x: " ;		// Introduccion de variables por parte del usuario
   cin  >> x ;									// y asignacion
   cout << "Introduce el valor de h: " ;
   cin  >> h ;
   cout << "Introduce el valor de y: " ;
   cin >> y ;
   
   expresion1 = (1 + x * x / y) / (pow(x, 3) / (1 + y)) ;	// Expresiones matematicas
   expresion2 = (1 + sin(h) / 3 - cos(h) / 7) / (2 * h) ;
   expresion3 = sqrt (1 + pow(exp(x) / (x * x), 2)) ;
   
   cout << expresion1 << " " << expresion2 << " " << expresion3 << "\n\n" ;	// Imprimimos en pantalla para comprobar las expresiones
   system ("pause") ;

}
