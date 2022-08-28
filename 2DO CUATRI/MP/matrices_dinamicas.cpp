//Ejemplo 1
//Creacion
int *m;
int nfil, ncol;
m =new int[nfil*ncol];

//Acceso
int a;
a = m[f*ncol+c];

//Destruccion
delete[] m;

//Ejemplo 2
//Creacion
int **m;
int nfil, ncol;
m =new int*[nfil];
for(int i=0; i<nfil;++i)
    m[i] = new int[ncol];

//Acceso
int a;
a = m[f][c];

//Destruccion
for(int i=0;i<nfil;++i)
    delete[] m[i];

delete[] m;

//Ejemplo 3
//Creacion
int **m;
int nfil, ncol;
m =new int*[nfil];
m[0] =new int[nfil*ncol];

for(int i=1; i<nfil;++i)
    m[i] = m[i-1]+ncol;

//Acceso
int a;
a = m[f][c];

//Destruccion
delete[] m[0];
delete[] m;