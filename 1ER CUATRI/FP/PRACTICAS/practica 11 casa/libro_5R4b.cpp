/*	Programa para guardar informacion diversa de un libro (titulo, autor, editorial y anio de edicion)
	en una clase, y realizar diversas operaciones con dichos datos
*/

#include <iostream>
#include <cstring>

using namespace std;

class Libro{
	private:
		string autor, titulo, editorial, anio;
		
		/* 	Metodo privado para ver si dos libros son identicos comparando dos
			strings con la biblioteca cstring. Son identicos si, y solo si, todos 
			sus datos son exactamente iguales
		*/
		bool iguales(Libro libro2){
			return 	autor == libro2.autor &&
					titulo == libro2.titulo &&
					editorial == libro2.editorial &&
					anio == libro2.anio;		
		}
		
		/* 	Metodo privado para ver si dos libros son diferentes comparando dos
			strings con la biblioteca cstring. Son identicos si, y solo si, todos 
			sus datos son diferentes
		*/
		bool diferentes(Libro libro2){
			return 	autor != libro2.autor &&
					titulo != libro2.titulo &&
					editorial != libro2.editorial &&
					anio != libro2.anio;		
		}
		
		
		
	public:
		// Metodo publico para asignar un string a cada componente
		void Set_libro(string first, string second, string third, string fourth){
			autor = first;
			titulo = second;
			editorial = third;
			anio = fourth;
		}
		
		// Metodo privado para mostrar todos los datos de un libro
		void Mostrar_libro(){
			cout << autor << "\n" << titulo << "\n" << editorial << "\n" << anio << endl;
		}  
		
		// Metodo privado para mostrar informacion sobre un libro segun la eleccion del usuario
		void Mostrar_eleccion(int eleccion){
			if (eleccion == 1)
				cout << autor;
			
			if (eleccion == 2)
				cout << titulo;
				
			if (eleccion == 3)
				cout << editorial;
				
			if (eleccion == 4)
				cout << anio;
			
		}
		
		/*	Metodo privado para comparar dos libros, seran iguales si todos sus datos son iguales
			seran distintos si todos sus datos son distintos y coincidiran en solo algunas cosas 
			en otras ocasiones
		*/
		void Compara(Libro libro2){
			if(iguales(libro2))
				cout << "Los libros son identicos";
			
			else if(diferentes(libro2))
				cout << "Los libros no son identicos";
				
			else{
				if (autor == libro2.autor)
					cout << "Libros comparten autor: " << autor << endl;
					
				if (titulo == libro2.titulo)
					cout << "Los libros comparten titulo: " << titulo << endl;
				
				if (editorial == libro2.editorial)
					cout << "Los libros comparten editorial: " << editorial << endl;
					
				if (anio == libro2.anio)
					cout << "Los libros comparten anio de publicacion: " << anio << endl;
				
			}
		}
};

int main(){
	Libro libro1, libro2;
	
	libro1.Set_libro("David", "Hola a todos", "Anaya", "2013");
	libro2.Set_libro("David", "Hola a todos", "Anaya", "2013");
	
	libro1.Mostrar_libro();
	
	libro1.Mostrar_eleccion(4);
	
	libro1.Compara(libro2);
	
}
