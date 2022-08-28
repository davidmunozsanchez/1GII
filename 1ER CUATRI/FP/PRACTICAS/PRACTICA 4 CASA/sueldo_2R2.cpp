/*	Programa que aplica subida de salarios en base a la edad 
	y los ingresos de una persona */

#include <iostream>

using namespace std;

struct persona{
	int edad;
	double ingresos;
};

int main (){
	persona persona1;
	double porcentaje;
	
	/* Primero voy a aplicar el programa mezclando cómputos y E/S 
	   dentro de las mismas estructuras condicionales */
	
	cout << "Introduce la edad de la persona y sus ingresos, separandolos con espacios: ";
	cin  >> persona1.edad >> persona1.ingresos;
	
	bool si_sube = persona1.edad > 65 && persona1.ingresos < 300;
	
	if (si_sube){
		persona1.ingresos = persona1.ingresos * 1.05;
		
		cout << "El nuevo salario es " << persona1.ingresos << "\n\n";
	}   
	
	else 
		cout << "No es aplicable la subida.\n\n";
	
	
	/* Ahora voy a realizarlo sin mezclar cómputos con entradas
		y salidas en los condicionales, contando con los datos introducidos anteriormente 
	
	bool si_sube = persona1.edad > 65 && persona1.ingresos < 300;
	
	if (si_sube)
		porcentaje = 1.05;
	
	persona1.ingresos = persona 1.ingresos * porcentaje;
	
	if (si sube)
		cout << "El nuevo salario es " << persona1.ingresos;
	
	else
		cout << "No es aplicable";
	
	*/
	
	/*	A continuacion, voy a aplicar el mismo programa pero añadiendo una posibilidad mas
		de subida de salario, en el caso de que sea menor de 35. Además, si es inferior a 300 euros,
		se le subirá un 3 %, primero lo hare mezclando computos
	*/
	
	bool mayor = persona1.edad > 65;
	bool menor = persona1.edad < 35;
	bool sube_sal = persona1.ingresos < 300;
	
	if (mayor || menor){
		if (sube_sal){
			persona1.ingresos = persona1.ingresos * 1.07;
			
			cout << "El nuevo salario es " << persona1.ingresos << "\n\n";
		}
		
		else{
			persona1.ingresos = persona1.ingresos * 1.04;
			
			cout << "El nuevo salario es " << persona1.ingresos << "\n\n";
		}
	}
	
	else 
		cout << "No es aplicable la subida";
	
	/* 	Ahora voy a plantear el programa sin mezcla computos, de una manera
		mucho mas generalizada, teniendo en cuenta las variables utilizadas
		anteriormente
	
		if (mayor || menor){
			
			if (sube_sal)
				porcentaje = 1.07;
			
			else
				porcentaje = 1.04;
		}
		
		persona1.ingresos = persona1.ingresos * porcentaje;
		
		if (mayor || menor)
			cout << "El nuevo salario es "" << persona1.ingresos << "\n\n";
		
		else
			cout << "No es aplicable la subida\n\n";
		
	*/
			
	
	
	
}
