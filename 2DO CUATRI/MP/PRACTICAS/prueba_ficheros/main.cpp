/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: davidms_83
 *
 * Created on 16 de marzo de 2020, 16:14
 */

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/*
 * 
 */
int main() {
    int i; double d; string s;
    ifstream fichero, fichero2, ficheros[100]; //input file stream
    ofstream salida; //output file stream
    
    fichero.open("data/datos.txt");
    if(fichero){
        fichero >> i;
        fichero >> d;
        fichero >> s;
        if(fichero){
            cout << "Has leido esto: "<<i<<" "<< d << " " << s << endl;
            salida.open("data/out.txt");
            salida << "Has leido esto: "<<i<<" "<< d << " " << s << endl;
            salida.close();
        }else
            cerr << "Error de lectura en el fichero" << endl;
        fichero.close(); //opcional porque c++ tiene destructor
    }else
        cerr << "Error abriendo el fichero datos.txt" << endl;
    
    return 0;
}

