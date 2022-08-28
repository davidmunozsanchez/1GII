#include <iostream>
#include <fstream> // ifstream
#include "VectorDinamicoChar.h"

using namespace std;

int main(int argc, char* argv[]) { //se puede poner char** argv, array de punteros a char
    char* arraychar;
    int nCaracteres;

    inicializar(arraychar, nCaracteres);
    if (argc == 1)leer(cin, arraychar, nCaracteres);
    else {
        ifstream flujo;
        flujo.open(argv[1]);
        if (!flujo) {
            cerr << "Error: Fichero " << argv[1] << " no valido." << endl;
            return 1;
        }
        leer(flujo, arraychar, nCaracteres);
        flujo.close();
    }
    mostrar(cout, arraychar, nCaracteres);
    liberar(arraychar, nCaracteres);
    return 0;
}
