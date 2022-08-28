#include <iostream>

using namespace std;

struct Celda{
    int d;
    int *p1, *p2;
    int *p3;
};

int main(){
    Celda a,b,c,d;
    int hola = 1;
    a.d = b.d = c.d = d.d = 0;
    
    c.p3 = &hola;
    a.p1 = &c;
    a.p2 = a.p1 -> p3;

    cout << a.p1;
}