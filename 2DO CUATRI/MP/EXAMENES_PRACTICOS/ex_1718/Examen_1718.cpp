/*
 * @file Examen_1718.cpp
 * @author Daniel Pérez Ruiz
 * @date 27.4.19
 */

#include <iostream>
#include <string>

using namespace std;

/*
 * @brief Lee una secuencia de Bigramas y los almacena en un array dinámico
 * @param arraySecuencias El vector dinámico donde almacenar la secuencia
 * @return El total de bigramas introducidos
 */
int LeerBigrama(string* &arraySecuencias){
	int total_bigramas = -1;
	string bigrama;
	

	cout << "INSERTE PARAMETROS [NUMERO B1 B2 ... BN] >>> ";
	cin >> total_bigramas;
	
	if(total_bigramas > 0){
		arraySecuencias = new string [total_bigramas];
		
		for(int i=0; i<total_bigramas; i++){
			cin >> bigrama;
			
			if(bigrama.size() == 2)
				arraySecuencias[i] = bigrama;
		}
	}
	
	
	return total_bigramas;
}

int main(){
	string* secuenciaA = nullptr;
	string* secuenciaB = nullptr;
	string* secuenciaCopia = nullptr;
	string* secuenciaInterseccion = nullptr;
	
	int num_A = LeerBigrama(secuenciaA);
	int num_B = LeerBigrama(secuenciaB);
	int contador = 0;
	bool repetido = false;
	
	//Realiza la intersección si la lectura de bigramas no ha fallado
	if(num_A > 0 && num_B > 0){
		secuenciaCopia = new string [num_A + num_B];
		
		for(int i=0; i<num_A; i++){
			repetido = false;
			
			for(int j=0; j<num_B && !repetido; j++){
				if(secuenciaA[i] == secuenciaB[j]){
					secuenciaCopia[contador] = secuenciaA[i];
					contador++;
					repetido = true;
				}
			}
		}
		
		secuenciaInterseccion = new string [contador];
		
		for(int k=0; k<contador; k++)
			secuenciaInterseccion[k] = secuenciaCopia[k];
		
		cout << "MOSTRANDO [" << contador << "] ELEMENTOS >> ";
		for(int y=0; y<contador; y++)
			cout << secuenciaInterseccion[y] << " ";
	}
	else{
		cerr << "ERROR: PARAMETROS NO INTRODUCIDOS CORRECTAMENTE" << endl;
	}
	
	//Liberación de la memoria
	
	delete [] secuenciaA;
	delete [] secuenciaB;
	delete [] secuenciaCopia;
	delete [] secuenciaInterseccion;
	
	return 0;
}
