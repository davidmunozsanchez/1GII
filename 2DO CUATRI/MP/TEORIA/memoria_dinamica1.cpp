#include <iostream>
#include <string>

using namespace std;

int main(){
    int *p; //Puntero a void sirve también void *p;
    p = new int;  //Mismos tipos en este caso int

    //SUPONEMOS SIEMPRE QUE HAY SUFICIENTE MEMORIA

    *p = 10;

    delete p; //Aquí liberamos la memoria

    //Con struct es prácticamente lo mismo
}