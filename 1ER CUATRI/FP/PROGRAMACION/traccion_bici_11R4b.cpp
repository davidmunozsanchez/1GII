/*	Programa que lee una secuencia de char introducida mediante un fichero que se corresponde con 	
	la relacion de marchas de una bici.
	E = PLATO    S = SUBIR
	P = PINION	 B = BAJAR 
	
	Ademas, en el caso de los piniones, se puede subir de 2 en 2 (T) o bajar (C).
	
	Por ultimo, se aniade situaciones en las que es peligroso cambiar de marcha y por eso el programa vuelve al estado anterior
*/

#include <iostream>
#include <vector>

using namespace std;

// Para almacenar en el dato Marcha el numero correspondiente al pinion y al plato
struct Marcha{
	int pinion;
	int plato;
};

// Clase para representar la traccion de una bicicleta
class Traccion{
	// Datos y metodos privados;
	private:
		Marcha marcha1;				// Representa la marcha actual
		Marcha marcha_anterior;		// Representa la marcha anterior
		vector<char> vector_cadena;	// ALmacena la secuencia de cambio de marcha
		
		/*  Metodo privado para leer un fichero externo, almacenando cada char 
			en el vector_cadena
		*/		
		void LeerFichero(){
			char elemento;
			
			cin >> elemento;
			
			while (elemento != '#'){
				vector_cadena.push_back(elemento);
				cin >> elemento;
			}
		}
		
		/* 	Metodo privado que devuelve un booleano si la realcion de marchas actual es 
			arriesgada
		*/
		bool Riesgo(){
			return (marcha1.plato == 1 && marcha1.pinion >= 5) 
					||
					(marcha1.plato == 2 && (marcha1.pinion == 1 || marcha1.pinion == 7))
					||
					(marcha1.plato == 3 && marcha1.pinion <= 3);
		}
	
	// Metodos publicos
	public:
		
		// Generador que recibe el dato Marcha
		Traccion(Marcha marcha_actual){
			marcha1.pinion = marcha_actual.pinion;
			marcha1.plato = marcha_actual.plato;
			LeerFichero();
		}
		
		/* 	Metodo privado encargado de realizar todos los calculos en referente al cambio de marcha.
			Si se identifica un pinion, trabaja sumando o restando, sin pasarse nunca de 7 o de 1.
			Si se identifica un plato, trabaja sumando o restando, sin pasarse nunca de 3 o de 1.
			Por ultimo, si determina que la marcha a la que se ha cambiado conlleva riesgo, se vuelve a la 
			marcha anterior.
		*/
		void Cambio_de_marcha(){
			bool es_pinion;
			bool es_plato;
			
			marcha_anterior = marcha1;
			
			for (int i = 0; i < vector_cadena.size(); i++){
				es_pinion = vector_cadena[i] == 'P';
				es_plato = vector_cadena[i] == 'E';
				
				if (es_pinion){
					if(vector_cadena[i + 1] == 'S' && marcha1.pinion < 7)
						marcha1.pinion += 1;
					
					if (vector_cadena[i + 1] == 'B' && marcha1.pinion > 1)
						marcha1.pinion -= 1;
					
					if (vector_cadena[i + 1] == 'T' && marcha1.pinion < 6)
						marcha1.pinion += 2;
					
					if (vector_cadena[i + 1] == 'C' && marcha1.pinion > 2)
						marcha1.pinion -= 2;
				}
				
				if (es_plato){
					if(vector_cadena[i + 1] == 'S' && marcha1.plato < 3)
						marcha1.plato += 1;
					
					if (vector_cadena[i + 1] == 'B' && marcha1.plato > 1)
						marcha1.plato -= 1;	
				}
						
			}
			
			if(Riesgo())
				marcha1 = marcha_anterior;
			
		
		}
		
		// Metodo privado para mostrar el vector cadena, con la relacion de marchas actual
		void Mostrar(){
			for (int i = 0; i < vector_cadena.size(); i++)
				cout << vector_cadena[i] << " ";
				
			cout << endl;
			
			cout << "Plato: " << marcha1.plato << ", pinion: " << marcha1.pinion;
		}
		
};

int main(){
	Marcha marcha1;
	marcha1.pinion = 4;
	marcha1.plato = 1;
	
	Traccion traccion1(marcha1);
	
	traccion1.Cambio_de_marcha();
	
	traccion1.Mostrar();
}
