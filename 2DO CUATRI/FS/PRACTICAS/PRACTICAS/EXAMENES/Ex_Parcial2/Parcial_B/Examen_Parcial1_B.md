## EXAMEN PARCIAL 2: PRUEBA B

*Examen del Año 2018~2019. Temas: Módulo 1 y Módulo 2*

#### 1. (3 puntos) Construya un guión (script) llamado *examen1.sh* en bash con el siguiente funcionamiento:

* a) *./examen1.sh --p fichero_destino* : Concatena los contenidos de los ficheros planos del directorio de trabajo en el *fichero_destino* en el orden que aparecen.
* b) *./examen1.sh --p directorio_destino (debe existir previamente)* : Copia los ficheros planos del directorio en el *directorio_destino*.
* c) *./examen1.sh --h* : Muestra esta ayuda en pantalla.
* d) *./examen1.sh --u* (sin argumentos). Muestra el número y el estado de los procesos del usuario.

Si el guión (script) se ejecuta sin argumentos o con un número erróneo de argumentos o un tipo de argumento no esperado (si se esperan archivos y son directorios o viceversa) dependiendo de las opciones seleccionadas, el script mostrará la ayuda.

#### 2. (5 puntos) Escriba un archivo llamado *Makefile* para compilar con la orden make los archivos (.cpp) y (.h) del directorio que se le ha facilitado [ARCHIVOS_EXAMEN2.ZIP] y además crear una librería con el nombre *mates.a*, formada con las funciones usadas. El directorio dado deberá ser tomado como el directorio de trabajo. El nombre del programa generado deberá llamarse *examen2*. El archivo *Makefile* debe cumplir las siguientes reglas:

* a) Cuando se invoque la orden *make* deberá generar los archivos objetos, la librería y el ejecutable *examen2* en el directorio de trabajo.
* b) Deberá disponer de una regla llamada *limpiar* que borre los archivos objetos, librerías y el ejecutable *examen2*.
* c) Disponer de la regla *instalar* que deberá realizar las siguientes acciones:
  * Generar el ejecutable *examen2*
  * Crear los directorios *./bin, ./lib y ./Fuentes* si no existen
  * Mover el ejecutable *examen2* al directorio *./bin*, la librería *mates.a* en *./lib*, todos los archivos (.cpp) y (.h) al directorio *./Fuentes*, el resto de archivos deben ser borrados.
* d) También deberá disponer de la regla *desinstalar* condicionada a que la regla *instalar* haya sido invocada con anterioridad. La regla *desinstalar* deberá restituir el directorio de trabajo a la situación inicial. En concreto, en el directorio de trabajo sólo deberán aparecer los archivos (.cpp) y (.h) que han sido proporcionados inicialmente, junto con el archivo *makefile* realizado, borrando el resto de archivos o directorios que puedan existir.

#### 3. (2 puntos) Modifique el fichero *Makefile* para depurar el programa compilado en el ejercicio anterior. Realice un script de gdb llamado *examen3.gdb* y que realice las siguientes actividades de depuración al programa del ejercicio anterior:

* a) Defina un punto de ruptura en la función *vsum(vector, vector)*.
* b) Defina un punto de ruptura condicional en la función *garea* que detendrá la ejecución cuando el círculo tenga radio mayor o igual a 10.
* c) Realice 5 iteraciones del bucle y muestre la variable *i* en todas las iteraciones.