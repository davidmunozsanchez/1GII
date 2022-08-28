ayuda="""./examen1.sh --p fichero_destino: concatena los contenidos de los ficheros planos del directorio de trabajo en el fichero_destino en el orden que aparecen, ó
./examen1.sh --p directorio_destino (debe existir previamente): copia los ficheros planos del directorio en el directorio_destino.
./examen1.sh --h muestra esta ayuda en pantalla
./examen1.sh --u (sin argumentos) muestra el número y el estado de los procesos del usuario"""

if [ $# -eq 1 ]
then
	if [ "$1" == "--u" ]
	then
		# Cuando hay un solo argumento y es --u, enseño los procesos incluyendo la información
		# sobre su estado, y el número de procesos que hay.
		procesos=$(ps -u $USER -o pid,cmd,stat,)
		n=$(echo "$procesos" | wc -l)
		n=$((n-1)) # le resto 1 porque la primera linea de ps no es un proceso
		echo "$procesos"
		echo "Hay un total de $n procesos abiertos."
	else
		# En otro caso (incluyendo --h) se enseña la ayuda.
		echo "$ayuda"	
	fi
elif [ $# -eq 2 ]
then
	if [ "$1" == "--p" ]
	then
		archivos=$(ls)
		if [ -d $2 ]
		then
			# Si hay dos argumentos, el primero es --p y el segundo es un directorio, se copian todos los
			# ficheros planos del directorio de trabajo en el directorio de destino.
			for archivo in $archivos
			do
				if [ -f $archivo ]
				then
					cp $archivo $2
				fi
			done
		else
			# Si el segundo argumento no es un directorio, entonces es el fichero de destino en el que se
			# concatenarán todos los archivos planos del directorio de trabajo.
			for archivo in $archivos
			do
				if [ -f $archivo ]
				then
					cat $archivo >> $2
				fi
			done
		fi
	else
		echo "$ayuda"
	fi
else
	echo "$ayuda"
fi
