/**
 * @file main.cpp
 * @brief Examen de laboratorio 
 * Universidad de Granada
 * Metodología de la Programación 
 * @nombre_del_alumno:  
 * 
 * @warning Por favor, rellene las funciones que se indican
*/
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#define ERROR_APERTURA 1
#define ERROR_DATOS 2

/**
@brief Imprime el contenido de un vector de string
@param v 	Vector de string
@param n	Número de elementos que contiene @a v
*/
void imprimirVector(const string *v, const int n)  {
    if (v != nullptr && n > 0)  {
        cout << n << " elementos" << endl;
        for (int i=0; i<n; i++)
                cout << "["<<i<<"] = " << v[i] << endl;
    }
    else
        cerr << "ERROR: Vector de datos vacío" << endl;
}

void redimensionar(string* &v, int& tama, int aumento) {
    if (tama + aumento > 0) {
        string *v_ampliado = new string[tama + aumento];
        for (int i = 0; (i < tama) && (i < tama + aumento); i++)
            v_ampliado[i] = v[i];
        delete[] v;
        v = v_ampliado;
        tama = tama + aumento;
    }
}

void MostrarError(int codigo){
    switch(codigo){
        case ERROR_APERTURA:
            cerr << "ERROR ABRIENDO EL FICHERO" << endl;
            
        case ERROR_DATOS:
            cerr << "ERROR EN LOS DATOS DEL FICHERO "<< endl;
            
    }
    std::exit(1);
        
}

/**
 * @brief Implementa la función del enunciado 
 * @param v1 Primer vector
 * @param nv1 Número de elementos de @a v1
 * @param v2 Segundo vector
 * @param nv2 Número de elementos de @a v2
 * @param v3 Vector resultado. Debe reservarse memoria dentro de la función
 * @param nv3 Número de elementos de @a v3
 */
void funcion(string const *v1, int nv1, string *v2, int nv2, string * &v3, int &nv3)  {
    for (int i = 0; i < nv1; i++){
        for (int j = 0; j < nv2; j++){
            if (v1[i] == v2[j]){
                redimensionar(v3, nv3, 1);
                v3[nv3 - 1] = v2[j];
            }
        }
    }
}


int main()  {
    int nv1=0, nv2=0, nv3=0;
    string *v1=nullptr, *v2=nullptr, *v3=nullptr;
    ifstream leeVector;
    ofstream mostrar;
    string archivo_entrada = "data/Laboratorio.dat";
    string archivo_salida = "data/salida.dat";
    string aniadir;

    // Examen: Leer vector v1
    leeVector.open(archivo_entrada);
    if (!leeVector.fail()){
        leeVector >> nv1;
        if (nv1 >= 0){
            v1 = new string[nv1];
 
            for (int i = 0; i < nv1; i++) {
                if (!leeVector.eof()) {
                    leeVector >> aniadir;
                    v1[i] = aniadir;
                } else
                    MostrarError(ERROR_DATOS);
            }
        }
        else
            MostrarError(ERROR_DATOS);
        
        
        leeVector >> nv2;
        if (nv2 >= 0){
            v2 = new string[nv2];

            for (int i = 0; i < nv2; i++) {
                if (!leeVector.eof() && nv2 >= 0) {
                    leeVector >> aniadir;
                    v2[i] = aniadir;
                }
                else
                    MostrarError(ERROR_DATOS);
            }
        }
        else
            MostrarError(ERROR_DATOS); 
    } 
    else
        MostrarError(ERROR_APERTURA);
    
    leeVector.close();
    // ...
    imprimirVector(v1, nv1);
    // Examen: Leer vector B
    // ...
    imprimirVector(v2, nv2);
    // Examen: Calcular resultado
    funcion(v1, nv1, v2, nv2, v3, nv3);
    // Examen: Mostrar resultado
    imprimirVector(v3, nv3);
    
    mostrar.open(archivo_salida);
    
    if (!mostrar.fail()){
        if (nv3 > 0){
            mostrar << "Numero de elementos de la intersección: " << nv3 << endl;
            
            for (int i = 0; i < nv3; i++){
                mostrar << "[" << i << "]" << " = " << v3[i] << endl;
            }
        }
           
        else
            mostrar << "La intersección es el conjunto vacío." << endl;
        
    }
    
    else
        MostrarError(ERROR_APERTURA);
    
    mostrar.close();
    

    // Examen: Terminación del programa
    // 
    
    delete[] v1;
    delete[] v2;
    delete[] v3;
    v1 = v2 = v3 = nullptr;
    nv1 = nv2 = nv3 = 0;
    return 0;
}
