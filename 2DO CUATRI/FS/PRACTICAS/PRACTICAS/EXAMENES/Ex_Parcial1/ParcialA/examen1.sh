#!/bin/bash

directorio_trabajo=`pwd`
declare -i numero_argumentos=$#

if ! (( $numero_argumentos == 1 )) && ! [ $numero_argumentos == 2 ] ; 
        then echo "Introduce 1, 2 o 3 argumentos, según lo que quieras hacer"
        
elif [ $numero_argumentos == 1 ] ;
        then ls -d *$1*

elif [ $numero_argumentos == 2 ] ;
        then if [ -f $1 ] ; 
         then if [ -f $2 ]; 
                    then  cat $1 >> $2
                elif [ -d $2 ] ;
                    then cp $1 $2
                else
                    cat $1 > $2;fi
        else
            echo "Tu primer archivo no existe";fi;fi


                

                
    
    
