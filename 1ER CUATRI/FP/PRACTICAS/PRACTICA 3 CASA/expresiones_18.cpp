/*	Programa para evaluar distintas expresiones con resultados booleanos o de otro tipo
*/

#include <iostream>

using namespace std;

int main (){
	
	bool expresion1 = 2+3 < 5+8;
	cout << "2+3 < 5+8: " << expresion1 << ".\n\n";
	
	//Esta expresion es verdadera, nos devuelve el booleano 1.
	
	bool expresion2 = 2 < 3 < 4;
	cout << "2 < 3 < 4: " << expresion2 << ".\n\n";
	
	/* 	Aparentemente nos devuelve un resultado correcto, pero primero evalúa
		2<3, que devuelve 1, que es menor que 4. Por lo que si cambiamos el 3 por un 1400,
		la expresion final nos seguiria deolviendo 1 (true).
	*/
	
	double expresion3 = 7/3 + 4.0;
	cout << "7/3 + 4.0 = " << expresion3 << ".\n\n";
	
	/*	Esta expresion esta mal formulada, puesto que 7/3 es una division de enteros, y nos devuelve 2.
		Hubiera bastado con poner 7.0/3 o 7/3.0 para que el compilador detectara una division entre doubles.
	*/
	
	int x = 4, y = 4, q = 4;
	bool  expresion4 = (x == 4) && (y == 3) || (q != 4)==(1 != 2);
	cout << "(x == 4) && (y == 3) || (z != 4)==(1 != 2): " << expresion4 << "\n\n";
	
	//	Dato booleano que depende de como coloquemos los paréntesis
	
	
	int h;
	cout << "Introduce un valor de h: ";
	cin  >> h;
	bool expresion5 = h <= 4 || h >= 4;
	cout << "h <= 4 || h >= 4" << expresion5 << "\n\n";
	
	/*	Nos devueve true siempre, ya que cualquier numero entero es
		mayor, menor o igual a otro, en este caso, a 4.
	*/
	
	int t;
	cout << "Introduce un valor de t: ";
	cin  >> t;
	bool expresion6 = x < 4 && x > 4;
	cout << "x < 4 && x > 4" << expresion6 << "\n\n";
	
	/*	Esta expresion siempre es falsa, no existe ningun entero que pueda ser
		a la vez mayor y menor a otro. Podriamos hacer que fuera verdadera para el
		4 poniendo <= y >=.
	*/
	
	int z;
	char a;
	cout << "Introduce una valor entero para z y un caracter para a, separados por espacio: ";
	cin  >> q, a;
	bool expresion7 = (z > 6) || (a < 'z' && a > 'a')|| (z < 6);
	cout << "(z > 6) || (a < 'z' && a > 'a')|| (z < 6): " << expresion7 << "\n\n";
	
	//	Es una expresion booleana que depende de como coloquemos los parentesis
	
}
