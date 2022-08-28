/*	Programa para diferenciar problemas de precision y desbordamiento
*/

#include <iostream>
using namespace std;

int main()
{
	int		chico, chico1, chico2;		//Declaracion de variables
	long	grande;
	double	resultado_c, real1, real2;
	double	resultado_d;
	double	real, otro_real;
	float	chico_g;
	double 	grande_g;


    cout.precision(20);

	// A

	chico1 = 123456789;
	chico2 = 123456780;
	chico = chico1 * chico2;
	
	cout << "EJERCICIO A\n\n";
	cout << "chico1 = "  << chico1 << "\n\n";
	cout << "chico2 = "  << chico2 << "\n\n";
	cout << "chico = chico1 * chico2: " << chico << "\n\n";
	cout << "resultado_a = " << chico << "\n\n";

	// El resultado debía ser de orden mayor, imposible de guardar en un int

    // B
    
    chico1 = 123456789;
    chico2 = 123456780;
    grande = chico1 * chico2;
    
    cout << "EJERCICIO B\n\n";
    cout << "chico1 = "  << chico1 << "\n\n";
    cout << "chico2 = "  << chico2 << "\n\n";
    cout << "grande = chico1 * chico2" << "\n\n";
    cout << "grande = " << grande << "\n\n";  

    // Es erroneo. A pesar de que grande sea un long, se desborda previamente la multiplicacion de enteros
    
	// C
	
	real1 = 123.1;
	real2 = 124.2;
	resultado_c = real1 * real2;

	cout << "EJERCICIO C\n\n";
	cout << "real1 = " <<  real1 << "\n\n";
	cout << "real2 = " <<  real2 << "\n\n";
	cout << "resultado_c = real1 * real2" << "\n\n";
	cout << "resultado_c = " << resultado_c << "\n\n";

	// Correcto. Aunque hay una cierta imprecision en los valores de los reales.
	

	// D

	real1 = 123456789.1;
	real2 = 123456789.2;
	resultado_d = real1 * real2;

	cout << "EJERCICIO D\n\n";
	cout << "real1 = " << real1 << "\n\n";
	cout << "real2 = " << real2 << "\n\n";
	cout << "resultado_d = real1 * real2" << "\n\n";
	cout << "resultado_d = " << resultado_d << "\n\n"; // 

	// Como el resultado tiene mas de 16 digitos, hay un claro problema de imprecision

	// E

	real = 2e34;
	otro_real = real + 1;
	otro_real = otro_real - real;

	cout << "EJERCICIO E\n\n";
	cout << "real = " << real << "\n\n";
	cout << "otro_real = real + 1" << "\n\n";
	cout << "otro_real = otro_real - real" << "\n\n";
	cout << "otro_real = " << otro_real << "\n\n";  


	/* 
	Cabría esperar el resultado 1, pero como real tiene más de 16 digitos su representacion 
	no es exacta, de forma que al sumar 2e34 + 1, nos sigue quedando 2e34, por lo que al final resulta 0
	*/

    // F
    
	real = 1e+300;
	otro_real = 1e+200;
	otro_real = real * otro_real;

	cout << "EJERCICIO F\n\n";
	cout << "real1 = 1e+300\n\n";
	cout << "real2 = 1e+200\n\n";
	cout << "otro_real = real * otro_real" << "\n\n";
	cout << "otro_real = " << otro_real << "\n\n";
	
	// Infinito. Los reales en coma flotante no se "desbordan" de la misma forma que los int. 

	// G
	
    grande_g = 2e+150;
    chico_g = grande_g;

	cout << "EJERCICIO G\n\n";
	cout << "grande_g = " << grande << "\n\n";
	cout << "chico_g = grande_g" << "\n\n";
	cout << "chigo_g = " << chico_g << "\n\n";

	// Infinito. Igual que el anterior, aunque ahora se desborda un float.
	
}
