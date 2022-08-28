#include <iostream>
#include <fstream> // ifstream

using namespace std;

void leerFlujo(istream& flujo){
   char caracter;
   
   while(flujo.get(caracter))
      cout<<caracter;
   //cout<<endl;
}
int main(int argc, char* argv[]){
   int dato;

   if(argc==1){
      leerFlujo(cin);
   }
   else{
      ifstream flujo(argv[1]);
      if (!flujo) {
         cerr << "Error: Fichero " << argv[1] << " no válido." << endl;
         return 1;
      }
      leerFlujo(flujo);
   }   
}
