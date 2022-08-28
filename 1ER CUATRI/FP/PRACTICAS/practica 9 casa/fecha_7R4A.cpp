#include <iostream>

using namespace std;

bool Fecha_corr (int dia, int mes, int anio){
	bool es_bisiesto;
	
	es_bisiesto = anio % 4 == 0;
	
	if (dia > 31 || mes > 12)
		return false;
	
	else {
		if (es_bisiesto){
			if (mes == 2 && dia > 29)
				return false;		
		}
		
		else {
			if (mes == 2 && dia > 28)
				return false;
		}
		
		if (mes <= 7 && mes % 2 == 0 && mes != 2 && dia > 30)
			return false;
			
		if (mes >= 8 && mes % 2 != 0 &&  dia > 30)
			return false;
			
		else 
			return true;
	}
}

int main(){
	int dia, mes, anio;
	bool valida;
	
	cout << "Introduce una fecha: ";
	cin  >> dia >> mes >> anio;
	
	valida = Fecha_corr(dia, mes, anio) == true;
	
	if (valida)
		cout << "La fecha es valida.";
		
	else 
		cout << "La fecha no es valida.";
}
