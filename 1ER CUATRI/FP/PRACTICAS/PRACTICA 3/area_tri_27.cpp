/* Programa para calcular el area de un triangulo a partir de dos de sus lados
   y el angulo que forman, mediante la expresion: are = 0.5 * a * b * sin(angulo).
   Suponemos que el usuario introduce los lados en centimetros y el angulo en grados.
*/

#include <iostream>				// Inclusion de los recursos E/S y matematicos
#include <cmath>

using namespace std;

int main(){                      // Programa principal
   const double PI = 3.141592;   // Declaramos la constante PI y 4 variables más
   double lado1, lado2;
   double angulo;
   double area;
   
   cout << "Introduce el valor de un lado: ";      // Pedimos los datos al usuario
   cin  >> lado1 ;                                 // y lo asignamos a las variables
   cout << "Introduce el valor del otro lado: " ;
   cin  >> lado2 ;
   cout << "Introduce el valor del angulo que forman estos lados (en grados): " ;
   cin  >> angulo;
   
   angulo = angulo * (2*PI / 360) ;             // Con esta expresion pasamos los grados a radianes, y reasignamos angulo
   area = 0.5 * lado1 * lado2 * sin(angulo);    // Con esta expresion calculamos el area
   
   cout << "\nEl valor del area es: " << area << " cms cuadrados.\n\n" ;      //Mostramos el resultado final
   system ("pause");

}
