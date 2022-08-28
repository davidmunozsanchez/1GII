CC = g++
CFLAGS = -Wall -g
INCLUDES = -I./
LIBRARIES = -L./

all: examen2

examen2: mates.a
	$(CC) $(CFLAGS) $(LIBRARIES) mates.a -o examen2

mates.a: complex.o dist.o geom.o pr.o vector.o
	ar -rvs mates.a complex.o dist.o geom.o pr.o vector.o

complex.o: complex.cpp complex.h
	$(CC) $(CFLAGS) $(INCLUDES) -c complex.cpp

dist.o: dist.cpp dist.h
	$(CC) $(CFLAGS) $(INCLUDES) -c dist.cpp

geom.o: geom.cpp geom.h
	$(CC) $(CFLAGS) $(INCLUDES) -c geom.cpp

vector.o: vector.cpp vector.h
	$(CC) $(CFLAGS) $(INCLUDES) -c vector.cpp

pr.o: pr.cpp complex.h geom.h vector.h dist.h
	$(CC) $(CFLAGS) $(INCLUDES) -c pr.cpp

limpiar:
	rm *.o *.a examen2

instalar: examen2
	mkdir -p ./bin ./SOURCE ./CABECERAS ./LIB
	
	mv examen2 ./bin
	mv *.cpp ./SOURCE
	mv *.h ./CABECERAS
	mv mates.a ./LIB
	rm *.*

desinstalar: ./CABECERAS	
	mv ./CABECERAS/* ./
	mv ./SOURCE/* ./

	rmdir CABECERAS
	rmdir SOURCE
	rm -r bin LIB		

depurar: all
	gdb -x examen3.gdb examen2


