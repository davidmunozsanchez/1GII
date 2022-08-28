/* Programa para trabajar con un numero racional haciendo uso de clases
*/

#include <iostream>
#include <algorithm>

using namespace std;

class Racional{
   private:
      int numerador; //Almacena el entero correspondiente al numerador
      int denominador; //Almacena el entero correspondiente al numerador
      
      // Funcion privada para calcular el mcd de dos numeros enteros
      int gcd(){
         int maximo;
         
         maximo = __gcd(numerador, denominador);
         
         return maximo; 
      }
   
   public:
   		//Constructor publico por defecto
      	Racional(){}
      
      	//Constructor a partir de dos numeros enteros
      	Racional(int num, int den){
        	numerador = num;
         	denominador = den;
      }
      	
      	// Reduccion de la fraccion, calculando previamente el mcd
      	void Irreducible(){
         	int comun = gcd();
         
         	numerador /= comun;
         	denominador /= comun;  
      }
      
      /* Metodo publico que devuelve un booleano. Si el objeto al que le aplicamos 
         el metodo es menor que el objeto que pasamos como parametro, devolvemos true,
         si es mayor, devolvemos false
      */
      	bool Es_menor(Racional num_racional){
         	if (denominador < num_racional.denominador)
            	return false;
            
         	else if (denominador > num_racional.denominador)
            	return true;
            
         	else{
            	if (numerador > num_racional.numerador)
               		return false;
               
            	else if (numerador < num_racional.numerador)
               		return true;
               
            	else 
              	 	return true;
         }
       
         
      }
      
      	/*	Metodo privado para mostrar la representacion de un racional segun una 
      		precision de digitos decimales dada. Para ello, usamos el algoritmo de la division de enteros.
      		La primera vez que el numerador (dividendo), sea mas chico que el denominador (divisor), 
      		imprimimos un 0,. Las demas veces multiplicamos el numerador por 10. Adema´s. el numerador es
      		el resto de la division del antiguo entre el denominador
      	*/
      	void MostrarRacional(int precision){
         	Irreducible();
         	int contador = 0;
         	int elemento;
         	bool primera_vez = true;
         
         	while (contador < precision + 1){
              	elemento = numerador / denominador;
              	cout << elemento;
                  
              	numerador = numerador % denominador;
              
              	if (numerador < denominador){
                  	if (primera_vez){
                     	cout << ",";
                     	primera_vez = false;
                  	}
                  
                  	numerador *= 10;  
              	}
              	contador ++;
         	}
      	}
      
      	// Metodo publico para mostrar un numero decimal
      	void Mostrar(){
         	cout << numerador << "/" << denominador << endl;
     	}
   
   
};

int main(){
   Racional racional1 (1500,3);
   Racional racional2 (5,6);
   
   racional1.MostrarRacional(30);
}
