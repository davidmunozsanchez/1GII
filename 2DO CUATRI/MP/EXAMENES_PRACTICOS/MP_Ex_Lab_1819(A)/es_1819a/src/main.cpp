/**
 * @author 
 * @file main.cpp
 * @brief 
 * Universidad de Granada - DGIM
 * Metodología de la Programación 
 * Examen de laboratorio 2018-2019
 * Por favor, rellene las funciones que se indican.
 * Una vez ejecutado el programa y obtenidos los ficheros de salida,
 * ejecute la script validaFicheros.sh para comprobar que la salida es correcta
 * No olvide pasar valgrind.
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

/**
 * @brief Función que analiza la IP del ordenador de prácticas y genera un número
 * entero asociado a ella
 * @return Un número entero obtenido a partir de la IP del ordenador de prácticas;
 */
int findIP();


/**
 * @brief Clase círculo
 */
class Circulo;

/**
 * @brief Clase punto bidimensional
 */
class Punto {
public: 
    double _x, _y;
    /**
     * @brief Constructor que inicializa el punto dependiendo de la IP
     * del ordenador en la que se ejecute
     */
    Punto();
    /**
     * Método que calcula si un punto está dentro de un círculo o no
     * @param c El círculo a comprobar
     * @return @retval true si @a p está dentro del círculo, @retval false en otro caso
     */
    bool estaDentro(Circulo c) const;
};

class Circulo{
public: 
    Punto _centro; 
    double _radio;
};

/**
@brief Imprime el contenido de un vector de Circulo
@param v 	Vector de Circulo
@param n	Número de elementos que contiene @a v
*/
void imprimirVector(Circulo *, int n);

int main()  {
    Punto P;                            /// Punto. Se inicializa automáticamente según la IP del ordenador
    Circulo *Circulos=nullptr,          /// Vector de círculos leídos desde el fichero de entrada
        *Dentro=nullptr,                /// Vector de círculos que contienen a Punto
        *Fuera=nullptr;                 /// Vector de círculos que no contienen a Punto
    int nCirculos=0,                      /// Número de elementos de Circulos[]
        nDentro=0,                        /// Número de elementos de Dentro[]
        nFuera=0;                         /// Número de elementos de Fuera[]
    ifstream fCirculos;                 /// Fichero de entrada
    ofstream fDentro, fFuera;            /// Ficheros de salida
    string sCirculos="data/datos1.dat",   /// Nombre del fichero de entrada
           sDentro="data/salida_"+to_string(findIP()%10)+".in",  /// Fichero de salida para Dentro[]
           sFuera="data/salida_"+to_string(findIP()%10)+".out";  /// Fichero de salida para Fuera []   

    /// Examen: Leer fichero de datos
    
    /// Examen: Imprimir los datos leídos

    /// Examen: Calcular resultado
    
    /// Examen: Mostrar resultado

    /// Examen: Guardar resultado en disco

    /// Examen: Terminación del programa
    
    return 0;
}

void imprimirVector(Circulo *v, int n)  {
    if (n>0 && v!=nullptr)  {
        cout << n << " elementos" << endl;
        for (int i=0; i<n; i++)
                cout << "["<<i<<"] = (" << v[i]._centro._x<<"-" << v[i]._centro._y <<")-" << v[i]._radio << (i%5==4? "\n" : "\t\t");
        cout << endl;
    }
    else
        cerr << "ERROR el vector está vacío"<<endl;
}

bool Punto::estaDentro(Circulo c)  const {
    return sqrt(pow(_x-c._centro._x,2)+pow(_y-c._centro._y,2))<=c._radio;
}

Punto::Punto() {
    int IP = findIP();
    srand(IP%10);
    _x = rand() % 20;
    _y = rand() % 20;
    cout << "PUNTO "<<_x << "-" << _y << endl;
}

int findIP() {
    ifstream f;
    string name;
    f.open("/etc/hostname");
    f >> name;
    f.close();
    return name[name.length()-1]-'0';
}
