/*	Programa para trabajar con vectores de objetos de varias clases, representadno una librería
*/
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

/* Clase para trabajar con el identificador
*/
class Identificador{
	private: 
		string cadena1; // Almacena un string correspondiente a la cadena.
		
	public:
		// Constructor por defecto
		Identificador (){}
		
		// Constructor al que le pasamos un string como parametro
		Identificador(string cadena){
			cadena1 = cadena;
		}
		
		// Metodo publico para ver si una cadena es igual a otra que pasamos como parametro
		bool EsIgual_a(Identificador cadena2){
			if (cadena1.compare(cadena2.cadena1) == 0)
				return true;
				
			else
				return false;
		}
		
		// Metodo publico para ver si una cadena es menor que otra que pasamos como parametro
		bool EsMenor_que(Identificador cadena2){
			if (cadena1.compare(cadena2.cadena1) < 0)
				return true;
			
			else
				return false;
		}
		
		// Metodo para devolver el dato miembro cadena1
		string DevolverCadena(){
			return cadena1;
		}
	
};

/*	Clase para trabajar con la fecha
*/
class Fecha{
	private:
		int dia,	//entero que representa al dia
			mes,	//entero que representa al mes
			anio;	//entero que representa al anio
	public:
		
		/* 	Metodo publico que establece una fecha a partir de tres parametros,
			teniendo en cuenta que sea coherente
		*/
		void SetDiaMesAnio(int el_dia, int el_mes, int el_anio){
			bool es_bisiesto;
			bool es_fecha_correcta;
			const int anio_inferior = 1900;
			const int anio_superior = 2500;
			const int dias_por_mes[12] =
				{31,28,31,30,31,30,31,31,30,31,30,31};
				// Meses de Enero a Diciembre

			es_fecha_correcta = 1 <= el_dia &&
								el_dia <= dias_por_mes[el_mes - 1] &&
								1 <= el_mes && el_mes <= 12 &&
								anio_inferior <= el_anio &&
								el_anio <= anio_superior;
								
								
			es_bisiesto = (el_anio % 4 == 0 && el_anio % 100 != 0) ||
							el_anio % 400 == 0;

			if (!es_fecha_correcta && el_mes == 2 && el_dia == 29 && es_bisiesto)
				es_fecha_correcta = true;

			if (es_fecha_correcta){
				dia = el_dia;
				mes = el_mes;
				anio = el_anio;
			}
		}
		
		/*	Metodo publico que devuelve un entero, el correspondiente
			al dia del objeto Fecha que tratemos
		*/
		int Dia(){
			return dia;
		}
	
		/*	Metodo publico que devuelve un entero, el correspondiente
			al mes del objeto Fecha que tratemos
		*/
		int Mes(){
			return mes;
		}
	
		/*	Metodo publico que devuelve un entero, el correspondiente
			al anio del objeto Fecha que tratemos
		*/
		int Anio(){
			return anio;
		}
		
		/* 	Metodo publico que devuelve un booleano true en caso de que la fecha que 
			tratemos sea menor a otra proporcionada como parametro
		*/
		bool EsIgual_a(Fecha fecha2){
			return anio == fecha2.anio && mes == fecha2.mes
					&& dia == fecha2.dia;
		}	
		
		/* 	Metodo publico que devuelve un booleano true en caso de que la fehca que tratemos sea menor
			a otra proporcionada como parametro
		*/
		bool EsMenor_que(Fecha fecha2){
			if (anio < fecha2.anio)
				return true;
			
			else if (anio > fecha2.anio)
				return false;
			
			else{
				if (mes < fecha2.mes)
					return true;
			
				else if (mes > fecha2.mes)
					return false;
				
				else{
					if (dia < fecha2.dia)
						return true;
					
					else if (dia > fecha2.dia)
						return false;
					
					else
						return false;
				}
			}
		}
};

/*	Clase para trabajar con objetos de tipo Libro, que tienen como datos miembros
	un identificador y una fecha de publicacion
*/
class Libro{
	private:
		Identificador identi;	// Objeto de tipo identificador
		Fecha fecha_publi;		// Objeto de tipo fecha
		
	public:
		
		// Constructor por defecto de la clase
		Libro(){}
		
		/*	Constructor con dos parametros, un objeto identificador y otro fecha
		*/
		Libro(Identificador a, Fecha b){
			identi = a;
			fecha_publi = b;
		}
		
		/*	Meotod publico que devuelve true si dos libros son iguales, es decir,
			si sus identificadores son iguales y si su fecha de publicacon son iguales
		*/
		bool EsIgual_a(Libro libro2){
			return identi.EsIgual_a(libro2.identi) &&
					fecha_publi.EsIgual_a(libro2.fecha_publi);
		}
		
		/* 	Metodo publico que devuelve true si dos libros son iguales, es decir, si
			su identificador es menor que el del libro que pasamos como parametro y lo
			mismo con la fecha
		*/
		bool EsMenor_que(Libro libro2){
			return identi.EsMenor_que(libro2.identi) &&
					fecha_publi.EsMenor_que(libro2.fecha_publi);
		}
		
		/*	Metodo publico para devolver el objeto Identificador que es dato miembro
		*/
		Identificador DevolverIdentificador(){
			return identi;
		}
		
		/* 	Metodo publico para devolver el objeto Fecha que es dato miembro
		*/
		Fecha DevolverFecha(){
			return fecha_publi;
		}
};

/* Clase que cuenta con vector de objetos de tipo Libro
*/
class Biblioteca{
	private:
		vector<Libro> biblio;
		
		/* 	Metodo privado para ordenar el vector de objetos de menor a mayor. Primero compara
			las fechas y escoge el libro que tenga una fecha de publicacion anterior. Despues, en
			caso de que las fechas sean iguales, compara las cadenas correspondientes a los identificadores
		*/	
		void Ordena(){
			Identificador i_minimo;
			Fecha minimo;
			Libro intercambia;
			int posicion_minimo;
			
			for (int i = 0; i < biblio.size(); i++){
				minimo = biblio[i].DevolverFecha();
				i_minimo = biblio[i].DevolverIdentificador();
				posicion_minimo = i;
				
				for (int j = i + 1; j < biblio.size(); j++ ){
					if (biblio[j].DevolverFecha().EsMenor_que(minimo)){
						minimo = biblio[j].DevolverFecha();
						posicion_minimo = j;
					}
					
					if (biblio[j].DevolverFecha().EsIgual_a(minimo)){
						if (biblio[j].DevolverIdentificador().EsMenor_que(i_minimo)){
							i_minimo = biblio[j].DevolverIdentificador();
							posicion_minimo = j;
						}
					}
				}
				
				intercambia = biblio[i];
				biblio[i] = biblio[posicion_minimo];
				biblio[posicion_minimo] = intercambia;
				
			}
		}
			
			/* 	Metodo privado igual que el anterior pero que ordena de mayor a menor
			*/
			void OrdenaMayor(){
				Identificador i_maximo;
				Fecha maximo;
				Libro intercambia;
				int posicion_maximo;
			
				for (int i = 0; i < biblio.size(); i++){
					maximo = biblio[i].DevolverFecha();
					i_maximo = biblio[i].DevolverIdentificador();
					posicion_maximo = i;
					
					for (int j = i + 1; j < biblio.size(); j++ ){
						if (!biblio[j].DevolverFecha().EsMenor_que(maximo)){
							maximo = biblio[j].DevolverFecha();
							posicion_maximo = j;
						}
						
						if (biblio[j].DevolverFecha().EsIgual_a(maximo)){
							if(!biblio[j].DevolverIdentificador().EsMenor_que(i_maximo)){
								i_maximo = biblio[j].DevolverIdentificador();
								posicion_maximo = j;
							}
						}
					}
				
					intercambia = biblio[i];
					biblio[i] = biblio[posicion_maximo];
					biblio[posicion_maximo] = intercambia;
				}
			}
		
	public:
		
		// Constructor por defecto de la clase
		Biblioteca(){}
		
		/*	Metodo privado que se encarga de aniadir objetos (que pasamos como parametro
			al vector) y de ordenarlos
		*/
		void SetBiblioteca(Libro libro1){
			biblio.push_back(libro1);
			
			OrdenaMayor();
		}
		
		/* Metodo privado que se encarga de devolver los datos de un libro dado el identificador
		*/
		void RecuperarDatos(string identificador){
			int longitud_a_recorrer = biblio.size();
			Fecha fecha_a_devolver;
			Identificador identificador_a_devolver;
			
			for (int i = 0; i < longitud_a_recorrer; i++){
				if (biblio[i].DevolverIdentificador().DevolverCadena() == identificador){
					cout << identificador << endl;
					cout << biblio[i].DevolverFecha().Dia() << "/" <<
							biblio[i].DevolverFecha().Mes() << "/" <<
							biblio[i].DevolverFecha().Anio() << endl;
				}		
			}
		}
		
		/* Metodo privado que se encarga de devolver el vector que es dato miembro de Biblioteca
		*/
		vector<Libro> DevolverBiblioteca(){
			return biblio;
		}
};

/* Clase sin datos miembros para leer una biblioteca
*/
class LectorBiblioteca{
	public:
		/*	Metodo publico para leer datos dado un objeto de la clase biblioteca que pasamos
			por referencia para que los cambios se le apliquen
		*/
		void LeerDatos(Biblioteca& biblioteca1){
			string elemento;
			int dia, mes, anio;
			Fecha fecha1;
			
			cin >> elemento;
			
			while (elemento != "FFFF"){
				Identificador identi(elemento);
				cin >> dia >> mes >> anio;
				fecha1.SetDiaMesAnio(dia, mes, anio);
				Libro libro_a_aniadir(identi, fecha1);
				biblioteca1.SetBiblioteca(libro_a_aniadir);
				
				cin >> elemento;
			}
		}
};

/* 	Clase sin datos miembros para imprimir los datos de una biblioteca
*/
class ImpresorBiblioteca{
	public:
		
		/*	Metodo publico que imprime todos los datos de un objeto Biblioteca que pasamos como parametro
		*/
		void ImprimeBiblioteca(Biblioteca biblioteca1){
			vector<Libro> vector_a_mostrar = biblioteca1.DevolverBiblioteca();
			
			for (int i = 0; i < vector_a_mostrar.size(); i++){
				cout << vector_a_mostrar[i].DevolverIdentificador().DevolverCadena() << " ";
				cout << vector_a_mostrar[i].DevolverFecha().Dia() << " " << 
						vector_a_mostrar[i].DevolverFecha().Mes() << " " <<
						vector_a_mostrar[i].DevolverFecha().Anio() << endl;
			}
				
		}
};

int main(){
	LectorBiblioteca lector1;
	Biblioteca biblioteca1;
	ImpresorBiblioteca a;
	
	lector1.LeerDatos(biblioteca1);
	a.ImprimeBiblioteca(biblioteca1);
	
}


