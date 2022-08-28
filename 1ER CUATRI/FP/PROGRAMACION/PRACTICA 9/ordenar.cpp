//  ordenar.cpp

#include <iostream>

using namespace std;

//Progama principal
int main(){
    const int LONGITUD = 20;

    int longitud = 0, longitud_final = 0;
    int i = 0, j = 0, k = 0;

    int vector1[LONGITUD] = {0} , vector2[LONGITUD] = {0};
    int vector_final[LONGITUD] = {0};

    cout << "\nIntroduce la longitud del vector: " << endl;
    cin >> longitud;

    longitud_final = 2 * longitud;


    //Introduccion de datos
    cout << "\nIntroduzca los elementos del primer vector: " << endl;
    for(int a = 0; a < longitud; a++)
        cin >> vector1[a];

    cout << "\nIntroduzca los elementos del segundo vector: " << endl;
    for(int b = 0; b < longitud; b++)
        cin >> vector2[b];

    //Ordenacion del vector
    while(j < longitud || i < longitud){
        if(i < longitud && j < longitud){
            if(vector1[i] < vector2[j]){
                vector_final[k] = vector1[i];
                i++;
            }
            else{
                vector_final[k] = vector2[j];
                j++;
            }
        }
        else {
            if (i < longitud){
                vector_final[k] = vector1[i];
                i++;
            }
            else{
            vector_final[k] = vector2[j];
            j++;
            }
        }
        k++;
    }


    //Muestra el vector ordenado
    cout << "\nEl vector final ordenado de forma ascendente es: " ;
    for(int c=0; c < longitud_final; c++)
        cout << vector_final[c];
}
