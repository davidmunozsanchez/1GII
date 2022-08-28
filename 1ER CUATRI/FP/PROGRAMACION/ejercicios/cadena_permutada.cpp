/* Comparar si dos cadenas permutadas son iguales
*/

#include <iostream>
#include <cstring>

using namespace std;

int main(){
	
	char cadena1[10] = "ABCD";
	char cadena2[10] = "CDAB";
	int longitud;;
	bool iguales = false;
	
	longitud = strlen(cadena1);
	

	
    for (int i=0; i<longitud && !iguales; i++){
    	iguales = true;
        for (int j=0; j<longitud && iguales; j++)
            if (cadena1[j] != cadena2[(j+i)%longitud])
                iguales = false;
        }
    
    
    cout << iguales;
	
}
