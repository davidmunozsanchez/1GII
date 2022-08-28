//programa que permite calcular el area de cualquier poligono dividiendolo en triangulos y calculando el area de estos
#include <iostream>
#include <cmath>
using namespace std;

//Struct para almacenar los puntos
struct TipoPunto {
	double abcisa;
	double ordenada;
};

//Struct para almacenar el poligono
struct TipoPoligono {
	TipoPunto puntos[100];
	int numero_puntos;
};

//Funcion que calcula el area de un triangulo
double AreaTriangulo (TipoPunto punto1, TipoPunto punto2, TipoPunto punto3) {
	double lado1, lado2, lado3, suma_lados, area;
	
	lado1 = sqrt(pow(punto1.abcisa - punto2.abcisa, 2) + pow(punto1.ordenada - punto2.ordenada, 2));
	lado2 = sqrt(pow(punto2.abcisa - punto3.abcisa, 2) + pow(punto2.ordenada - punto3.ordenada, 2));
	lado3 = sqrt(pow(punto1.abcisa - punto3.abcisa, 2) + pow(punto1.ordenada - punto3.ordenada, 2));
	suma_lados = (lado1 + lado2 + lado3) / 2;
	area = sqrt(suma_lados * (suma_lados - lado1) * (suma_lados - lado2) * (suma_lados - lado3));
	
	return area;
}

//Funcion que calcula separa el poligono en triangulos y suma su area
double AreaPoligono(TipoPoligono poligono) {
	double area = 0;
	
	for(int i = 0; i < poligono.numero_puntos - 2; i++)
		area += AreaTriangulo(poligono.puntos[0], poligono.puntos[i + 1], poligono.puntos[i + 2]);
	
	return area;
}

int main() {
	TipoPoligono poligono;
	double area;
	
	do{
		cout << endl << "Introduce el numero de lados el poligono: ";
		cin >> poligono.numero_puntos;
	}while(poligono.numero_puntos < 3);
	
	for(int i = 0; i < poligono.numero_puntos; i++){
		cout << endl << "Abcisa punto " << i + 1 << ": ";
		cin >> poligono.puntos[i].abcisa;
		cout << endl << "Ordenada punto " << i + 1 << ": ";
		cin >> poligono.puntos[i].ordenada;
	}
	
	area = AreaPoligono(poligono);
	
	cout << endl << "El area es: " << area << " unidades cuadradas";
}
