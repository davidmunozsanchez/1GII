#include<iostream>
#include<cstring>

using namespace std;

int main(){
    const int MAXIMO = 100;
    char cadena[MAXIMO];
    char login[MAXIMO];
    
    int max_car;
    int contador_car = 0;
    int posicion_es = 0;
    int longitud;
    
    cout << "\nIntroduce nombre (MAX " << MAXIMO << " caracteres): \n";
    cin.getline(cadena, MAXIMO);
    
    longitud = strlen(cadena);
    
	cout << "Introduce un numero entero positivo: ";
    cin >> max_car;
    
    for ( int i=0; i<longitud; i++ ){
        if ( cadena[i] == ' ' )
            contador_car = 0;
        else if ( contador_car < max_car){
            login[posicion_es] = tolower(cadena[i]);
            posicion_es++;
            contador_car++;
        }
    }
    
    login[posicion_es] = '\0';
    
    cout << "\nLogin: " << login << "\n";
}
