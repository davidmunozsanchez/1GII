#include <iostream>
#include <fstream>
#include "VectorSD.h"

using namespace std;

int main(int argc, char* argv[]){
    VectorSD v;
    if (argc == 1){
        v.leer(cin);
   
    }
    else{
        ifstream flujo(argv[1]);
        if(!flujo){
            cerr << "Error: Fichero " << argv[1] << " no valido." << endl;
            return 1;
        }
        v.leer(flujo);
    }
    v.mostrar(cout);
    v.liberar();
}