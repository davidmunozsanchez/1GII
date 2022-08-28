//Programa que calcula la moda de caracteres en un vector de caracteres
#include <iostream>
using namespace std;

//Struct que almacena un caracter y la frecuencia con la que aparece
struct Moda {
  char caracter;
  int frecuencia;
};

Moda funcion() 
{
  Moda E;
  char cadena[50];
  E.frecuencia = 0;
  char Caracter;
  int posibleModa = 0;
  int modaMax = 0;
  bool leyendo = true;

  cout << "Introduce la cadena: ";
  cin.getline(cadena, 50);

  for(int i = 0; i < 50; i++){
    if(cadena[i] == '\0')
      leyendo = false;
      for(int j = 0; j < 50; j++)
        if(cadena[i] == cadena[j] && leyendo)
          posibleModa++;
    if(posibleModa > modaMax && leyendo){
      Caracter = cadena[i];
      modaMax = posibleModa;
    }
    posibleModa = 0;
  }
  
  E.frecuencia = modaMax;
  E.caracter = Caracter;
  return E;
}

int main() {
  Moda moda;
  moda = funcion();
  cout << "Caracter: " << moda.caracter;
  cout << endl << "Frecuencia: " << moda.frecuencia;
}

