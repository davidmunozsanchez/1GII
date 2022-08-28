#include <iostream>

using namespace std;

int main(){
    int v[5];
    int * p = v;

    cout << "Introduce 5 valores para el array: ";
    for (int i=0; i < 5; i++){
        cin >> *p;

        p++;
    }

    p = &(v[0]);

    for(int i = 0; i < 5; i++){
        if(*p < 0)
            *p = -*p;

        p++;
    }
    p = &(v[0]);
    for(int i=0; i<5; i++){
        cout << *p;

        p++;
    }

    /* EQUIVALENTEMENTE
    for (int i = 0; i < 1000; i++){
        if(*(v+i)<0)
            *(v+i) = -*(v+i);
    }*/
}