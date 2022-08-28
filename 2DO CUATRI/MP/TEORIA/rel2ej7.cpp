#include <iostream>

using namespace std;

int ComparaCadenas(char cad1[], char cad2[]){
    int tam1;
    int tam2;
    char *p1 = cad1;
    char *p2 = cad2;
    int devolver;

    while (*p1 != '\0'){
        tam1 += 1;
        p1++;
    }

    while (*p2 != '\0'){
        tam2 += 1;
        p2++;
    }
    
    if (tam1 < tam2)
        devolver = -1;

    if (tam1 == tam2)
        devolver = 0;

    if (tam1 > tam2)
        devolver = 1;    

    return devolver;
}

void insertaCadena(char &destino[], char origen[], int p){
    char *p1 = destino;
    char *p2 = origen;

}
int main(){

}