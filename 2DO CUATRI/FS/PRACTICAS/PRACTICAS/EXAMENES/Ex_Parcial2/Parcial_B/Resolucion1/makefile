CC=g++
CPPFLAGS=-Wall -g

EXECUTABLE=examen2
EXECUTABLE_DEBUG=examen2_depurable
SOURCES=pr.cpp
OBJECTS=$(SOURCES:.cpp=.o)

LIBRERIA=mates.a
LIBRERIA_SOURCES=complex.cpp geom.cpp vector.cpp
LIBRERIA_OBJECTS=$(LIBRERIA_SOURCES:.cpp=.o)
LIBRERIA_HEADERS=$(LIBRERIA_SOURCES:.cpp=.h)


all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) $(LIBRERIA)
	$(CC) $(CPPFLAGS) -o $@ $^

$(OBJECTS): $(SOURCES)
	$(CC) $(CPPFLAGS) -c $^

$(LIBRERIA): $(LIBRERIA_OBJECTS)
	ar -rvs $@ $^

$(LIBRERIA_OBJECTS): $(LIBRERIA_SOURCES) $(LIBRERIA_HEADERS)
	$(CC) $(CPPFLAGS) -c $^

$(EXECUTABLE_DEBUG): $(OBJECTS) $(LIBRERIA)
	$(CC) $(CPPFLAGS) -o $@ $^

limpiar:
	rm *.o *.a *.gch $(EXECUTABLE) $(EXECUTABLE_DEBUG)

instalar: $(EXECUTABLE)
	mkdir bin lib Fuentes
	mv $(EXECUTABLE) bin
	mv $(LIBRERIA) lib
	mv *.cpp *.h Fuentes
	rm *.o *.gch

desinstalar:
	mv bin/* lib/* Fuentes/* .
	rmdir bin lib Fuentes
	rm $(EXECUTABLE) $(LIBRERIA)

depurar: $(EXECUTABLE_DEBUG)
	gdb -x examen3.gdb $(EXECUTABLE_DEBUG)
