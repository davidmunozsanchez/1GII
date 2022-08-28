#include <iostream>

using namespace std;

void elevarAlCuadrado(int* &pEntero){
    int cuadrado = *pEntero;
    cuadrado *= cuadrado;
    *pEntero = cuadrado;
    pEntero = 0;  //o pEntero = 0;
}
int main(){
    int a = 6;
    int *q;
    q = &a;
    elevarAlCuadrado(q);
    cout << a <<" "<< q;
}