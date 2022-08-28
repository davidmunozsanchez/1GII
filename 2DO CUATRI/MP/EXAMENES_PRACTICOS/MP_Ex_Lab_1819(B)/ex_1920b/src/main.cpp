/**
 * @file main.cpp
 * @author 
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

#define ERROR_DATOS 1
#define ERROR_ESCRITURA 2

/**
 * @brief Función que analiza la IP del ordenador de prácticas y genera un número
 * entero asociado a ella
 * @return Un número entero obtenido a partir de la IP del ordenador de prácticas;
 */
int findIP();

/**
 * @brief Clase punto bidimensional
 */
class Punto {
public:
    double _x, _y;
};

/**
 * @brief Clase círculo
 */
class Circulo {
public:
    Punto _centro;
    double _radio;
    /**
     * @brief Constructor que inicializa el círculo dependiendo de la IP
     * del ordenador en la que se ejecute
     */
    Circulo();
    /**
     * Método que calcula si un punto está dentro del círculo o no
     * @param p El punto a calcular
     * @return @retval true si @a p está dentro del círulo, @retval false en otro caso
     */
    bool estaDentro(Punto p) const;
};

/**
@brief Imprime el contenido de un vector de Punto
@param v 	Vector de Punto
@param n	Número de elementos que contiene @a v
 */
void imprimirVector(Punto *, int n);

void redimensionar(Punto* &v, int& tama, int aumento) {
    if (tama + aumento > 0) {
        Punto *v_ampliado = new Punto[tama + aumento];
        for (int i = 0; (i < tama) && (i < tama + aumento); i++)
            v_ampliado[i] = v[i];
        delete[] v;
        v = v_ampliado;
        tama = tama + aumento;
    }
}

void MostrarError(int codigo){
    switch(codigo){
        case ERROR_DATOS:
            cerr << "DATOS INCORRECTOS O INSUFICIENTES" << endl;
            
        case ERROR_ESCRITURA:
            cerr << "Error mostrando la salida." << endl;
            
    }
    std::exit(1);
        
}

int main() {
    Circulo C; /// Cïrculo. Se inicializa automáticamente según la IP del ordenador
    Punto *Puntos = nullptr, /// Vector de puntos leídos del fichero 
            *Dentro = nullptr, /// Vector de puntos que están dentro del círculo
            *Fuera = nullptr; /// Vector de puntos que están fuera del círculo
    int nPuntos = 0, /// Número de elementos de Puntos[]
            nDentro = 0, /// Número de elementos de Dentro[]
            nFuera = 0; /// Número de elementos de Fuera[]

    ifstream fPuntos; /// Fichero de entrada
    istream *flujo;
    ofstream fDentro;
    ofstream fFuera;
    ostream *sal;
    string sPuntos = "data/error.dat", /// Nombre del fichero de entrada
            sDentro = "data/salida_" + to_string(findIP() % 10) + ".in", /// Fichero de salida para Dentro[]
            sFuera = "data/salida_" + to_string(findIP() % 10) + ".out"; /// Fichero de salida para Fuera []   

    /// Examen: Leer fichero de datos
    fPuntos.open(sPuntos);
    flujo = &fPuntos;

    *flujo >> nPuntos;
    
    if (nPuntos <= 0)
        MostrarError(ERROR_DATOS);
    
    else
        Puntos = new Punto[nPuntos];

    for (int i = 0; i < nPuntos; i++) {
        if (!flujo->eof())
            *flujo >> Puntos[i]._x >> Puntos[i]._y;
        else
            MostrarError(ERROR_DATOS);
    }
    
    fPuntos.close();

    /// Examen: Imprimir los datos leídos
    for (int i = 0; i < nPuntos; i++)
        cout << Puntos[i]._x << " " << Puntos[i]._y << endl;
    /// Examen: Calcular resultado
    Dentro = new Punto[0];
    Fuera = new Punto[0];
    for (int i = 0; i < nPuntos; i++) {
        if (C.estaDentro(Puntos[i])) {
            redimensionar(Dentro, nDentro, 1);
            Dentro[nDentro - 1] = Puntos[i];
        }
        else {
            redimensionar(Fuera, nFuera, 1);
            Fuera[nFuera - 1] = Puntos[i];
        }
    }
    /// Examen: Mostrar resultado
    cout << "Puntos dentro del círculo: " << endl;
    for (int j = 0; j < nDentro; j++)
        cout << Dentro[j]._x << "     " << Dentro[j]._y << endl;

    cout << "Puntos fuera del círculo: " << endl;
    for (int k = 0; k < nFuera; k++)
        cout << Fuera[k]._x << "     " << Fuera[k]._y << endl;
    /// Examen: Guardar resultado en disco
    fDentro.open(sDentro);
    sal = &fDentro;
    *sal << nDentro << endl;
    
    for (int i = 0; i < nDentro; i++)
        *sal << Dentro[i]._x << " " << Dentro[i]._y << endl;
    
    fDentro.close();
    
    fFuera.open(sFuera);
    sal = &fFuera;
    *sal << nFuera << endl;
    for (int i = 0; i < nFuera; i++)
        *sal << Fuera[i]._x << " " << Fuera[i]._y << endl;
    /// Examen: Terminación del programa
    delete[] Puntos;
    delete[] Fuera;
    delete[] Dentro;
    
    return 0;
}

void imprimirVector(Punto *v, int n) {
    if (n > 0 && v != nullptr) {
        cout << n << " elementos" << endl;
        for (int i = 0; i < n; i++)
            cout << "[" << i << "] = " << v[i]._x << "-" << v[i]._y << (i % 8 == 7 ? "\n" : "\t");
        cout << endl;
    } else
        cerr << "ERROR el vector está vacío" << endl;
}

int findIP() {
    ifstream f;
    string name;
    f.open("/etc/hostname");
    f >> name;
    f.close();
    return name[name.length() - 1] - '0';
}

Circulo::Circulo() {
    int IP = findIP();
    srand(IP % 10);
    _radio = rand() % 8;
    _centro._x = rand() % 20;
    _centro._y = rand() % 20;
    cout << "Círculo (" << _centro._x << "," << _centro._y << ")-" << _radio << endl;
}

bool Circulo::estaDentro(Punto p) const {
    return sqrt(pow(p._x - _centro._x, 2) + pow(p._y - _centro._y, 2)) <= _radio;
}
