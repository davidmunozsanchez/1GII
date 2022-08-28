/*	Programa que toma los datos fiscales de una persona y reajusta
	su renta bruta segun diversos criterios
*/

#include <iostream>

using namespace std;

int main(){
	// Declaramos  constantes para facilitar la comprension del codigo
    const double VARIACION_PENSIONISTA = 1;
    const double VARIACION_AUTONOMO = 3;
    const double VARIACION_SALARIO_BAJO = 6;
    const double VARIACION_SALARIO_NORMAL_SOLTERO = 10;
    const double VARIACION_SALARIO_NORMAL_CASADO = 8;
    const double VARIACION_RESTO = 2;
	
	// Declaramos booleanos, y distintos doubles
	bool autonomo, pensionista, casado, salario_menor;
	double renta_bruta, reten_ini, renta_neta, reten_fin;
	
	// Leemos por teclado
	cout << "LEE ATENTAMENTE ANTES DE INTRODUCIR DATOS\n\n";
	cout << "Si lo que se pregunta es verdad, introduce un 1, y si no, un 0\n\n";
	cout << "\nEs autonomo? ";
	cin  >> autonomo;
	cout << "\nEs pensionista? ";
	cin  >> pensionista;
	cout << "\nEsta casado? ";
	cin  >> casado;
	cout << "\nIntroduce el salario bruto del trabajador: ";
	cin  >> renta_bruta;
	cout << "\nIntroduce la retencion inicial del trabajador (sin el simbolo %): ";
	cin  >> reten_ini;
	
	// Planteamos las distintas posibilidades con estructuras condicionales
	if (autonomo)
		reten_fin = reten_ini - reten_ini * (VARIACION_AUTONOMO/100);
	
	else {
		if (pensionista)
			reten_fin = reten_ini + reten_ini * (VARIACION_PENSIONISTA/100);
		
		else {
		
			reten_fin = reten_ini + reten_ini * (VARIACION_RESTO/100);
			
			if (renta_bruta < 20000)
				reten_fin = reten_ini + reten_ini * (VARIACION_SALARIO_BAJO/100);
			
			if ((renta_bruta > 20000) && (casado == true))
				reten_fin = reten_ini + reten_ini * (VARIACION_SALARIO_NORMAL_CASADO/100);
			
			if ((renta_bruta > 20000) && (casado == false))
				reten_fin = reten_ini + reten_ini * (VARIACION_SALARIO_NORMAL_SOLTERO/100);
		}
	}
	
	// Calculamos la renta neta
	renta_neta = renta_bruta - renta_bruta * (reten_fin/100);
	
	// Imprimimos el resultado final
	cout << "\nLa renta neta del trabajador es: " << renta_neta << " euros\n\n";
}
