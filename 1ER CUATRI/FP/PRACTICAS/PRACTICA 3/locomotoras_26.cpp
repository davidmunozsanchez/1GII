/* Programa para calcular los metros que recorren dos locomotoras antes de 
   sufrir un accidente en un instante determinado, dadas la longitud de su ruta
   y sus respectivas velocidades.
*/

#include <iostream>		// Inclusiun recursos E/S

using namespace std;

int main(){                      // Programa principal
   double dis_sepa, vel1, vel2;  // Declaracion de variables
   double dist1, dist2;
   double inst_choque;
   
   cout << "Introduce la distancia que separa los puntos iniciales ";   // Asignacion de datos a las variables
   cout << "de partida de ambas locomotoras(m): ";                      // a partir de los datos introducidos por el usuario
   cin  >> dis_sepa ;
   cout << "Introduce la velocidad de la locomotora 1(m/s): " ;
   cin  >> vel1 ;
   cout << "Introduce la velocidad de la locomotora 2(m/s): " ;
   cin  >> vel2 ;
   
   inst_choque = dis_sepa / (vel1 + vel2) ;     // Calculo de el instante de choque 
   dist1 = vel1 * inst_choque ;                 // y de las distancias recorridas respectivamente
   dist2 = vel2 * inst_choque ;
   
   cout << "\nLa locomotora 1 recorre " << dist1 << " metros antes del choque" ;    // Mostramos el resultado en pantalla
   cout << " y la locomotora 2 " << dist2 << " metros.\n\n";
   systemm ("pause") ;		

}
