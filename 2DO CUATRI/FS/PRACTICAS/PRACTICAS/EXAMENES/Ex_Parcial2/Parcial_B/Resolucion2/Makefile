#MAKEFILE: ARCHIVO MAKEFILE PARA examen2
#USO:	make -f makefile
#	make -f makefile all	      >> construye todo el programa
#	make -f makefile library      >> construye librería necesaria
#	make -f makefile instalar     >> instala en escritorio
#	make -f makefile desinstalar  >> desinstala el ejecutable
#	make -f makefile depurar      >> permite depuracion de programa
#	make -f makefile limpiar

#DECLARACIÓN DE VARIABLES PARA EL USO DE MAKEFILE

#1. CC: Asigna el compilador a utilizar.

CC=g++

#2. CPPFLAGS: Asigna rutinas de compilacion así como el directorio
#donde se encuentran las librerias necesarias

CPPFLAGS=-g -Wall $(CABECERA_DIR)

#3. CABECERA_DIR: Asigna el directorio de la libreria a buscar

DIRECTORIO_CABECERAS=cabeceras
CABECERA_DIR=-I./

#4. INSTALL_DIR: Asigna la dirección donde instalar el programa

INSTALL_DIR=./bin

#5. EXECUTABLE: Asigna nombre de ejecutable
EXECUTABLE=examen2

#6. SOURCE_FILES: Asigna una lista de dependencias del programa final

SOURCE_FILES=complex.cpp geom.cpp pr.cpp vector.cpp

#7. LIBRARY_FILES: Archivos necesarios para la creación de una librería

LIBRARY_FILES=complex.o vector.o geom.o
LIBRARY=mates.a
LIBRARY_OBJS=$(LIBRARY_FILES:.cpp=.h)

#8. OBJECT_FILES: Asigna los correspondientes archivos objeto de SOURCE_FILES

OBJECT_FILES=$(SOURCE_FILES:.cpp=.o)

#============================================================================

#CONSTRUCCIÓN DEL MAKEFILE

#ALL: CONSTRUYE TODO EL PROGRAMA (DEPENDE DE: $(EXECUTABLE), $(OBJECT_FILES))
#[NOTA: NORMALMENTE EL OBJETIVO "ALL" PUEDE DEPENDER DE LIBRERÍAS]

all: $(OBJECT_FILES) $(EXECUTABLE) $(LIBRARY)

#EXECUTABLE: CONSTRUYE EL CORRESPONDIENTE EJECUTABLE (DEPENDE DE $(OBJECT_FILES))
# $^ : REPRESENTA TODAS LAS DEPENDENCIAS SEPARADAS EN BLANCO
# $@ : NOMBRE DEL 0BJETIVO EN LA REGLA EN LA QUE NOS ENCONTRAMOS

$(EXECUTABLE): $(OBJECT_FILES) $(LIBRARY)
	$(CC) $(CABECERA_DIR) $^ -o $(EXECUTABLE) $(LIBRARY)

#.o: COMPILA TODOS LOS FICHEROS DE CÓDIGO FUENTE A OBJETO (DEPENDE DE LIBRERIAS)
#[EN CPPFLAGS YA SE INDICA A MAKE CÓMO DEBE ENLAZAR LAS LIBRERÍAS]
# $< : MUESTRA PRIMERA DEPENDENCIA NECESARIA 
#	[ archivo.o: dependencia.cpp ]
#	[ DEVUELVE: dependencia.cpp ]

complex.o: complex.cpp complex.h
	$(CC) -c $(CPPFLAGS) $<

geom.o: geom.cpp geom.h
	$(CC) -c $(CPPFLAGS) $<

vector.o: vector.cpp vector.h
	$(CC) -c $(CPPFLAGS) $<

pr.o: pr.cpp $(LIBRARY_OBJS)
	$(CC) -c $(CPPFLAGS) $<

#$(LIBRARY): GENERA LA LIBRERIA PEDIDA

$(LIBRARY): 
	ar -rvs $@ $^

library: $(LIBRARY_FILES) 
	ar -rvs $(LIBRARY) $(LIBRARY_FILES)
	rm *.o

#install_dir: INSTALA EL EJECTUABLE EN EL DIRECTORIO ASIGNADO

directorios:
	mkdir -p bin lib Fuentes

instalar: $(EXECUTABLE) directorios
	mv $(EXECUTABLE) $(INSTALL_DIR)
	mv $(LIBRARY) ./lib
	mv *.cpp *.h ./Fuentes
	rm *.a *.o

#desinstalar: DESINSTALA EL PROGRAMA EJECUTABLE PREVIAMENTE INSTALADO
#EN EL DIRECTORIO ASIGNADO

desinstalar: ./bin/$(EXECUTABLE)
	mv ./Fuentes/* ./ && rmdir ./Fuentes/
	rm ./lib/* && rmdir ./lib/
	rm ./bin/* && rmdir ./bin/

#debug: PROPORCIONA INFORMACION PARA DEPURAR EL OBJETO EJECUTABLE

debug: $(EXECUTABLE_DEBUG) $(LIBRARY)

$(EXECUTABLE_DEBUG): $(OBJECT_FILES) $(LIBRARY)
	$(CC) -g $(LIB_DIR) -o $@ $(OBJECT_FILES) $(LIBRARY)

#limpiar: OBJETIVO PARA ELIMINAR TODOS LOS CÓDIGO OBJETO GENERADOS EN EL
#PROCESO DE COMPILACION

limpiar:
	rm *.o $(EXECUTABLE) *.a
