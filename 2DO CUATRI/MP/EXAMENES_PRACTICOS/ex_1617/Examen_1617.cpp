/*
 * @file Examen_1617.cpp
 * @author Daniel Pérez Ruiz
 * @date 27.4.19
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

/*
 * @brief Lee las palabras de un fichero y las añade a un vector dinámico de strings
 * @param fichero El nombre del fichero
 * @param arrayPalabras Array dinámico de strings donde se insertarán las palabras
 * @return El número total de palabras
 * @retval -1 si ha fallado la lectura del fichero
 */
int leerFichero(char* fichero, string* &arrayPalabras){
	int numero_palabras = 5;
	string palabras;
	ifstream fin;
	
	fin.open(fichero);
	if(fin){
		fin >> numero_palabras;
		
		if(numero_palabras > 0){
			arrayPalabras = new string [numero_palabras];
			 
			if(fin){
				for(int i=0; i<numero_palabras; i++){
					fin >> palabras;
					arrayPalabras[i] = palabras;
				}
				
				if(fin){
					cout << "SE HAN LEIDO [" << numero_palabras << "] PALABRAS CORRECTAMENTE DEL FICHERO [" << fichero << "]" << endl;
				}
				else{
					cerr << "ERROR [3] EN leerFichero: INCOHERENCIA EN NUM PALABRAS" << endl;
				}
				
			}
			else{
				cerr << "ERROR [2] EN leerFichero: EL FICHERO [" << fichero << "] NO ES VALIDO" << endl;
			}
			
		}
		else{
			if(numero_palabras == 0){
				cout << "NO SE INSERTARAN PALABRAS EN EL VECTOR" << endl;
			}
			else{
				cerr << "ERROR [1] EN leerFichero: TOTAL DE PALABRAS NO VALIDO [" << numero_palabras << "]" << endl;
			}
		}
		fin.close();
	}
	else{
		cerr << "ERROR [0] EN leerFichero: EL FICHERO [" << fichero << "] NO EXISTE" << endl;
	}
	
	return numero_palabras;
}



int main(){
	string* ficheroA = nullptr;
	string* ficheroB = nullptr;
	string* arrayUnion = nullptr;
	string* arrayCopia = nullptr;
	int palabrasA, palabrasB, contador = 0, j = 0, k = 0;
	bool repetido;
	
	//Nombre de los ficheros
	char fileA[] = "ficheroA";
	char fileB[] = "ficheroB";
	
	//Set del total de palabras
	palabrasA = leerFichero(fileA, ficheroA);
	palabrasB = leerFichero(fileB, ficheroB);
	
	//Se realiza el proceso de unión siempre y cuando no haya fallado la lectura del fichero
	if(palabrasA != -1 && palabrasB != -1){
		
		//Se reserva memoria para un array dinámico de strings
		arrayCopia = new string [palabrasA + palabrasB];
		
		//Copio todas las palabras del fichero A
		for(int i=0; i<palabrasA; i++){
			arrayCopia[i] = ficheroA[i];
			contador++;
		}
		
		k = palabrasA;
		
		//Comparo las palabras de ambos ficheros y añado al vector las que no se repiten
		while(j < palabrasB){
			repetido = false;
			for(int i=0; i<palabrasA && !repetido; i++){
				if(arrayCopia[i] == ficheroB[j])
					repetido = true;
			}
			
			if(!repetido){
				arrayCopia[k] = ficheroB[j];
				k++;
				contador++;
			}
			j++;
		}
		
		//Liberación de la memoria y muestra de resultados
		
		delete [] ficheroA;
		delete [] ficheroB;
		
		arrayUnion = new string [contador];
		
		for(int i=0; i<contador; i++){
			arrayUnion[i] = arrayCopia[i];
		}
		
		delete [] arrayCopia;
		
		for(int i=0; i<contador; i++){
			cout << "Palabra [" << i+1 << "] >>> " << arrayUnion[i] << endl;
		}
	
		delete [] arrayUnion;
	}
	
	return 0;
}
