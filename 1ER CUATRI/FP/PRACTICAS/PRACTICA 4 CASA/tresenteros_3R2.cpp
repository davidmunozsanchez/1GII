/*	Programa para decir si tres enteros estan ordenados
	en forma decreciente o creciente
*/

#include <iostream>

using namespace std;

int main(){
	int ent1, ent2, ent3;
	bool ordenadoscrec, ordenadosdecrec;
	
	// Introduccion de datos
	cout << "Introduce los tres enteros, separados por un espacio: ";
	cin  >> ent1 >> ent2 >> ent3;
	
	// Evaluamos las expresiones
	ordenadoscrec = (ent1 <= ent2) && (ent2 <= ent3) && (ent1 <= ent3);
	ordenadosdecrec = (ent1 >= ent2) && (ent2 >= ent3) && (ent1 >= ent3);
	
	// Diferenciamos dos casos
	if (ordenadoscrec || ordenadosdecrec)
		cout << "Estan ordenados";
	
	else 
		cout << "No estan ordenados";
}

