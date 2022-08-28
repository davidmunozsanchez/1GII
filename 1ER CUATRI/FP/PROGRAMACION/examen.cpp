/*	Programa para leer un examen, sus respuestas, y evaluar los conociminetos del alumno
	devolviendo la nota sobre 10, sea cual sea el numero de preguntas
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <iomanip>

using namespace std;

// Clase Examen
class Examen{
	private:
		string asignatura;			// Nombre de la asignatura
		vector<string> preguntas;	// Vector para las preguntas del examen
		vector<char> respuestas;	// Vector para las respuestas
		
		/*	Metodo privado para calcular la nota del examen, pasandole como parametro las respondidas
			las no respondidas, y las que estan en blanco y las que no se han contestado, que se debe indicar
			con un #
			Finalmente, se hace la nota sobre 10
		*/
		double CalculaNota(double no_respondidas, double respondidas_bien, double respondidas_mal){
			double nota;
			
			nota += no_respondidas * 0;
			nota += respondidas_bien * 1;
			nota -= respondidas_mal * 1;
			
			if (nota < 0)
				nota = 0;
				
			if (preguntas.size() > 10 || preguntas.size() < 10)
				nota = (nota * 10)/preguntas.size();
				
			return nota;
		}
		
	public:
		// Constructor que almacena el nombre de la asignatura al crear el objeto
		Examen(string nombre){
			asignatura = nombre;
		}
		
		// Metodo publico para crear una nueva pregunta con su correspondiente respuesta
		void NuevaPregunta(string pregunta, char respuesta){
			preguntas.push_back(pregunta);
			respuestas.push_back(respuesta);
		}
		
		/*  Metodo publico para aniadir una serie de preguntas con sus respectivas respuestas a sus 
			respectivos vectores
		*/
		void AniadirNPreguntas(int n){
			char respuesta;
			string pregunta;
			cout << "Introduce las preguntas: ";
			for (int i = 0; i < n; i++){
				getline(cin, pregunta);
				preguntas.push_back(pregunta);	
			}
			
			cout << "Introduce las respuestas: ";
			for (int i = 0; i < n; i++){
				cin >> respuesta;
				respuestas.push_back(respuesta);
			}		
					
		}

		// Metodo publico para devolver el numero total de preguntas
		int NumPreguntas(){
			return preguntas.size();
		}
		
		// Metodo publico para devolver la pregunta en la posicion iesima
		string GetEnunciado (int iesima){
			return preguntas[iesima - 1];
		}
		
		// Metodo publico para obtener la respuesta de la pregunta en la posicion iesima
		char GetRespuesta (int iesima){
			return respuestas[iesima - 1];
		}
		
		/*  Metodo privado para evaluar a un numero n de alumnos, mostrando la nota justo al final de
			terminar la prueba, con una precision de 2 decimales. Para hacer los calculos, hago uso del
			metodo privado declarado anteriormente, habiendo calculado el numero de cada tipo de preguntas
		*/
		void Evaluar(int num_veces){
			double no_respondidas;
			double respondidas_bien;
			double respondidas_mal;
			char respuesta;
			
			for (int j = 0; j < num_veces; j++){
				for (int i = 0; i < preguntas.size(); i++){
					cout << preguntas[i] << " ";
					cin  >> respuesta;
				
					if (respuesta == '#')
						no_respondidas += 1;
					
					if (respuesta == respuestas [i])
						respondidas_bien += 1;
					
					if (respuesta != respuestas[i] && respuesta != '#')
						respondidas_mal += 1;
					
				}
				cout << setprecision(2) << CalculaNota(no_respondidas, respondidas_bien, respondidas_mal) << endl;
				no_respondidas = respondidas_bien = respondidas_mal = 0;
			}
			
			
			
		}
};

int main(){
	Examen examen1("FP");
	
	examen1.AniadirNPreguntas(3);
	
	examen1.Evaluar(2);
}
