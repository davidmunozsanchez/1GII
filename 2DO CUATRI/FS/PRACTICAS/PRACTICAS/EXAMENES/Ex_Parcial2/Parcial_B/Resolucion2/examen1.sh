#!/bin/bash

ayuda0="ERROR: PARAMETROS NO INTRODUCIDOS CORRECTAMENTE. MUESTRA DE AYUDA\n"
ayuda1="./examen1.sh --p (fichero_destino). Concatena los contenidos de los ficheros planos del directorio de trabajo en el fichero_destino introducido ó\n"
ayuda2="./examen1.sh --p (directorio_destino). Copia todos los archivos planos de texto del directorio actual a la carpeta especificada\n"
ayuda3="./examen1.sh --h . Muestra esta ayuda en pantalla\n"
ayuda4="./examen1.sh --u . Muestra el numero y estado de los procesos del usuario\n"



case $1 in
	"--p")	if ! test -d $2 ; then

		for archivo in $(ls)
		do
		   if [ -f $archivo ] && [ $archivo != "$2" ] && [ $archivo != "examen1.sh" ]
		   then
		      cat $archivo >> $2
	           fi
		done ;

		elif test -d $2 ; then

		for archivo in $(ls)
		do
		    if [ -f $archivo ] && [ $archivo != "examen1.sh" ]
		    then
		        cp $archivo $2
		    fi
		done
		fi
		 ;;
	"--h") echo -e $ayuda0 $ayuda1 $ayuda2 $ayuda3 $ayuda4;;
	"--u")  lista=$(ps -u $USER -o pid,cmd,stat)
		numero=$(echo "$lista" | wc -l)
		numero=$((numero - 1))
		echo "$lista" && echo -e "\n\nNUMERO DE PROCESOS: $numero";;
	*) echo -e $ayuda0 $ayuda1 $ayuda2 $ayuda3 $ayuda4 ;;
esac
