#!/bin/bash

mostrarAyuda(){
	echo "Texto de ayuda:"
	echo "./examen1-sh --c argumentos, donde argumentos puede ser: i)ficheros_fuentes fichero destino. Copia los ficheros fuentes en el destino. ii)directorio(si no existe se crea). Copia los ficheros planos del directorio de trabajo en el directorio de destino"
	echo "./examen1.sh --h muestra esta ayuda"
	echo "./examen1.sh --sh argumento muestra los usuarios que usan el shell argumento, que puede ser bash, sh o csh"
	
}

#Depuro la entrada de datos
if (($# == 0))
then
	echo "No ha introducido ningun argumento"
	mostrarAyuda

else
	case $1 in
	--h)
		mostrarAyuda
		;;
	--c)		
		if(($# == 2))	#Se quiere usar la opcion de directorio
		then
			mkdir -p $2	#Creo el directorio si no existe
			for archivo in $(ls)	#Compruebo que los archivos sean planos
			do
				if test -f $archivo
				then
					cp $archivo $2
				fi
			done
		else
			for(( i=1; i < $#; i++ ))
			
			do
				cat $i>>$#
			done
		fi
		;;
	--sh)
		case $2 in
		csh)
			echo "Usuarios que usan csh: "
			for x in $(cat /etc/passwd | egrep "/csh")
			do
				echo $x
			done		
		;;
		sh)
			echo "Usuarios que usan sh: "			
			for x in $(cat /etc/passwd | egrep "/sh")
			do
				usuario=$(echo $x | cut -d':' -f1)
				echo $usuario
			done
		;;
		bash)
			echo "Usuarios que usan bash: "
			for x in $(cat /etc/passwd | egrep "/bash")
			do
				usuario=$(echo $x | cut -d':' -f1)
				echo $usuario
			done	
		;;
		*)
			echo "Tipo de Shell no valido"
			mostrarAyuda
		;;
		esac
	;;
	*)
		echo "Argumentos invalidos"
		mostrarAyuda
	;;
	esac
fi

