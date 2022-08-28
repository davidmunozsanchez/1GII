#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define ERROR_ARG 1
#define ERROR_APER 2
#define ERROR_DATOS 3

void errorCall (int codigo);

void leer (istream &flujo, string* &v, int &tamanio);

void redimensionar (string* &v, int& tama, int aumento);

int main(int nargs, char * args[]){
    string *puntero_a = 0, *puntero_b = 0;
    string *puntero_final = 0;
    string fichero1, fichero2;
    ifstream entrada1, entrada2;
    istream *input1, *input2;

    int tamanio1 = 0,
        tamanio2 = 0,
        tamanio_final = 0;

    // Vamos a recorrer los argumentos del main, en busca de los dos ficheros de texto
    if (nargs < 3 || nargs > 3)
        errorCall(ERROR_ARG);
    else{
        fichero1 = args[1];
        fichero2 = args[2];
    }
 
    //Una vez que tengo los dos ficheros procedo a leerlos
    entrada1.open(fichero1);
    entrada2.open(fichero2);

    input1 = &entrada1;
    input2 = &entrada2;

    leer(*input1, puntero_a, tamanio1);
    leer(*input2, puntero_b, tamanio2);
}


void errorCall (int codigo){
    switch (codigo)
    {
    case ERROR_ARG:
        cerr << "Error en la llamada. Por favor, introduce dos arhivos de texto." << endl;
        break;
    
    case ERROR_APER:
        cerr << "Error abriendo el archivo." << endl;
        break;

    case ERROR_DATOS:
        cerr << "Error da datos en una de los archivos." << endl;
        break;
    }
}

void redimensionar(string* &v, int &tama, int aumento){
    if(tama+aumento > 0){
		string *v_ampliado = new string[tama+aumento];
		for (int i=0; (i<tama) && (i<tama+aumento); i++)
			v_ampliado[i] = v[i];
		delete[] v;
		v = v_ampliado;
		tama=tama+aumento;
	}
}

void leer (istream &flujo, string* &v, int &tamanio){
    int longitud;
    string palabra;

    flujo >> tamanio;

    for (int i = 0; i < tamanio; i++){
        flujo >> palabra;
        redimensionar(v, tamanio, 1);
        v[i] = palabra;
    }
}